#include <stdlib.h>
#include "ft_list.h"

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp = *begin_list;

	while (temp)
	{
		if (cmp(temp->data, data_ref) == 0)
			free(temp);
		temp = temp->next;
	}
}