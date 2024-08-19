#include "philosophers_bonus.h"

void	output_actions(t_philo *philo, t_action action)
{
	int elapsed_time;

	if (action == DIE)
	{
		elapsed_time = get_time() - philo->info->start_time;
		printf("%s%d %d died%s\n", color(RED), elapsed_time, philo->id, color(STOP));	
	}
	if (action == TAKING)
	{
		elapsed_time = get_time() - philo->info->start_time;
		printf("%d %d has taken a fork\n", elapsed_time, philo->id);
	}
}