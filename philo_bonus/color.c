#include "philosophers_bonus.h"

char	*color(t_color color)
{
	if (color == RED)
		return ("\x1b[31m");
	if (color == GREEN)
		return ("\x1b[32m");
	if (color == BLUE)
		return ("\x1b[34m");
	if (color == YELLOW)
		return ("\x1b[33m");
	if (color == STOP)
		return ("\x1b[39m");
}