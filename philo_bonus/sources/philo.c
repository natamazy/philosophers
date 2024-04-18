/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:36 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/18 20:39:40 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_info	all_info;

	if (validation(argc, argv, &all_info) == 1)
		return (1);
	if (initialization(&all_info) == 1)
		return (1);
	creating_forks(&all_info);
}
