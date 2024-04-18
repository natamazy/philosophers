/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:46:31 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 20:39:46 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

long long	ft_atoi(const char *str, int i, int j, int flag)
{
	long long	res;

	res = 0;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] != '\0' && str[i] == '0')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		j++;
	}
	if (str[i] != '\0' || j > 10 || (res == 0 && flag > 0)
		|| res > INT_MAX || res < 0)
		return (-1);
	return (res);
}

int	validation(int argc, char *argv[], t_info *all_info)
{
	if (argc < 5 || argc > 6)
	{
		printf("\033[0;31mIncorect arguments count\n\033[0m");
		return (1);
	}
	all_info->philos_count = ft_atoi(argv[1], 0, 0, 0);
	all_info->die_time = ft_atoi(argv[2], 0, 0, 0);
	all_info->eat_time = ft_atoi(argv[3], 0, 0, 0);
	all_info->sleep_time = ft_atoi(argv[4], 0, 0, 0);
	if (argc == 6)
		all_info->must_eat = ft_atoi(argv[5], 0, 0, 0);
	else
		all_info->must_eat = -1;
	if (((all_info->philos_count <= 0 || all_info->philos_count > 200)
			|| all_info->die_time < 60 || all_info->eat_time < 60
			|| all_info->sleep_time < 60)
		|| (argc == 6 && all_info->must_eat == -1))
	{
		printf("\033[0;31mInsert correct numbers\n");
		printf("Minimum - 60ms for times\n");
		printf("Maximum - 200 for philosophers\n\033[0m");
		return (1);
	}
	return (0);
}
