/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 10:35:53 by rishibas          #+#    #+#             */
/*   Updated: 2024/08/02 10:35:53 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>

# define MAX_OF_PHILO 200
# define SUCESS 0
# define FAILED 1

// typedef struct s_player	t_player;

typedef enum e_color
{
	RED,
	GREEN,
	YELLOW,
	BLUE,
	BOLD,
	STOP,
}	t_color;

typedef enum e_action
{
	TAKING,
	SLEEPING,
	EATING,
	THINKING,
	DIE,
}	t_action;

typedef struct s_info t_info;

typedef struct s_player
{
	int				id;
	int				right_fork;
	int				left_fork;
	t_info			*info;
	pthread_t		thread;
	pthread_t		monitor_thread;
	int				last_eat_time;
}	t_player;

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_must_eat;
	int				start_times;
	pthread_mutex_t	fork[MAX_OF_PHILO];
	t_player		philo[MAX_OF_PHILO];
	pthread_mutex_t	die;
	pthread_mutex_t print_mutex;
	bool			is_done;

}	t_info;

int		main(int argc, char **argv);
void	print_error(char *message);
void	handle_argm_error(int argc, char **argv, t_info *info);
void	init_info(t_info *info);
void	handle_single_philosopher(t_info *info);
int		get_time(void);
void    handle_philo_die(t_player *philo, int time);
void    taking_fork(t_player *philo);
void    eating_spaghetti(t_player *philo);
void    sleeping(t_player *philo);
void    thinking(t_player *philo);
void	skip_to_time(int target_time, int start_time);
void    print_action(t_player *philo, t_action action);
void    handle_philosophers(t_info *info);
char	*color(t_color color);
bool    check_is_died(t_player *philo);

#endif