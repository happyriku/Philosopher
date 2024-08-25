#include "../include/philosophers_bonus.h"

void	handle_a_philosopher(t_info *info)
{
	filter_and_output_actions(&info->philo[0], TAKING);
	skip_time(info->time_to_die);
	filter_and_output_actions(&info->philo[0], DIE);
}