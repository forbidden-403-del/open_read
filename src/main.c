#include "include/mstd.h"

void write_char(char ch) {
	sysWrite(1, &ch, 1);
}

void print(char *str) {
	while (*str) {
		write_char(*str);
		str++;
	}
}

void _start() {
	char    buf[BUF_SZ];
	int		fd;
	fd = sysOpen("data.txt", 0);
	if (fd != -1) {
		ssize_t num_read = sysRead(fd, buf, BUF_SZ - 1);
		while (num_read > 0) {
			buf[num_read] = '\0';
			print(buf);
			num_read = sysRead(fd, buf, BUF_SZ - 1);
		}
	} else {
		print("Error opening file");
		sysExit(-1);
	}
	sysClose(fd);
	sysExit(0);
}
