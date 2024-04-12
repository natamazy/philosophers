/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:18 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/12 18:15:15 by natamazy         ###   ########.fr       */
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

// struct
typedef struct s_info
{
	long long	philos_count;
	long long	die_time;
	long long	eat_time;
	long long	sleep_time;

	long long	must_eat;
}	t_info;

// validation.c
int	validation(int argc, char *argv[], t_info *all_info);

#endif