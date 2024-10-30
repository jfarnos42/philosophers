/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:19:58 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 07:39:53 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_eat(t_table *table)
{
	long	start_time;

	start_time = get_current_time();
	printf("%ld %d has taken right fork\n", start_time, table->philosopher.id);
	printf("%ld %d has taken left fork\n", start_time, table->philosopher.id);
	printf("%ld %d is eating\n", start_time, table->philosopher.id);
	usleep(table->philosopher.routine.time_to_eat * 1000);
}

void	philo_sleep(t_table *table)
{
	long	start_time;

	start_time = get_current_time();
	printf("%ld %d is sleeping\n", start_time, table->philosopher.id);
	usleep(table->philosopher.routine.time_to_sleep * 1000);
}

void	philo_think(t_table *table)
{
	long	start_time;

	start_time = get_current_time();
	printf("%ld %d is thinking\n", start_time, table->philosopher.id);
}

int	is_philo_pepsi(t_table *table, long last_supper)
{
	long	current_time;

	current_time = get_current_time();
	if ((current_time - last_supper) >= table->philosopher.routine.time_to_die)
	{
		printf("%ld %d died\n", current_time, table->philosopher.id);
		return (TRUE);
	}
	return (FALSE);
}
