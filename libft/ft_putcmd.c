#include "libft.h"

int		ft_putcmd(int c)
{
	return (write(1, &c, 1));
}