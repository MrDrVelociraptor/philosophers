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



// void	print_status(t_data *data, t_philo *philo, int n)
// {
// 	size_t	t2;

// 	pthread_mutex_lock(&data->print);
// 	t2 = whats_the_time_mr_wolf() - data->start_time;
// 	if (!data->dead)
// 	{
// 		if (n == 1)
// 			printf("%zu Philo %i has taken a fork\n", t2, 
// 				philo->philo_num);
// 		if (n == 3)
// 			printf("%zu Philo %i is eating\n", t2, 
// 				philo->philo_num);
// 		if (n == 4)
// 			printf("%zu Philo %i is sleeping\n", t2, 
// 				philo->philo_num);
// 		if (n == 5)
// 			printf("%zu Philo %i is thunking\n", t2, 
// 				philo->philo_num);
// 	}
// 	if (n == 6 && !data->done_eating)
// 		printf("%zu Philo %i is dead\n", t2, philo->philo_num);
// 	pthread_mutex_unlock(&data->print);
// }

// void	lock_forks(t_data *data, t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->fork);
// 	print_status(data, philo, 1);
// 	pthread_mutex_lock(&philo->philo_to_right->fork);
// 	print_status(data, philo, 2);
// }

// void	food(t_philo *philo)
// {
// 	print_status(philo->data, philo, 3);
// 	how_long(philo->data, philo->data->tte);
// 	pthread_mutex_unlock(&philo->fork);
// 	pthread_mutex_unlock(&philo->philo_to_right->fork);
// }

// void	rest(t_philo *philo)
// {
// 	print_status(philo->data, philo, 4);
// 	how_long(philo->data, philo->data->tts);
// 	print_status(philo->data, philo, 5);
// }

// void	*actions(void *philosopher)
// {
// 	t_data	*data;
// 	t_philo	*philo;

// 	philo = (t_philo *)philosopher;
// 	data = philo->data;
// 	if (philo->philo_num % 2 == 0)
// 		usleep(1000);
// 	while (!data->dead)
// 	{
// 		lock_forks(data, philo);
// 		food(philo);
// 		rest(philo);
// 	}
// 	return (NULL);
// }