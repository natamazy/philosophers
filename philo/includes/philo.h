/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:18 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/16 17:00:31 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

// struct
typedef struct s_philo
{
	unsigned long	last_eat;
	int				*is_dead;
	int				id;
	int				eat_time;
	int				sleep_time;
	int				eat_counter;
	pthread_t		philo;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	each_eat;
	pthread_mutex_t	*mutex_die;
	pthread_mutex_t	*mutex_write;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
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
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	*forks;
}		t_info;

// validation.c
int	validation(int argc, char *argv[], t_info *all_info);

// init.c
int	initialization(t_info *all_info);

#endif