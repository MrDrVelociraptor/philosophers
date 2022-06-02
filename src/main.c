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
	int		time;

	i = 0;
	time = t_time();
	if (argc < 5 || argc > 7)
		return (0);
	init_args(&info, argv);
	init_mutexes(&info);
	printf("args have been initialised\n");
	printf("Time since start = %ims\n", t_time());
	timer(info.philo, info.tts);
	printf("Time slept for = %ims\n", t_time() - time);
	printf("Time after sleep = %ims\n", t_time());
	



	return (0);
}

