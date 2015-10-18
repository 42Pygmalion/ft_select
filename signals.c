#include "ft_select.h"

int 		g_winch = 0;

// # define ERROR_IOCTL 8

// typedef struct winsize t_winsize;

// t_winsize 				ft_check_winsize(void)
// {
// 	t_winsize ws;

// 	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
// 		error_select(ERROR_IOCTL);

// 	return (ws)
// }

void				ft_refresh()

void				ft_sig_handler(int sig)
{
	if (sig = SIGWINCH) // changement de taille de fenetre
		g_winch = 1; // globale ou singleton
	else if (SIGTSTP) // ctrl Z
	{
		signal(SIGTSTP, SIG_DFL);
		 tgetstr("ve", NULL);
        tputs(tmp, 1, custom_putchar);
	}
	else if (SIGCONT) // fg
	{

	}
	else // tous les autres
		error_select(sig);
}

void				check_signals(void)
{
	int sig;

	sig = 1;
	while (sig < 32)
		signal(sig++, ft_sig_handler);
}