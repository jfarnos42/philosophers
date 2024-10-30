/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:04:12 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 08:50:34 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

t_routine_data	init_routine_data(char **argv)
{
	t_routine_data	routines;

	if (argv[1] == 0 || argv[2] == 0 || argv[3] == 0 || argv[4] == 0)
		exit(EXIT_FAILURE);
	routines.n_philos = ft_atoi(argv[1]);
	routines.time_to_die = ft_atoi(argv[2]);
	routines.time_to_eat = ft_atoi(argv[3]);
	routines.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		routines.number_of_times = ft_atoi(argv[5]);
	else
		routines.number_of_times = 0;
	return (routines);
}