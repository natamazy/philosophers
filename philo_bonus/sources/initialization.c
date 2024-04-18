/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:58:01 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 20:39:39 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	open_sem(t_info *all_info)
{
	all_info->each_eat_sem = sem_open(SEMEAT, O_CREAT, 0777, 1);
	all_info->last_eat_sem = sem_open(SEMLASTEAT, O_CREAT, 0777, 1);
	all_info->forks = sem_open(SEMFORKS, O_CREAT, 0777, all_info->philos_count);
	all_info->write_sem = sem_open(SEMWRITE, O_CREAT, 0777, 1);
	all_info->die_sem = sem_open(SEMDIE, O_CREAT, 0777, 1);
	if (all_info->each_eat_sem == SEM_FAILED || all_info->die_sem == SEM_FAILED
		|| all_info->forks == SEM_FAILED || all_info->write_sem == SEM_FAILED
		|| all_info->last_eat_sem == SEM_FAILED)
		return (1);
	return (0);
}

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
		i++;
	}
}

void	cl_unl(t_info *all_info)
{
	sem_close(all_info->each_eat_sem);
	sem_close(all_info->last_eat_sem);
	sem_close(all_info->forks);
	sem_close(all_info->write_sem);
	sem_close(all_info->die_sem);
	sem_unlink(SEMEAT);
	sem_unlink(SEMLASTEAT);
	sem_unlink(SEMFORKS);
	sem_unlink(SEMWRITE);
	sem_unlink(SEMDIE);
}

int	initialization(t_info *all_info)
{
	all_info->is_dead = 0;
	all_info->philos = (t_philo *)
		malloc(sizeof(t_philo) * all_info->philos_count);
	if (!all_info->philos)
		return (1);
	init_philos(all_info);
	cl_unl(all_info);
	if (open_sem(all_info) == 1)
	{
		free(all_info->philos);
		return (1);
	}
	return (0);
}
