#include "ft_select.h"

void				error_select(int error)
{
	struct termios		s_term;

	if (error == 0)
		ft_putendl_fd("Needs at least one argument.", 2);
	if (error == 1)
		ft_putendl_fd("Incomplete environment.", 2);
	if (error == 7)
		ft_putendl_fd("Fine.", 1);
	tcgetattr(0, &s_term);
	s_term.c_lflag = (ICANON | ECHO);
	tcsetattr(0, 0, &s_term);
	exit(-1);
}

struct termios		ft_init(void)
{
	struct termios	s_term;

	tgetent(NULL, getenv("TERM")) != ERR ? tcgetattr(0, &s_term) : error_select(1);
	s_term.c_lflag &= ~(ICANON | ECHO);
	s_term.c_cc[VMIN] = 1;
	s_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &s_term);
	return (s_term);
}

t_select			*init_list(t_select	*select, char *name)
{
	select =
}

int					main(int ac, char **av, char **env)
{
	struct termios	s_term;
	t_select		*select;
	int 			i;

	i = 1;
	ac > 1 ? s_term = ft_init() : error_select(0);
	while (av[i])
		select->next = init_list(select, av[i++]);
	error_select(7);
	(void)ac;
	(void)av;
	(void)env;
    return (0);
}