typedef struct s_list
{
	struct s_list *next;
	void			*data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list *temp;
	int count = 0;

	temp = begin_list;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
