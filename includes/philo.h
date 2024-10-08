/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:49:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/09 01:02:50 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "includes/Libft/libft.h"
# include "includes/ft_printf/ft_printf.h"
# include <pthread.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct s_routine_data
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times;
}					t_routine_data;

typedef enum s_actions
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}					t_actions;

typedef struct s_toggle_mutex
{
	pthread_mutex_t	*print;
	pthread_mutex_t	*fork;
}					t_toggle_mutex;

typedef struct s_philosopher
{
	int				id;
	//need for forks var
	t_actions		*current_action;
	t_routine_data	*routine;
	t_toggle_mutex	*mutex;
}					t_philosopher;

typedef struct s_table
{
	t_philosopher	*philosopher;
	t_table			*next;
}					t_table;


/*### FUNCTIONS ###*/

/*	INITS	*/
t_routine_data	*init_routine_data(char **argv);

/*	PARSER	*/
int	parser(int argc, char **argv, t_table **table);
int check_for_digit(char *argv);

/*	PHILO	*/
void biov(void);

/*	UTILS	*/
t_table *philo_lstnew(t_routine_data *routine, int id);
void philo_lstadd_back(t_table **table, t_table *chair);

#endif