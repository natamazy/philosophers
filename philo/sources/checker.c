/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:23:50 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 17:33:27 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_info *all_info)
{
	int	i;

	i = 0;
	while (i < all_info->philos_count)
	{
		pthread_mutex_lock(&all_info->philos[i].last_eat_mutex);
		if (get_time() - all_info->philos[i].last_eat >= all_info->die_time)
		{
			pthread_mutex_lock(&all_info->mutex_die);
			all_info->is_dead = 1;
			pthread_mutex_unlock(&all_info->mutex_die);
			pthread_mutex_lock(&all_info->mutex_write);
			printf("%lld %i died\n", get_time(), i + 1);
			pthread_mutex_unlock(&all_info->mutex_write);
			pthread_mutex_unlock(&all_info->philos[i].last_eat_mutex);
			return (1);
		}
		pthread_mutex_unlock(&all_info->philos[i].last_eat_mutex);
		i++;
	}
	return (0);
}

int	check_eat(t_info *all_info)
{
	int	i;
	int	counter;

	if (all_info->must_eat == -1)
		return (0);
	i = 0;
	counter = 0;
	while (i < all_info->philos_count)
	{
		pthread_mutex_lock(&all_info->philos[i].each_eat);
		if (all_info->philos[i].eat_counter >= all_info->must_eat)
			counter++;
		if (counter == all_info->philos_count)
		{
			pthread_mutex_lock(&all_info->mutex_die);
			all_info->is_dead = 1;
			pthread_mutex_unlock(&all_info->mutex_die);
			pthread_mutex_unlock(&all_info->philos[i].each_eat);
			return (1);
		}
		pthread_mutex_unlock(&all_info->philos[i].each_eat);
		i++;
	}
	return (0);
}
