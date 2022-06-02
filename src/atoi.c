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

static size_t	isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	atoi(const char *str)
{
	int	result;
	int	negpos;

	result = 0;
	negpos = 1;
	while (isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negpos *= -1;
		str++;
	}
	while (isdigit(*str))
	{
		result *= 10;
		result += *str++ - '0';
	}
	return (result * negpos);
}	

// void	dishes(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->nop)
// 	{
// 		pthread_mutex_destroy(&data->philo[i].fork);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&data->print);
// 	free(data->philo);
// 	exit(0);
// }