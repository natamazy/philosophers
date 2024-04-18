/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:58:01 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 17:30:38 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_info *all_info)
{
	int	i;

	i = 0;
	while (i < all_info->philos_count)
	{
		all_info->philos[i].id = i;
		all_info->philos[i].last_eat = LLONG_MAX;
		all_info->philos[i].eat_counter = 0;
		all_info->philos[i].is_dead = &(all_info->is_dead);
		all_info->philos[i].all_info = all_info;
		pthread_mutex_init(&(all_info->philos[i].each_eat), NULL);
		pthread_mutex_init(&(all_info->philos[i].last_eat_mutex), NULL);
		pthread_mutex_init(&(all_info->forks[i]), NULL);
		i++;
	}
}

int	initialization(t_info *all_info)
{
	all_info->is_dead = 0;
	pthread_mutex_init(&(all_info->mutex_write), NULL);
	pthread_mutex_init(&(all_info->mutex_die), NULL);
	all_info->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * all_info->philos_count);
	if (!all_info->forks)
		return (1);
	all_info->philos = (t_philo *)
		malloc(sizeof(t_philo) * all_info->philos_count);
	if (!all_info->philos)
	{
		free(all_info->forks);
		return (1);
	}
	init_philos(all_info);
	return (0);
}
