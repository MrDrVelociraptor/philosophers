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

int	t_time(void)
{
	int				time;
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	time = ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
	return (time);
}

void	timer(t_philo	*philo, unsigned long time)
{
	long	curr;

	curr = clock();
	while (!philo->dead)
	{
		usleep(time * 1000);
		if (clock() - curr >= time)
			break;
	}
}
