/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:40:27 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:40:27 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

char	*color(t_color color)
{
	if (color == STOP)
		return ("\e[0m");
	if (color == RED)
		return ("\e[31m");
	if (color == GREEN)
		return ("\e[32m");
	if (color == YELLOW)
		return ("\e[33m");
	if (color == BLUE)
		return ("\e[34m");
	if (color == BOLD)
		return ("\e[37m");
	return (NULL);
}
