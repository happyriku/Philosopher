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

void	skip_time(int time, t_info *info)
{
	int start_time;

	start_time = get_time();
	while (time >= get_time() - start_time)
	{
		if (info->is_done)
			break ;
		usleep(100);
	}
}