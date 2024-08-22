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

void	skip_time(int time)
{
	int start_time;

	start_time = get_time();
	printf("time : %d\n", time);
	while (time >= get_time() - start_time)
	{
		printf("elaped time : %d\n", get_time() - start_time);
		usleep(100);
	}
}