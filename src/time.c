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

size_t	whats_the_time_mr_wolf(void) //returns time in milliseconds since 1/1/1970
{
	struct timeval	spag;

	gettimeofday(&spag, NULL);
	return ((spag.tv_sec * 1000) + (spag.tv_usec / 1000));
}

void	how_long(t_data *data, size_t time)
{
	size_t	curr;

	curr = whats_the_time_mr_wolf();
	while (!(data->dead))
	{
		if (whats_the_time_mr_wolf() - curr >= time)
			break;
		usleep(100);
	}
}