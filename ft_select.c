#include "ft_select.h"

void	error_select(int error)
{
	if (error == 0)
		ft_putendl_fd("Needs at least one argument.", 2);
	exit(-1);
}

struct termios		ft_init(int ac, char **av, char **env)
{
	struct termios	*s_term;

	s_term = (termios *)malloc(sizeof(termios));
	return (s_term);
}

int		main(int ac, char **av, char **env)
{
	struct termios	*s_term;

	ac > 1 ? s_term = ft_init(ac, av, env) : error_select(0);
}