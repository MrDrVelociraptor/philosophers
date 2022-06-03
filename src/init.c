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

void	init_args(t_info *info, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->nop = atoi(argv[1]);
	info->ttd = atoi(argv[2]);
	info->tte = atoi(argv[3]);
	info->tts = atoi(argv[4]);
}

void	init_mutexes(t_info *info)
{
	int	i;

	i = 0;
	info->philo = (t_philo *)malloc(info->nop * sizeof(t_philo));
	memset(info->philo, 0, sizeof(t_philo) * info->nop);
	pthread_mutex_init(&info->print, NULL);
	while (i < info->nop)
	{
		info->philo[i].info = info;
		info->philo[i].place = i + 1;
		pthread_mutex_init(&info->philo[i].fork, NULL);
		info->philo[i].neighbour = &info->philo[(i + 1) % info->nop];
		i++;
	}
}

void	init_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nop)
	{
		pthread_create(&info->philo[i].people, NULL,
			&est, &info->philo[i]);
		info->philo[i].hunger = info->start;
		i++;
	}
}
