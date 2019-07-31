#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	int fd, f, tmp = 0;
	char string[] = {"Hello World!"};
	char buffer[14];
	if(f = open ("test.txt", O_CREAT) == -1) printf("open error!");

	#ifdef TEST
	f = open("text.txt", O_CREAT);
	#endif

	close(f);
	if (fd = open("test.txt", O_WRONLY) == -1) printf("write error!");

	#ifdef TEST
	fd = open("test.txt" , O_WRONLY);
	if(fd == -1) printf("Open error!");
	#endif

	write (fd, string, 12);
	close(fd);

	if(fd = open("test.txt", O_RDONLY) == -1) printf("read error!");

	for (int i = 1; i <= 12; i++){
		lseek(fd, -i, SEEK_END);
		read(fd, buffer, 1);
		printf("%c", buffer[0]);
	}
	printf("\n");
	return 0;
}
