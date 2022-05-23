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
	while (i < data->who_at_dinner)
	{
		pthread_create(data->philosopher[i].philo_id, NULL, are_you, &data->philosopher[i]);
		data->philosopher[i].last_meal = data->the_beginning;
		i++;
	}
}

void	status(t_data *data)
{
	while (!data->done_eating && !data->starvation)
		are_you_dead(data);
}

void	are_you_dead(t_data *data)
{
	int	i;

	i = 0;
	while (!data->starvation && i < data->who_at_dinner)
	{
		if (whats_the_time_mr_wolf() - data->philosopher[i].last_meal >= data->time_to_die)
		{
			data->starvation = true;
			print_status(data, 6);
			dishes(data);
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_data	data;

	i = 0;
	if (argc < 5 || argc > 7)
		return (0);
	if (argv[1] < '2')
		printf("Can't eat with only one fork apparently\n");
	set_the_table(&data, argv);
	data.the_beginning = whats_the_time_mr_wolf();
	threader(&data);
	status(&data);
	while (i < data.who_at_dinner)
		pthread_join(data.philosopher[i].philo_id, NULL);
	dishes(&data);
	return (0);
}

