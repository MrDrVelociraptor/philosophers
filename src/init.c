/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getreadyfordinner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:29:14 by nspeedy           #+#    #+#             */
/*   Updated: 2022/05/13 10:29:18 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(t_data *data, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->nop = atoi(argv[1]);
	data->ttd = atoi(argv[2]);
	data->tte = atoi(argv[3]);
	data->tts = atoi(argv[4]);
	data->start_time = whats_the_time_mr_wolf();
	pthread_mutex_init(&data->print, NULL);
	who_got_the_fork(data);
}

void	who_got_the_fork(t_data *data)
{
	int	i;

	i = 0;
	data->philo = (t_philo *)malloc(data->nop * sizeof(t_philo));
	while (i < data->nop)
	{
		data->philo[i].data = data;
		data->philo[i].philo_num = i + 1;
		pthread_mutex_init(&data->philo[i].fork, NULL);
		if (i == data->nop)
			data->philo[i].philo_to_right = &data->philo[0];
		else
			data->philo[i].philo_to_right = &data->philo[i + 1];
		i++;
	}
}
