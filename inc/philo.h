/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nspeedy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:30:07 by nspeedy           #+#    #+#             */
/*   Updated: 2022/06/03 11:32:06 by nspeedy          ###   ########.fr       */
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
	int				place;
	size_t			hunger;
	bool			dead;
	pthread_t		people;
	pthread_mutex_t	fork;
	struct s_philo	*neighbour;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				nop;
	size_t			ttd;
	size_t			tte;
	size_t			tts;
	size_t			start;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_info;

void	init_args(t_info *info, char **argv);
size_t	t_time(void);
void	timer(t_info *info, t_philo	*philo, size_t time);
void	init_mutexes(t_info *info);
void	*est(void *philosopher);
void	rest(t_philo *philo);
void	food(t_philo *philo);
void	lock_forks(t_philo *philo);
void	status(t_info *info, t_philo *philo, int n);
void	are_you_dead(t_info *info);
void	dishes(t_info *info);
void	init_thread(t_info *info);

#endif
