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

public:
    explicit Buffer(int initBuffSize = 1024);

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

    std::string RetrieveAllToStr();

    const char *BeginWriteConst() const;

    char *BeginWrite();

    void Append(const std::string &str);

    void Append(const char *str, size_t len);

    void Append(const void *data, size_t len);

    void Append(const Buffer &buff);

    ssize_t ReadFd(int fd, int *Errno);

    ssize_t Write(int fd, int *Errno);

private:
    char *BeginPtr_();

    const char *BeginPtr_() const;

    void MakeSpace_(size_t len);

    std::vector<char> buffer_;

    std::atomic<std::size_t> readPos_;
    std::atomic<std::size_t> writePos_;
};


#endif //WEBSERVER_BUFFER_H
