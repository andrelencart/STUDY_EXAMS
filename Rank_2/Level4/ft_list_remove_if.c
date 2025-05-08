#include <stdlib.h>
#include <stdio.h>

#include <string.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *temp = *begin_list;
	t_list *delete;


	while (temp)
	{
		if (cmp(temp->data, data_ref) == 0)
		{
			if (temp == *begin_list)
				*begin_list = temp->next;
			else
				delete->next = temp->next;
			delete = temp;
			temp = temp->next;
			free(delete);
		}
		else
		{
			delete = temp;
			temp = temp->next;
		}
	}
}

// Function to create a new node
t_list *create_node(void *data)
{
    t_list *new = malloc(sizeof(t_list));
    if (!new)
        return NULL;
    new->data = data;
    new->next = NULL;
    return new;
}

// Function to print the list
void print_list(t_list *list)
{
    while (list)
    {
        printf("%s -> ", (char *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

// Function to free the list
void free_list(t_list *list)
{
    t_list *temp;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
}

// Comparison function (strcmp-like)
int cmp(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

// Main function to test ft_list_remove_if
int main()
{
    // Creating a linked list: ["Hello"] -> ["World"] -> ["Hello"] -> ["42"] -> NULL
    t_list *list = create_node("\0");
    list->next = create_node("World");
    list->next->next = create_node("Hello");
    list->next->next->next = create_node("42");

    printf("Before removal:\n");
    print_list(list);

    // Removing "Hello" from the list
    ft_list_remove_if(&list, "Hello", cmp);

    printf("After removal:\n");
    print_list(list);

    // Free remaining nodes
    free_list(list);

    return 0;
}