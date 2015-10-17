#include "ft_select.h"

void	end(t_select *select)
{
	t_select	*tmp;

	tmp = select;
	tputs(tgetstr("cl", NULL), 0, ft_putcmd);
	while (1)
	{
		if (select->highlight)
			ft_putendl(select->name);
		if (select->next && select->next != tmp)
			select = select->next;
		else
			break ;
	}
	error_select(7);
}

void	input_needed(t_select *select)
{
	int 	*key;

	key = (int *)malloc(sizeof(int));
	while (1)
	{
		*key = 0;
		read(0, key, 3);
		if (*key == ESCAPE)
			error_select(7);
		else if (*key == SPACE || *key == UP || *key == DOWN || *key == LEFT || *key == RIGHT)
			select = move(select, *key);
		else if (*key == RETURN)
			end(select);
		else if (*key == BACK || *key == DEL)
			select = del(select);
		else if (*key == CMD_A)
			select = highlight(select);
	}
}