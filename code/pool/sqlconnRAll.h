//
// Created by dusensen on 2022/8/20.
//

#ifndef WEBSERVER_SQLCONNRALL_H
#define WEBSERVER_SQLCONNRALL_H


#include "sqlconnpool.h"

class SqlConnRAII {

public:
    SqlConnRAII(MYSQL **sql, SqlConnPool *connpool) {
        assert(connpool);
        *sql = connpool->GetConn();
        sql_ = *sql;
        connpool_ = connpool;
    }

private:
    MYSQL *sql_;
    SqlConnPool *connpool_;
};


#endif //WEBSERVER_SQLCONNRALL_H
