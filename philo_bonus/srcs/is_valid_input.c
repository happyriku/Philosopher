/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:07:48 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:07:48 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

bool	print_error_msg(int num)
{
	if (num == 1)
		printf("please make sure argv[1] (0 < num_of_philo <= 200)");
	else if (num == 2)
		printf("please make sure argv[2] (0 < time_to_die)");
	else if (num == 3)
		printf("please make sure argv[3] (0 < time_to_eat)");
	else if (num == 4)
		printf("please make sure argv[4] (0 < time_to_sleep)");
	else if (num == 5)
		printf("please make sure argv[5] (0 < num_of_times_must_eat)");
	return (false);
}

bool	is_valid_input(int argc, char **argv)
{
	int	i;
	int	num;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 0;
	while (++i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1 && (num < 0 || MAX_OF_PHILO < num))
			return (print_error_msg(i));
		else if (num <= 0)
			return (print_error_msg(i));
	}
	return (true);
}
