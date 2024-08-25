#include "../include/philosophers_bonus.h"

char	*color(t_color color)
{
	if (color == RED)
		return ("\x1b[31m");
	else if (color == GREEN)
		return ("\x1b[32m");
	else if (color == BLUE)
		return ("\x1b[34m");
	else if (color == YELLOW)
		return ("\x1b[33m");
	else if (color == BOLD)
		return ("\e[37m");
	else if (color == STOP)
		return ("\x1b[39m");
	else
		return (NULL);

}