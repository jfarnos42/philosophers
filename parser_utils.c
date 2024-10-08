/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:22:23 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/09 01:24:57 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int check_for_digit(char *argv)
{
    int i;

    i = -1;
    while(argv[++i])
    {
        if (argv[i] < '0' && argv[i] > '9')
            return (FALSE);
    }
    return(TRUE);
}
