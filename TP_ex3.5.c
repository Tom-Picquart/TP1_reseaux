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

void remove_last_element(link **list)
{
    if (*list == NULL)
        return;
    link *element = *list;
    link *previous = NULL;
    while (element->next != NULL)
    {
        previous = element;
        element = element->next;
    }

    if (previous == NULL)
    {
        *list = NULL;
    }
    else
    {
        previous->next = NULL;
    }

    free(element);
}

int main(){
	link* list;	
	list = create_list(8);
	remove_last_element(&list);
	show_list_elements(list);
	return 0;
}
