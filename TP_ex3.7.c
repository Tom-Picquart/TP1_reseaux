
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


void show_list_elements(link* list){
	link* element = list;
    while (element != NULL)
    {
        printf("adress: %p, value: %d\n",(void *)element,element->value);
        element = element->next;
	}
}

void add_first_element(link** list, int x){
	link* new_element= malloc(sizeof(link));
	new_element->value = x;
    new_element->next = *list;
    *list = new_element;
	}

int main(){
	link* list;	
	list = create_list(8);
	add_first_element(&list, 20);
	show_list_elements(list);
	return 0;
}

