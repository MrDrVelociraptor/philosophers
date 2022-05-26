/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:41:34 by nspeedy           #+#    #+#             */
/*   Updated: 2022/05/23 12:41:36 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threader(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nop)
	{
		pthread_create(&data->philo[i].philosopher, NULL, &actions, &data->philo[i]);
		data->philo[i].time_since_last_food = data->start_time;
		i++;
	}
}

void	status(t_data *data, t_philo *philo)
{
	while (!data->done_eating && !data->dead)
		are_you_dead(data, philo);
}

void	are_you_dead(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (!data->dead && i < data->nop)
	{
		if (whats_the_time_mr_wolf() - data->philo[i].time_since_last_food >= data->ttd)
		{
			data->dead = true;
			print_status(data, philo, 6);
			dishes(data);
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;
	t_philo	philo;

	i = 0;
	if (argc < 5 || argc > 7)
		return (0);
	
	init_args(&data, argv);
	data.start_time = whats_the_time_mr_wolf();
	threader(&data);
	status(&data, &philo);
	while (i < data.nop)
	{
		pthread_join(data.philo[i].philosopher, NULL);
		i++;
	}
	dishes(&data);
	return (0);
}

