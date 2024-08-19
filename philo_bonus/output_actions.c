#include "philosophers_bonus.h"

void	output_actions(t_philo *philo, t_action action)
{
	int elapsed_time;

	elapsed_time = get_time() - philo->info->start_time;
	if (action == TAKING)
		printf("%d %d has taken a fork\n", elapsed_time, philo->id);
	else if (action == EATING)
		printf("%d %d is eating\n", elapsed_time, philo->id);
	else if (action == SLEEPING)
		printf("%d %d is sleeping\n", elapsed_time, philo->id);
	else if (action == THINKING)
		printf("%d %d is thinking\n", elapsed_time, philo->id);
}

void	filter_and_output_actions(t_philo *philo, t_action action)
{
	int elapsed_time;

	if (action == DIE)
	{
		elapsed_time = get_time() - philo->info->start_time;
		printf("%s%d %d died%s\n", color(RED), elapsed_time, philo->id, color(STOP));	
	}
	else
		output_actions(philo, action);
}