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
# include <math.h>

typedef struct s_philo
{
	int				phil_num;
	int				meals;
	size_t			last_meal;
	pthread_t		*philo_id;
	pthread_mutex_t	fork;
	struct s_data	*data;
	struct s_philo	*forking_thief;
}	t_philo;

typedef struct s_data
{
	int				who_at_dinner;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				catering;
	size_t			the_beginning;
	bool			done_eating;
	bool			starvation;
	t_philo			*philosopher;
	pthread_mutex_t	print;
}	t_data;

void	set_the_table(t_data *data, char **argv);
void	who_got_the_fork(t_data *data);
size_t	whats_the_time_mr_wolf(void);
void	print_status(t_data *data, int n);
void	how_long(t_data *data, size_t time);
void	lock_forks(t_philo *philo);
void	food(t_data *data);
void	rest(t_data *data);
void	*are_you(t_data *data);
int		atoi(const char *str);
void	dishes(t_data *data);
void	status(t_data *data);
void	threader(t_data *data);
void	are_you_dead(t_data *data);

#endif
