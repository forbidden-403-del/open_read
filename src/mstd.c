#include "include/mstd.h"

void sysExit(int errcode) {
	asm volatile (
		"syscall"
		:
		:"a"(SYSEXIT), "D"(errcode)
	);
}

void sysWrite(unsigned fd, const char *buf, size_t count) {
    asm (
        "syscall"
        :
        :"a"(SYSWRITE), "D"(fd), "S"(buf), "d"(count)
    );
}

ssize_t sysRead(unsigned fd, char *buf, size_t count) {
    ssize_t ret;
    asm (
        "syscall"
        :"=a"(ret)
        :"a"(SYSREAD), "D"(fd), "S"(buf), "d"(count)
    );
    return ret;
}

int sysOpen(const char *pathname, int flags) {
    long ret;
    asm (
        "syscall"
        : "=a"(ret)
        : "a"(SYSOPEN), "D"(pathname), "S"(flags), "d"(0)
    );
    return (int)ret;
}

void sysClose(int fd) {
    asm (
        "syscall"
        :
        :"a"(SYSCLOSE), "D"(fd)
    );
}