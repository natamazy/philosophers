/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:17:33 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 15:27:35 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	static long long	start;
	struct timeval		time;

	if (start == 0)
	{
		gettimeofday(&time, NULL);
		start = (time.tv_usec / 1000 + time.tv_sec * 1000);
	}
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - start);
}

void	my_sleep(long long time1)
{
	long long	time2;

	time2 = get_time();
	while (get_time() - time2 <= time1)
		usleep(500);
}
