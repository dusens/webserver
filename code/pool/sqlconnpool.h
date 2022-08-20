//
// Created by dusensen on 2022/8/20.
//

#ifndef WEBSERVER_SQLCONNPOOL_H
#define WEBSERVER_SQLCONNPOOL_H

#include <mysql/mysql.h>
#include <string>
#include <queue>
#include <mutex>
#include <semaphore.h>
#include <thread>
#include <cassert>

class SqlConnPool {
public:
    static SqlConnPool *Instance();

    MYSQL *GetConn();

    void FreeConn(MYSQL *conn);

    int GetFreeConnCount();

    void Init(const char *host, int port, const char *user, const char *pwd,
              const char *dbName, int connSize);

    void ClosePool();

private:
    SqlConnPool();

    ~SqlConnPool();

    int MAX_CONN_;
    int userCount_;
    int freeCount_;

    std::queue<MYSQL *> connQue_;
    std::mutex mtx_;
    sem_t semId_;
};

#endif //WEBSERVER_SQLCONNPOOL_H
