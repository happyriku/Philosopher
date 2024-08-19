#include "philosophers_bonus.h"

void	output_actions(t_philo *philo, t_action action)
{
	int elapsed_time;

	if (action == DIE)
	{
		elapsed_time = get_time() - philo->info->start_time;
		printf("%d %d died\n", elapsed_time, philo->id);	
	}
}