#ifndef FT_SELECT
# define FT_SELECT

# include <termios.h>
# include <term.h>
# include <curses.h>
# include "libft/libft.h"

# define UP			4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define ESCAPE		27
# define SPACE		32
# define RETURN		10
# define BACK		127
# define DEL		2117294875
# define TAB		9
# define CMD_C		3
# define CMD_A		1

typedef struct 		s_select
{
	char			*name;
	int				type;
	struct s_select	*next;
	struct s_select	*prev;
}					t_select;

#endif