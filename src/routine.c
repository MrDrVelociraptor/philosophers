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

void    status(t_info *info, int n)
{
    unsigned long   stamp;

    pthread_mutex_lock(&info->print);
    stamp = (unsigned long)t_time - info->start;
    if (n == 1)
        printf("%lims Philo %i taken forks\n", stamp, info->philo->place);
    if (n == 2)
        printf("%lims Philo %i is eating\n", stamp, info->philo->place);
    if (n == 3)
        printf("%lims Philo %i is sleeping\n", stamp, info->philo->place);
    if (n == 4)
        printf("%lims Philo %i is thinking\n", stamp, info->philo->place);
    if (n == 5)
        printf("%lims Philo %i has died\n", stamp, info->philo->place);
    pthread_mutex_unlock(&info->print);
}

void	lock_forks(t_info *info)
{
	pthread_mutex_lock(&info->philo->fork);
	status(info, 1);
	pthread_mutex_lock(&info->philo->neighbour->fork);
	status(info, 2);
}

void	food(t_info *info)
{
    info->philo->hunger = t_time();
	status(info, 3);
    usleep((info->tte - 1) * 1000);
	pthread_mutex_unlock(&info->philo->fork);
	pthread_mutex_unlock(&info->philo->neighbour->fork);
}

void	rest(t_info *info)
{
	status(info, 4);
    usleep((info->tts - 1) * 1000);
	status(info, 5);
}

void	*est(void *philosopher)
{
	t_info  *info;
	t_philo	*philo;

	philo = (t_philo *)philosopher;
    info = philo->info;
	if (philo->place % 2 == 0)
		usleep(1000);
	while (!philo->dead)
	{
		lock_forks(info);
		food(info);
		rest(info);
	}
	return (NULL);
}