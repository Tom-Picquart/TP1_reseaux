#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	char *addr;
	int fd;
	struct stat sb;
	
	
	if ((fd = open("./test.txt",O_RDWR))==-1){
		fprintf(stderr, "Cannot open /etc/ptmp. Try again later.\n");
		exit(1);}
	
	if (stat("./test.txt", &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
	printf("File size:                %lld bytes\n",(long long) sb.st_size);
	
	addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE,MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED){
        perror("mmap");}
        
	int i = 0;
	while (i < sb.st_size-(i+1))
	{
		char tmp = addr[i];
		addr[i] = addr[sb.st_size-(i+1)];
		addr[sb.st_size-(i+1)] = tmp;
		i++;
	}

	munmap(addr, sb.st_size);
	return 0;
}
