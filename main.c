#include <unistd.h>
#include <fcntl.h>

#define BUF_SZ 1024

void write_char(char ch) {
	write(1, &ch, 1);
}

void write_str(char *str) {
	while (*str) {
		write_char(*str);
		str++;
	}
}

int main() {
	char    buf[BUF_SZ];
	int		fd;
	fd = open("data.txt", O_RDONLY);
	if (fd != -1) {
		ssize_t num_read = read(fd, buf, BUF_SZ - 1);
		while (num_read > 0) {
			buf[num_read] = '\0';
			write_str(buf);
			num_read = read(fd, buf, BUF_SZ - 1);
		}
	} else {
		write_str("Error opening file");
		return (-1);
	}
	close(fd);
	return 0;
}

