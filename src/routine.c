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

void	status(t_info *info, t_philo *philo, int n)
{
	size_t	stamp;

	pthread_mutex_lock(&info->print);
	stamp = t_time() - info->start;
	if (n == 1)
		printf("%lims Philo %i taken forks\n", stamp, philo->place);
	if (n == 2)
		printf("%lims Philo %i is eating\n", stamp, philo->place);
	if (n == 3)
		printf("%lims Philo %i is sleeping\n", stamp, philo->place);
	if (n == 4)
		printf("%lims Philo %i is thinking\n", stamp, philo->place);
	if (n == 5)
		printf("%lims Philo %i has died\n", stamp, philo->place);
	pthread_mutex_unlock(&info->print);
}

void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	status(philo->info, philo, 1);
	pthread_mutex_lock(&philo->neighbour->fork);
}

void	food(t_philo *philo)
{
	status(philo->info, philo, 2);
	philo->hunger = t_time();
	usleep((philo->info->tte - 1) * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->neighbour->fork);
}

void	rest(t_philo *philo)
{
	status(philo->info, philo, 3);
	usleep((philo->info->tts - 1) * 1000);
	status(philo->info, philo, 4);
}

void	*est(void *philosopher)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	info = philo->info;
	if (philo->place % 2 == 0)
	{
		rest(philo);
	}
	while (!philo->dead)
	{
		lock_forks(philo);
		food(philo);
		rest(philo);
	}
	return (NULL);
}
