#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int data = 20;
int BSS = 0;

void show_stack(void)
{
    int stack = 13;
    printf("Stack: %p\n", (void *)&stack);
}


int main() {
	char* str = "hello world";
    int *heap = malloc(sizeof(int));
    if (heap == NULL) {
        perror("malloc");
        return 1;
    }
    *heap = 42; 
    
	void *mapped = mmap(NULL,4096,PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,-1,0);

    if (mapped == MAP_FAILED)
    {
        perror("mmap");
        free(heap);
        return 1;
    }
	
	printf("Data: %p \n",(void*)&data);
	printf("BSS: %p \n",(void*)&BSS);
	printf("str: %p \n",(void*)str);
	printf("heap: %p \n",(void*)heap);
	show_stack();
	printf("main: %p\n",(void*) main);
	printf("LibC: %p\n",(void*) printf);
	printf("mmap: %p \n", mapped);
	munmap(mapped, 4096);
	free(heap);
	printf("pid: %d \n", getpid());
	
	//in order to call pmap -X PID in another window
	printf("press enter to end process...\n");
	getchar();
    return 0;
}
