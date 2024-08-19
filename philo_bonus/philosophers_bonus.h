#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdlib.h>

# define MAX_OF_PHILO 200

typedef struct s_info	t_info;

typedef enum action
{
	TAKING,
	EATING,
	SLEEPING,
	THINKING,
	DIE,
}	t_action;

typedef struct s_philo
{
	t_info	*info;
	int		id;
	int		num_of_times_eaten;
}	t_philo;

typedef struct s_info
{
	int		num_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_of_times_must_eat;
	int		start_time;
	t_philo	philo[MAX_OF_PHILO];
	sem_t	*waiter;
	sem_t	fork;

}	t_info;

void	print_error(char *message);
int		main(int argc, char	**argv);
void	handle_args_error(int argc, char **argv, t_info *info);
int		ft_atoi(const char *str);
void	info_init(t_info *info);
void	handle_philosophers(t_info *info);
void	handle_a_philosopher(t_info *info);
int		get_time(void);
void	take_fork(t_philo *philo);
void	output_actions(t_philo *philo, t_action action);

#endif