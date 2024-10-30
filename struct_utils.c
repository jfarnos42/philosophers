/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:03:11 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 05:07:42 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void philo_free_table(t_table **table)
{
    t_table *temp;
    
    while (*table)
    {
        temp = (*table)->next;
        pthread_mutex_destroy(&(*table)->mutex.r_fork);
        free(*table);
        *table = temp;
    }
}


t_table	*philo_lstnew(t_routine_data routine, int id)
{
	t_table	*chair;

	chair = (t_table *)malloc(sizeof(t_table) * 1);
	if (!chair)
		return (NULL);
	chair->philosopher.routine = routine;
	chair->philosopher.id = id;
	//chair->philosopher.name = philo_baptizer();
	chair->next = NULL;
	return (chair);
}

void	philo_lstadd_back(t_table **table, t_table *chair)
{
	t_table	*aux_table;

	if (chair)
	{
		aux_table = philo_lstlast(*table);
		if (!aux_table)
			*table = chair;
		else
			aux_table->next = chair;
	}
}

t_table	*philo_lstlast(t_table *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void print_table(t_table *table)
{
    if (table)
    {
        while(table->next)
        {
            printf("Philo ID: %i\n", table->philosopher.id);
            printf("    time_to_die: %i\n", table->philosopher.routine.time_to_die);
            printf("    time_to_eat: %i\n", table->philosopher.routine.time_to_eat);
            printf("    time_to_sleep: %i\n", table->philosopher.routine.time_to_sleep);
            table = table->next;
        }
    }
}
