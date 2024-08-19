#include "philosophers_bonus.h"

void	handle_a_philosopher(t_info *info)
{
	info->start_time = get_time();
	take_fork(&info->philo[0]);
	//skip_time(info->time_to_die);
	output_actions(&info->philo[0], DIE);
}