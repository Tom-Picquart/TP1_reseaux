

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


void show_list_elements(link* head){
	link* element = head;
    while (element != NULL)
    {
        printf("adress: %p, value: %d\n",(void *)element,element->value);
        element = element->next;
	}
}

link* append_lists(link* head1, link* head2){
	if (head1==NULL){
		return head2;
		}
	link* temp= head1;
	while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;  
	}

int main(){
	link* list;	
	list = create_list(8);
	link* list2 = create_list(4);
	link* new_list=append_lists(list, list2);
	show_list_elements(new_list);
	return 0;
}

