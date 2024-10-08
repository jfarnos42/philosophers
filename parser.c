/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:31:46 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/09 01:21:48 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void    gemma_the_maître(t_table **table, t_routine_data *routine)
{
    int i;

    while(i)
}

int	parser(int argc, char **argv, t_table **table)
{
    t_routine_data *routine;

	if ((argc < 4 || argc > 5) || !argv)
		return (ERROR);
	while (argc != 1)
	{
		if (!check_for_digit(argv[argc]));
            return (ERROR);
		argc--;
	}
	routine = init_routine_data(argv);
    gemma_the_maître(table, routine);
	return (TRUE);
}
