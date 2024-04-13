/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:18 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/13 12:43:17 by natamazy         ###   ########.fr       */
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
typedef struct s_info
{
	int	philos_count;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
}	t_info;

typedef struct s_philo
{
	bool	died;
}	t_philo;

// validation.c
int	validation(int argc, char *argv[], t_info *all_info);

#endif