/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:41:00 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:41:00 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_info		info;

	if (!(argc == 5 || argc == 6))
		print_error("The number of arguments is different !");
	handle_argm_error(argc, argv, &info);
	info_init(&info);
	if (info.num_of_philo == 1)
		handle_a_philosopher(&info);
	else
		handle_philosophers(&info);
	mutex_destroy(&info);
	return (0);
}
