#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int value;
    struct link *next;
} link;


link *create_list(int n)
{
    link *list = NULL;
    link *new = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        new = malloc(sizeof(link));

        if (new == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        new->value = i;
        new->next = list;
        list = new;
    }

    return list;
}


int return_length(link* list){
	int l=0;
	link* element = list;
	while (element != NULL){
		element= element->next;
		l+=1;
		}
	return l;
	}



int main(){
	link* list;
	
	list = create_list(8);
	int i= return_length(list);
	printf("length: %d \n", i);
	return 0;
}
