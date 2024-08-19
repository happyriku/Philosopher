#include "philosophers_bonus.h"

int	get_time(void)
{
	struct	timeval tv;
	int		time;

	if (gettimeofday(&tv, NULL) == -1)
		print_error("failed gettimeofday");
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}