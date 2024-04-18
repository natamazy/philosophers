/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:18 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 20:58:53 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define SEMEAT "/eat"
# define SEMLASTEAT "/last_eat"
# define SEMFORKS "/forks"
# define SEMWRITE "/write"
# define SEMDIE "/die"

// printf
# include <stdio.h>

// pthread
# include <pthread.h>

// usleep
# include <unistd.h>

// malloc
# include <stdlib.h>

// limits
# include <limits.h>

// bool
# include <stdbool.h>

// gettimeofday
# include <sys/time.h>

// semaphore
# include <semaphore.h>

// signals
# include <signal.h>

struct	s_info;

// struct
typedef struct s_philo
{
	long long		last_eat;
	int				*is_dead;
	int				id;
	int				eat_counter;
	pid_t			pid;
	pthread_t		thread;
	pthread_mutex_t	each_eat;
	struct s_info	*all_info;
}		t_philo;

typedef struct s_info
{
	int				philos_count;
	int				die_time;
	int				must_eat;
	int				eat_time;
	int				sleep_time;
	int				is_dead;
	t_philo			*philos;
	sem_t			*forks;
	sem_t			*write_sem;
	sem_t			*die_sem;
	sem_t			*each_eat_sem;
	sem_t			*last_eat_sem;
}		t_info;

// validation.c
int			validation(int argc, char *argv[], t_info *all_info);

// init.c
int			initialization(t_info *all_info);
void		cl_unl(t_info *all_info);

// simulation.c
void		creating_forks(t_info *all_info);

// time.c
long long	get_time(void);
void		my_sleep(long long time1);

// checker.c
int			check_die(t_philo *philo);
int			check_eat(t_philo *philo);
void		lock_last_eat(t_philo *p);
void		*to_check(t_philo *philo);

#endif