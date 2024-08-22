#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define MAX_OF_PHILO 200

typedef struct s_info	t_info;

typedef enum s_action
{
	TAKING,
	EATING,
	SLEEPING,
	THINKING,
	DIE,
}	t_action;

typedef enum s_color
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	BOLD,
	STOP,
	
}	t_color;

typedef struct s_philo
{
	t_info		*info;
	int			id;
	int			num_of_times_eaten;
	int			last_eat_times;
	pthread_t	thread;
}	t_philo;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_must_eat;
	int				start_time;
	t_philo			philo[MAX_OF_PHILO];
	pid_t			pids[MAX_OF_PHILO];
	sem_t			waiter;
	sem_t			fork;
	sem_t			*sem_done;
	sem_t			*sem_print;
	sem_t			*sem_stop;
	sem_t			*sem_waiter;
	sem_t			*sem_fork;
	sem_t			*sem_dead;
	pthread_t		reaper_thread;
	bool			stop_sim;

}	t_info;

void	print_error(char *message);
int		main(int argc, char	**argv);
void	handle_args_error(int argc, char **argv, t_info *info);
int		ft_atoi(const char *str);
void	info_init(t_info *info);
void	handle_philosophers(t_info *info);
void	handle_a_philosopher(t_info *info);
int		get_time(void);
void	taking_fork(t_philo *philo);
void	eating_spaghetti(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	filter_and_output_actions(t_philo *philo, t_action action);
void	skip_time(int time);
char	*color(t_color color);
void	routine(t_philo	*philo);
bool	is_philo_dead(t_philo *philo);

#endif