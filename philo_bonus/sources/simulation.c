/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:32:34 by natamazy          #+#    #+#             */
/*   Updated: 2024/10/07 21:37:10 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	is_dead(t_philo *philo)
{
	int	i;

	sem_wait(philo->all_info->die_sem);
	i = *philo->is_dead;
	sem_post(philo->all_info->die_sem);
	return (i);
}

void	print_message(t_philo *philo, char *message)
{
	sem_wait(philo->all_info->write_sem);
	if (!is_dead(philo))
		printf("%lld %i %s", get_time(), philo->id + 1, message);
	sem_post(philo->all_info->write_sem);
}

void	*start_sim(t_philo *philo)
{
	pthread_create(&philo->thread, NULL,
		(void *)to_check, philo);
	lock_last_eat(philo);
	while (1)
	{
		sem_wait(philo->all_info->forks);
		print_message(philo, "has taken a fork\n");
		sem_wait(philo->all_info->forks);
		print_message(philo, "has taken a fork\n");
		print_message(philo, "is eating\n");
		my_sleep(philo->all_info->eat_time);
		lock_last_eat(philo);
		sem_wait(philo->all_info->each_eat_sem);
		philo->eat_counter++;
		sem_post(philo->all_info->each_eat_sem);
		sem_post(philo->all_info->forks);
		sem_post(philo->all_info->forks);
		print_message(philo, "is sleeping\n");
		my_sleep(philo->all_info->sleep_time);
		print_message(philo, "is thinking\n");
	}
	pthread_join(philo->thread, NULL);
	exit (0);
}

void	creating_forks(t_info *all_info)
{
	int	i;
	int	exit;

	i = -1;
	while (++i < all_info->philos_count)
	{
		all_info->philos[i].pid = fork();
		if (all_info->philos[i].pid == 0)
			start_sim(&all_info->philos[i]);
	}
	i = -1;
	while (++i <= all_info->philos_count)
	{
		waitpid(-1, &exit, 0);
		if (WEXITSTATUS(exit) > 0)
		{
			i = -1;
			while (++i < all_info->philos_count)
				kill(all_info->philos[i].pid, SIGKILL);
			break ;
		}
	}
	cl_unl(all_info);
	free(all_info->philos);
}
