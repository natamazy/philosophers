/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natamazy <natamazy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:20:36 by natamazy          #+#    #+#             */
/*   Updated: 2024/04/16 16:02:13 by natamazy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_info	all_info;

	if (validation(argc, argv, &all_info) > 0)
		return (1);
	if (initialization(&all_info, 0) == 1)
		return (1);
}
