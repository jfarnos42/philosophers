/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 19:31:46 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/30 07:22:35 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int check_for_digit(char *argv)
{
    int i;

    i = 0;
    while(argv[i])
    {
        if (argv[i] == '-' || (argv[i] < '0' || argv[i] > '9'))
            return (FALSE);
        i++;
    }
    return(TRUE);
}

int	parser(int argc, char **argv)
{
	int i;
	
	if ((argc < 5 || argc > 6) || (!argv || argv[1] == 0))
		return (FALSE);
	i = 1;
	while (argv[i])
	{
		if (!check_for_digit(argv[i]))
            return (FALSE);
		i++;
	}
	return (TRUE);
}
