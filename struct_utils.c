/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:03:11 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/09 01:04:29 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

t_table *philo_lstnew(t_routine_data *routine, int id)
{
    t_table *chair;

    chair = (t_table *)malloc(sizeof(t_table) * 1);
    if (!chair)
        return (NULL);
    chair->philosopher->routine = routine;
    chair->philosopher->id = id;
//  chair->philosopher->fork = FALSE;
    chair->next = NULL;
    return (chair);      
}

void philo_lstadd_back(t_table **table, t_table *chair)
{
	t_table *aux_table;

	if (chair)
	{
		aux_table = ft_lstlast(table);
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
