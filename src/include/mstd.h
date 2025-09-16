#ifndef __MSTD__
#define __MSTD__

#define SYSWRITE 1
#define SYSREAD 0
#define SYSOPEN 2
#define SYSCLOSE 3
#define SYSEXIT 60

#define BUF_SZ 1024

typedef __SIZE_TYPE__ size_t;
typedef long ssize_t;

void sysWrite(unsigned fd, const char *buf, size_t count);
void sysExit(int errcode);
ssize_t sysRead(unsigned fd, char *buf, size_t count);
int sysOpen(const char *pathname, int flags);
void sysClose(int fd);

#endif
