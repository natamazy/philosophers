/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:32:34 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 21:09:47 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&philo->all_info->mutex_die);
	i = *philo->is_dead;
	pthread_mutex_unlock(&philo->all_info->mutex_die);
	return (i);
}

void	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->all_info->mutex_write);
	if (!is_dead(philo))
		printf("%lld %i %s", get_time(), philo->id + 1, message);
	pthread_mutex_unlock(&philo->all_info->mutex_write);
}

int	simulation_helper(t_philo *p, pthread_mutex_t *l_f,
	pthread_mutex_t *r_f)
{
	pthread_mutex_lock(l_f);
	print_message(p, "has taken a fork\n");
	if (l_f == r_f)
	{
		pthread_mutex_unlock(l_f);
		return (1);
	}
	pthread_mutex_lock(r_f);
	print_message(p, "has taken a fork\n");
	print_message(p, "is eating\n");
	my_sleep(p->all_info->eat_time);
	pthread_mutex_unlock(l_f);
	pthread_mutex_unlock(r_f);
	pthread_mutex_lock(&p->each_eat);
	p->eat_counter++;
	pthread_mutex_unlock(&p->each_eat);
	pthread_mutex_lock(&p->last_eat_mutex);
	p->last_eat = get_time();
	pthread_mutex_unlock(&p->last_eat_mutex);
	print_message(p, "is sleeping\n");
	my_sleep(p->all_info->sleep_time);
	print_message(p, "is thinking\n");
	return (0);
}

void	*start_sim(t_philo *p)
{
	pthread_mutex_t	*l_f;
	pthread_mutex_t	*r_f;

	l_f = &p->all_info->forks[p->id];
	r_f = &p->all_info->forks[(p->id + 1) % p->all_info->philos_count];
	pthread_mutex_lock(&p->last_eat_mutex);
	p->last_eat = get_time();
	pthread_mutex_unlock(&p->last_eat_mutex);
	if (p->id % 2 == 1)
		my_sleep(p->all_info->eat_time);
	while (!is_dead(p))
	{
		if (simulation_helper(p, l_f, r_f) == 1)
			break ;
	}
	return (NULL);
}

void	creating_threads(t_info *all_info)
{
	int	i;

	i = -1;
	get_time();
	while (++i < all_info->philos_count)
		pthread_create(&all_info->philos[i].thread, NULL,
			(void *) start_sim, all_info->philos + i);
	while (1)
	{
		if (check_die(all_info) || check_eat(all_info))
			break ;
	}
	i = 0;
	while (i < all_info->philos_count)
	{
		pthread_join(all_info->philos[i].thread, NULL);
		pthread_mutex_destroy(&all_info->forks[i]);
		pthread_mutex_destroy(&all_info->philos[i].last_eat_mutex);
		pthread_mutex_destroy(&all_info->philos[i].each_eat);
		i++;
	}
	pthread_mutex_destroy(&all_info->mutex_die);
	pthread_mutex_destroy(&all_info->mutex_write);
	free(all_info->philos);
	free(all_info->forks);
}
