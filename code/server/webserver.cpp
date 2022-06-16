#include "webserver.h"

using namespace std;

WebServer::WebServer(int port, int trigMode, int timeoutMS, bool OptLinger,
                     int sqlPort, const char *sqlUser, const char *sqlPwd,
                     const char *dbName, int connPoolNum, int threadNum,
                     bool openLog, int logLevel, int logQueSize) : port_(port),
                                                                   openLinger_(OptLinger), timeoutMS_(timeoutMS), isClose_(false),
                                                                   timer_(new HeapTime()), threadpool_(new ThreadPool(threadNum)), epoller_(new Epoller())
{
    srcDir_ = getcwd(nullptr, 256);
    assert(srcDir_);
    strncat(srcDir_, "/resources/", 16);
}