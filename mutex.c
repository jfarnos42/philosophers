/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 05:33:40 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 05:43:02 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void	init_fork_mutex(t_table **table)
{
	t_table	*head;

	head = *table;
	while ((*table) && (*table)->next)
	{
		if (pthread_mutex_init(&(*table)->mutex.r_fork, NULL) != 0)
        {
            printf("Error Mutex INIT");
            exit(EXIT_FAILURE);
        }
		(*table)->next->mutex.l_fork = (*table)->mutex.r_fork;
		*table = (*table)->next;
	}
	if (head && (*table))
		head->mutex.l_fork = (*table)->mutex.r_fork;
	*table = head;
}
