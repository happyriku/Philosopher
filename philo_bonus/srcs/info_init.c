#include "../include/philosophers_bonus.h"

void	philo_info_init(t_philo	*philo, t_info *info, int num)
{
	philo->info = info;
	philo->num_of_times_eaten = 0;
	philo->id = num + 1;
	philo->last_eat_times = 0;
	philo->is_eaten = true;
	if (info->argc == 6)
		philo->num_of_meals = 0;
	else
		philo->num_of_meals = 1;
}

void	semaphore_init(t_info *info)
{
	sem_unlink("/sem_done");
	sem_unlink("/sem_print");
	sem_unlink("/sem_stop");
	sem_unlink("/sem_fork");
	sem_unlink("/sem_dead");
	info->sem_fork = sem_open("/sem_fork", O_CREAT, 0644, info->num_of_philo);
	info->sem_done = sem_open("/sem_done", O_CREAT, 0644, 0);
	info->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	info->sem_stop = sem_open("/sem_stop", O_CREAT, 0644, 1);
	info->sem_dead = sem_open("/sem_dead", O_CREAT, 0644, 1);
	info->sem_philo = sem_open("/sem_philo", O_CREAT, 0644, 0);
}

void	info_init(t_info *info, int argc, char **argv)
{
	int	i;

	info->argc = argc;	
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_times_philo_must_eat = ft_atoi(argv[5]);
	info->stop_sim = false;
	info->is_done = false;
	i = -1;
	while (++i < info->num_of_philo)
		philo_info_init(&info->philo[i], info, i);
	semaphore_init(info);
}