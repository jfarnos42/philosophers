/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:53:53 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 07:47:57 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	thread_join(pthread_t *threads_id, int n_philos)
{
	int	i;

	i = 0;
	if (!threads_id)
		return ;
	while (i < n_philos)
	{
		printf("%i\n", i);
		if (pthread_join(threads_id[i], NULL) != 0)
			return ;
		i++;
	}
}

void	*thread_routine(void *args)
{
	t_table	*table;
	long	last_supper;

	table = (t_table *)args;
	last_supper = get_current_time();
	while (TRUE)
	{
        pthread_mutex_lock(&(table->mutex.l_fork));
        pthread_mutex_lock(&(table->mutex.r_fork));

		philo_eat(table);
		last_supper = get_current_time();
		pthread_mutex_unlock(&(table->mutex.l_fork));
		pthread_mutex_unlock(&(table->mutex.r_fork));
		if (is_philo_pepsi(table, last_supper))
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
