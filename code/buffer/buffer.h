//
// Created by dusensen on 2022/8/20.
//

#ifndef WEBSERVER_BUFFER_H
#define WEBSERVER_BUFFER_H

#include <cstring>   //perror
#include <iostream>
#include <unistd.h>  // write
#include <sys/uio.h> //readv
#include <vector> //readv
#include <atomic>
#include <assert.h>


class Buffer {
    Buffer(int initBuffSize = 1024);

    ~Buffer() = default;

    size_t WriteableBytes() const;

    size_t ReadableBytes() const;

    size_t PrependableBytes() const;

    const char *Peek() const;

    void EnsureWriteable(size_t len);

    void HashWriten(size_t len);

    void Retrieve(size_t len);

    void RetrieveUntil(const char *end);

    void RetrieveAll();

    std::string
};


#endif //WEBSERVER_BUFFER_H
