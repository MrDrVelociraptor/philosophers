/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                          :+:      :+:    :+:      */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 13:07:43 by nspeedy           #+#    #+#             */
/*   Updated: 2022/01/17 09:46:30 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	atoi(const char *str)
{
	int	value;
	int	posneg;

	value = 0;
	posneg = 1;
	while (*str == '\f' || *str == '\r' || *str == '\n'
		|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '-')
		posneg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (value * posneg);
}
