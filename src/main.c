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

static bool	str_len(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
		i++;
	return (i);
}

static bool	valid_num(char *num)
{
	int	i;
	int	len;

	i = 0;
	len = str_len(num);
	while (num[i])
	{
		if (num[i] == '-')
			return (false);
		if (num[i] < '0' && num[i] > '9')
			return (false);
		i++;
	}
	if (len <= 10)
		return (true);
	if (len > 10)
		return (false);
	return (true);
}

static bool	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
		return (0);
	while (argv[i])
	{
		if (!valid_num(argv[i]))
		{
			printf("Don't be uncouth\n");
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int		i;
	t_info	info;

	i = 0;
	if (check_args(argc, argv) == false)
		exit(1);
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
	dishes(&info);
	return (0);
}
