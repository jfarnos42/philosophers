/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:53:53 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 05:37:03 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	thread_join(pthread_t *threads_id, int n_philos)
{
	int	i;

	i = 0;
	if (!threads_id) // Check if threads_id is NULL at the beginning
	{
		printf("Error: threads_id is NULL\n");
		return ;
	}
	while (i < n_philos) // Loop until all philosopher threads are joined
	{
		printf("Joining thread %i\n", i);
		if (pthread_join(threads_id[i], NULL) != 0)
			// Check return value of pthread_join
		{
			printf("Error: failed to join thread %i\n", i);
			return ; // Exit if there's an error
		}
		i++;
	}
}

void	*thread_routine(void *args)
{
	t_table	*table;
	long	the_last_supper;

	table = (t_table *)args;
	the_last_supper = get_current_time();
	while (TRUE)
	{
        pthread_mutex_lock(&(table->mutex.l_fork));
        pthread_mutex_lock(&(table->mutex.r_fork));

		philo_eat(table);
		the_last_supper = get_current_time();
		pthread_mutex_unlock(&(table->mutex.l_fork));
		pthread_mutex_unlock(&(table->mutex.r_fork));
		if (is_philo_pepsi(table, the_last_supper))
			break ;
		philo_sleep(table);
		philo_think(table);
	}
	return (NULL);
}

pthread_t	*init_threads(t_table *table)
{
    t_table     *head;
	pthread_t	*threads_id;
	int			i;

	i = 0;
    head = table;
	threads_id = (pthread_t *)malloc(sizeof(pthread_t)
			* table->philosopher.routine.n_philos);
	if (!threads_id | !table)
		return (NULL);
	else
	{
		while (table->next)
		{
			pthread_create(&threads_id[i++], NULL, thread_routine, table);
			table = table->next;
			// printf("ID del hilo: %lu\n", (unsigned long)threads_id[i-1]);
		}
		usleep(500);
	}
    table = head;
	return (threads_id);
}
