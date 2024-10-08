/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:38 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/09 01:22:29 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"


int main(int argc, char **argv)
{
    t_table *table;
    
    if (!parser(argc, argv, &table))
        return (ERROR);
    
}

/*  
    parser
        errors
        init_struct
        add_nodes_to_table
    gestion de filosofofos
        start_threads
        start_monitoring_thread
        actions();
*/