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



int	main(int argc, char **argv)
{
	int		i;
	t_info	info;
	// unsigned long	time;

	i = 0;
	// time = t_time();
	if (argc < 5 || argc > 7)
		return (0);
	init_args(&info, argv);
	init_mutexes(&info);
	info.start = t_time();
	init_thread(&info);
	are_you_dead(&info);
	while (i < info.nop)
	{
		pthread_join(info.philo[i].people, NULL);
		i++;
	}
	printf("fart\n");
	dishes(&info);
	// printf("args have been initialised\n");
	// printf("Time since start = %lims\n", t_time());
	// usleep((info.tts - 1) * 1000);
	// printf("Time slept for = %lims\n", t_time() - time);
	// printf("Time after sleep = %lims\n", t_time());
	return (0);
}

