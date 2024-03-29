#ifndef __WEBSERVER_H__
#define __WEBSERVER_H__

#include <unordered_map>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "epoller.h"
#include <iostream>

using namespace std;

class WebServer {
public:
    WebServer(
            int port, int trigMode, int timeoutMS, bool OptLinger,
            int sqlPort, const char *sqlUser, const char *sqlPwd,
            const char *dbName, int connPoolNum, int threadNum,
            bool openLog, int logLevel, int logQueSize);

    ~WebServer();

    void Start();

private:
    bool InitSocket_();

    void InitEventMode_(int trigMode);

    void AddClient_(int fd, sockaddr_in addr);

    void DealListen_();

    voi DealWrite(HttpConn *client);

    int port_;
    bool openLinger_;
    int timeoutMS_;
    bool isClose_;
    int listenFd_;
    char *srcDir_;

    uint32_t listenEvent_;
    uint32_t connEvent_;

    std::unique_ptr <HeapTimer> timer_;
    std::unique_ptr <ThreadPool> threadpool_;
    std::unique_ptr <Epoller> epoller_;
    std::unordered_map<int, HttpConn> users_;
};

#endif