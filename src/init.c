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
	printf("ttd is %i\n", info->ttd);
	printf("tte is %i\n", info->tte);
	printf("tts is %i\n", info->tts);
}

void	init_mutexes(t_info *info)
{
	int	i;

	i = 0;
	info->philo = (t_philo *)malloc(info->nop * sizeof(t_philo));
	//memset(info->philo, 0, sizeof(t_philo) * info->nop);
	if(!pthread_mutex_init(&info->print, NULL))
		printf("Printing locked\n");
	while (i < info->nop)
	{
		//info->philo[i].info = info;
		info->philo[i].place = i + 1;
		printf("Philosopher %i is alive\n", info->philo[i].place);
		pthread_mutex_init(&info->philo[i].fork, NULL);
		info->philo[i].neighbour = &info->philo[(i + 1) % info->nop];
		// if (i == info->nop - 1)
		// 	info->philo[i].neighbour = &info->philo[0];
		// else
		// 	info->philo[i].neighbour = &info->philo[i + 1];
		i++;
	}
}

void	init_thread(t_info *info)
{
	int	i;

	i = 0;
	info->philo[i].hunger = 0;
	printf("nop = %i\n", info->nop);
	while (i < info->nop)
	{
		pthread_create(&info->philo[i].people, NULL,
			&est, &info->philo[i]);
		info->philo[i].hunger = info->start;
		printf("hunger = %i\n", info->philo[i].hunger);
		i++;
	}
}