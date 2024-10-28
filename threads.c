/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:53:53 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/26 18:45:30 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void thread_join(pthread_t *threads_id, int n_philos)
{
    int i;

    i = 0;
    if (!threads_id) // Check if threads_id is NULL at the beginning
    {
        printf("Error: threads_id is NULL\n");
        return;
    }

    while (i < n_philos) // Loop until all philosopher threads are joined
    {
        printf("Joining thread %i\n", i);
        if (pthread_join(threads_id[i], NULL) != 0) // Check return value of pthread_join
        {
            printf("Error: failed to join thread %i\n", i);
            return; // Exit if there's an error
        }
        i++;
    }
}

void    init_fork_mutex(t_table **table)
{
    t_table *head;
    
    head = *table;
    while ((*table) && (*table)->next)
    {
        if ((*table)->mutex)
            (*table)->mutex = (t_toggle_mutex *)malloc(sizeof(t_toggle_mutex) * 1);
        if ((*table)->next->mutex)
            (*table)->next->mutex = (t_toggle_mutex *)malloc(sizeof(t_toggle_mutex) * 1);
        
        pthread_mutex_init(&(*table)->mutex->r_fork, NULL);
        (*table)->next->mutex->l_fork = (*table)->mutex->r_fork;
        (*table) = (*table)->next;
    }
    //printf("donde estoy ==) %d\n", (head)->philosopher.id);   
    if (head && (*table) && head->mutex && (*table)->mutex)
        head->mutex->l_fork = (*table)->mutex->r_fork;
    *table = head;
}

void *thread_routine(void *args)
{
    t_table *table;

    table = (t_table *)args;
    philo_eat(table);
    sleep(5);
    philo_sleep(table);
    sleep(5);
    philo_think(table);
    return (NULL);
}

pthread_t	*init_threads(t_table *table)
{
	pthread_t	*threads_id;
	int			i;

	i = 0;
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
            //printf("ID del hilo: %lu\n", (unsigned long)threads_id[i-1]);
		}
        //wait_for_threads();
	}
	return (threads_id);
}
