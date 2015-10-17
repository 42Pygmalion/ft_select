#include "ft_select.h"

void				error_select(int error)
{
	struct termios		term;

	if (error == 0)
		ft_putendl_fd("Needs at least one argument.", 2);
	if (error == 1)
		ft_putendl_fd("Incomplete environment.", 2);
	if (error == 7)
		ft_putendl_fd("Fine.", 1);
	tcgetattr(0, &term);
	term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &term);
	exit(-1);
}

struct termios		ft_init(void)
{
	struct termios	term;

	tgetent(NULL, getenv("TERM")) != ERR ? tcgetattr(0, &term) : error_select(1);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	return (term);
}

void				ft_display(t_select *select)
{
	t_select	*tmp;

	tmp = select;
	while (1)
	{
		ft_putendl(select->name);
		if (select->next != tmp && select->next)
			select = select->next;
		else
			break ;
	}
}

void				ft_select(t_select *select, struct termios term)
{
	tputs(tgetstr("cl", NULL), 0, ft_putcmd);
	ft_display(select);
	input_needed(select);
	(void)select;
	(void)term;
}

int					main(int ac, char **av, char **env)
{
	struct termios	term;
	t_select		*select;
	int 			i;

	i = 1;
	select = NULL;
	ac > 1 ? term = ft_init() : error_select(0);
	while (av[i])
		select = add_list(select, av[i++]);
	ft_select(select, term);
	error_select(7);
	(void)env;
    return (0);
}