/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   people.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:49:44 by nspeedy           #+#    #+#             */
/*   Updated: 2022/05/12 13:49:46 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	t_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

void	are_you_dead(t_info *info)
{
	int	i;

	i = 0;
	while (!info->philo->dead && i < info->nop)
	{
		if (t_time() - info->philo[i].hunger >= info->ttd)
		{
			info->philo->dead = true;
			status(info, info->philo, 5);
			dishes(info);
		}
	}
}

void	dishes(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nop)
	{
		pthread_mutex_destroy(&info->philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	free(info->philo);
	exit(0);
}
