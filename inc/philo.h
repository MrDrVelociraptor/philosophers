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
	int				philo_num;
	size_t			time_since_last_food;
	pthread_t		philosopher;
	pthread_mutex_t	fork;
	struct s_data	*data;
	struct s_philo	*philo_to_right;
}	t_philo;

typedef struct s_data
{
	int				nop;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	size_t			start_time;
	bool			done_eating;
	bool			dead;
	t_philo			*philo;
	pthread_mutex_t	print;
}	t_data;

void	init_args(t_data *data, char **argv);
void	who_got_the_fork(t_data *data);
size_t	whats_the_time_mr_wolf(void);
void	print_status(t_data *data, t_philo *philo, int n);
void	how_long(t_data *data, size_t time);
void	lock_forks(t_data *data, t_philo *philo);
void	food(t_philo *philo);
void	rest(t_philo *philo);
void	*actions(void *philosopher);
int		atoi(const char *str);
void	dishes(t_data *data);
void	status(t_data *data, t_philo *philo);
void	threader(t_data *data);
void	are_you_dead(t_data *data, t_philo *philo);

#endif
