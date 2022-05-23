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

void	set_the_table(t_data *data, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->who_at_dinner = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	if (argv[5])
		data->catering = atoi(argv[5]);
	else
		data->catering = -1;
	pthread_mutex_init(&data->print, NULL);
	who_got_the_fork(data);
}

void	who_got_the_fork(t_data *data)
{
	int	i;

	data->philosopher = (t_philo *)malloc(data->who_at_dinner * sizeof(t_philo));
	i = 0;
	while (i < data->who_at_dinner)
	{
		data->philosopher[i].data = data;
		data->philosopher[i].meals = 0;
		data->philosopher[i].phil_num = i + 1;
		pthread_mutex_init(&data->philosopher[i].fork, NULL);
		if (i + 1 == data->who_at_dinner)
			data->philosopher[i].forking_thief = &data->philosopher[0];
		else
			data->philosopher[i].forking_thief = &data->philosopher[i + 1];
		i++;
	}
}
