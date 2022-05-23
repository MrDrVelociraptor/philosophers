/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:48:44 by nspeedy           #+#    #+#             */
/*   Updated: 2022/05/19 11:48:47 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	print_status(t_data *data, int n)
{
	size_t	t2;

	pthread_mutex_lock(&data->print);
	t2 = whats_the_time_mr_wolf() - data->the_beginning;
	if (!data->starvation)
	{
		if (n == 1)
			printf("%zu Philo %i has taken a fork\n", t2, 
				data->philosopher->phil_num);
		if (n == 2)
			printf("%zu Philo %i has taken the fork from philo %i\n", t2, 
				data->philosopher->phil_num, data->philosopher->forking_thief->phil_num);
		if (n == 3)
			printf("%zu Philo %i is eating\n", t2, 
				data->philosopher->phil_num);
		if (n == 4)
			printf("%zu Philo %i is sleeping\n", t2, 
				data->philosopher->phil_num);
		if (n == 5)
			printf("%zu Philo %i is thunking\n", t2, 
				data->philosopher->phil_num);
	}
	if (n == 6 && !data->done_eating)
		printf("%zu Philo %i is dead\n", t2, data->philosopher->phil_num);
	pthread_mutex_unlock(&data->print);
}

void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	print_status(philo->data, 1);
	pthread_mutex_lock(&philo->forking_thief->fork);
	print_status(philo->data, 2);
}

void	food(t_data *data)
{
	data = data->philosopher->data;
	data->philosopher->meals++;
	print_status(&data, 3);
	data->philosopher->last_meal = whats_the_time_mr_wolf();
	usleep(1000);
	pthread_mutex_unlock(&data->philosopher->fork);
	pthread_mutex_unlock(&data->philosopher->forking_thief->fork);
}

void	rest(t_data *data)
{
	print_status(&data->philosopher->phil_num, 4);
	how_long(&data->philosopher->phil_num, data->time_to_sleep);
	print_status(&data->philosopher->phil_num, 5);
}

void	are_you(t_data *data)
{
	if (data->philosopher->phil_num % 2 == 0)
		usleep(1000);
	while (!data->starvation && data->philosopher->meals != data->catering)
	{
		lock_forks(data->philosopher->phil_num);
		food(data->philosopher->phil_num);
		rest(data->philosopher->phil_num);
	}
	if (data->philosopher->meals == data->catering)
		data->done_eating = true;
}