#include "ft_select.h"

t_select	*new_list(char *arg, void *prev)
{
	t_select *new;

	new = (t_select *)malloc(sizeof(t_select));
	if (new == NULL)
		return (NULL);
	new->name = ft_strdup(arg);
	new->next = NULL;
	new->highlight = 0;
	new->underlined = 0;
	new->prev = prev;
	return (new);
}

t_select	*add_list(t_select *lst, char *arg)
{
	t_select *tmp;

	if (lst == NULL)
		return (new_list(arg, NULL));
	tmp = lst;
	while (tmp->next && tmp->next != lst)
		tmp = tmp->next;
	tmp->next = new_list(arg, tmp);
	tmp->next->next = lst;
	tmp->next->next->prev = tmp->next;
	return (lst);
}