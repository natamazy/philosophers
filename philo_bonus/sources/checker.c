/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:23:50 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 20:56:00 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_die(t_philo *philo)
{
	sem_wait(philo->all_info->last_eat_sem);
	if (get_time() - philo->last_eat >= philo->all_info->die_time)
	{
		sem_wait(philo->all_info->die_sem);
		philo->all_info->is_dead = 1;
		sem_post(philo->all_info->die_sem);
		sem_wait(philo->all_info->write_sem);
		printf("%lld %d died\n", get_time(), philo->id + 1);
		sem_post(philo->all_info->last_eat_sem);
		exit(1);
	}
	sem_post(philo->all_info->last_eat_sem);
	return (0);
}

int	check_eat(t_philo *philo)
{
	sem_wait(philo->all_info->each_eat_sem);
	if (philo->eat_counter == philo->all_info->must_eat)
	{
		sem_wait(philo->all_info->die_sem);
		philo->all_info->is_dead = 1;
		sem_post(philo->all_info->die_sem);
		sem_post(philo->all_info->each_eat_sem);
		exit (0);
	}
	sem_post(philo->all_info->each_eat_sem);
	return (0);
}

void	lock_last_eat(t_philo *p)
{
	sem_wait(p->all_info->last_eat_sem);
	p->last_eat = get_time();
	sem_post(p->all_info->last_eat_sem);
}

void	*to_check(t_philo *philo)
{
	while (true)
	{
		if (check_die(philo) == 1 || check_eat(philo) == 1)
			break ;
	}
	return (NULL);
}
