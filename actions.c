/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:19:58 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/26 18:49:17 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void    philo_sleep(t_table *table)
{
    (void)table;
    //table->philosopher.current_action = SLEEPING;
    //usleep(table->philosopher.routine.time_to_sleep);
}

void    philo_eat(t_table *table)
{
    (void)table;
    //table->philosopher.current_action = EATING;
    //usleep(table->philosopher.routine.time_to_eat);
}

void    philo_think(t_table *table)
{
    (void)table;
    //table->philosopher.current_action = THINKING;
    /*  DE MOMENTO NO HASE NA   */
}
