/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:40:38 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 07:18:38 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	init_dinner(t_table **table, t_routine_data routine)
{
	int		i;
	t_table	*chair;

	i = 0;
	while (i <= routine.n_philos)
	{
		chair = philo_lstnew(routine, i);
		if (!chair)
			return (FALSE);
		philo_lstadd_back(table, chair);
		i++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_table			*table;
	t_routine_data	routine;
	pthread_t		*threads_id;

	if (!parser(argc, argv))
		return (FALSE);
	routine = init_routine_data(argv);
	if (!init_dinner(&table, routine))
		return (FALSE);
	// print_table(table);
	init_fork_mutex(&table);
	threads_id = init_threads(table);
	if (!threads_id)
		return (FALSE);
	thread_join(threads_id, table->philosopher.routine.n_philos);
	free(threads_id);
	philo_free_table(&table);
	return (TRUE);
}

/*
	parser
		errors (done)
		init_struct (done)
		add_nodes_to_table (done)
	gestion de filosofofos (WIP)
		start_monitoring_thread (x)
		start_threads (x)
		actions();
*/