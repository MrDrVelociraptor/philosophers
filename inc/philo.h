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

typedef struct	s_philo
{
	int				place;
	int				hunger;
	bool			dead;
	pthread_t		people;
	pthread_t		watcher;
	pthread_mutex_t	fork;
	struct s_philo	*neighbour;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				start;
	pthread_mutex_t	print;
	t_philo			*philo;
}	t_info;

void	init_args(t_info *info, char **argv);
int		t_time(void);
void	timer(t_philo	*philo, unsigned long time);
void	init_mutexes(t_info *info);

#endif
