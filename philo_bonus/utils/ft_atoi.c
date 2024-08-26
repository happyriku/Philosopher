/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-26 06:08:38 by rishibas          #+#    #+#             */
/*   Updated: 2024-08-26 06:08:38 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

static void	rm_isspace(const char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
}

static void	rm_sign(const char *str, int *i, int *sign)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	rm_isspace(str, &i);
	rm_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if (((num == 922337203685477580 && (str[i] - '0') > 6)
				|| (num >= 922337203685477581 && (str[i] - '0') >= 0))
			&& sign == 1)
			return (-1);
		else if (num >= 922337203685477580 && (str[i] - '0') > 7 && sign == -1)
			return (0);
	}
	return (sign * num);
}
