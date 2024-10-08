/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:09:27 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:09:27 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <errno.h>

# define MAX_OF_PHILO 200

# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

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
	int			num_of_meals;
	bool		is_full;
	pthread_t	thread;
}	t_philo;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_philo_must_eat;
	int				start_time;
	int				argc;
	t_philo			philo[MAX_OF_PHILO];
	pid_t			pids[MAX_OF_PHILO];
	sem_t			*sem_done;
	sem_t			*sem_print;
	sem_t			*sem_stop;
	sem_t			*sem_philo;
	sem_t			*sem_fork;
	sem_t			*sem_dead;
	sem_t			*sem_error;
	sem_t			*sem_shared;
	sem_t			*sem_see;
	pthread_t		famine_reaper_thread;
	pthread_t		gluttony_reaper_thread;
	bool			stop_sim;
	bool			is_done;

}	t_info;

void	print_error(char *message, t_info *info);
int		main(int argc, char	**argv);
int		ft_atoi(const char *str);
bool	init_info(t_info *info, int argc, char **argv);
void	handle_philosophers(t_info *info);
void	handle_a_philosopher(t_info *info);
int		get_time(void);
void	taking_fork(t_philo *philo);
void	eating_spaghetti(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo, bool silent);
void	filter_and_output_actions(t_philo *philo, t_action action);
void	skip_time(int time);
char	*color(t_color color);
void	routine(t_philo	*philo);
bool	is_philo_dead(t_philo *philo);
bool	has_simulation_stop(t_info *info);
bool	is_valid_input(int argc, char **argv);
void	kill_all_philosophers(t_info *info);
void	cleanup_info(t_info *info);
void	cleanup_sem(t_info *info);

#endif