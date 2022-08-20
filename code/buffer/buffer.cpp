//
// Created by dusensen on 2022/8/20.
//

#include "buffer.h"

Buffer::Buffer(int initBuffSize) : buffer_(initBuffSize), readPos_(0), writePos_(0) {}

size_t Buffer::WriteableBytes() const {
    return 0;
}

size_t Buffer::ReadableBytes() const {
    return 0;
}

size_t Buffer::PrependableBytes() const {
    return 0;
}

const char *Buffer::Peek() const {
    return nullptr;
}

void Buffer::EnsureWriteable(size_t len) {

}

void Buffer::HashWriten(size_t len) {

}

void Buffer::Retrieve(size_t len) {

}

void Buffer::RetrieveUntil(const char *end) {

}

void Buffer::RetrieveAll() {

}

std::string Buffer::RetrieveAllToStr() {
    return std::__cxx11::string();
}

const char *Buffer::BeginWriteConst() const {
    return nullptr;
}

char *Buffer::BeginWrite() {
    return nullptr;
}

void Buffer::Append(const std::string &str) {

}

void Buffer::Append(const char *str, size_t len) {

}

void Buffer::Append(const void *data, size_t len) {

}

void Buffer::Append(const Buffer &buff) {

}

ssize_t Buffer::ReadFd(int fd, int *Errno) {
    return 0;
}

ssize_t Buffer::Write(int fd, int *Errno) {
    return 0;
}

char *Buffer::BeginPtr_() {
    return nullptr;
}

const char *Buffer::BeginPtr_() const {
    return nullptr;
}

void Buffer::MakeSpace_(size_t len) {

}
