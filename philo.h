/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:30:07 by nspeedy           #+#    #+#             */
/*   Updated: 2022/05/12 09:30:09 by nspeedy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <stdbool.h>

typedef struct s_philo
{
	int				phil_num;
	int				number_of_times_each_philosopher_must_eat;
	int				last_meal;
	pthread_t		*philo_id;
	pthread_mutex_t	fork;
	struct s_data	*data;
	struct s_philo	*forking_thief;
}	t_philo;

typedef struct s_data
{
	int				who_at_dinner;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				catering;
	int				the_beginning;
	bool			done_eating;
	bool			starvation;
	t_philo			*philosopher;
	pthread_mutex_t	print;
}	t_data;

#endif
