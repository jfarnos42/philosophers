/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:49:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/26 18:37:57 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <pthread.h>

# define TRUE 1
# define FALSE 0

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
	pthread_mutex_t	print;
	pthread_mutex_t pepsi;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
}					t_toggle_mutex;

typedef struct s_philosopher
{
	int				id;
	// char			*name;
	t_actions		*current_action;
	t_routine_data	routine;
}					t_philosopher;

typedef struct s_table
{
	t_philosopher	philosopher;
	t_toggle_mutex	*mutex;
	struct s_table	*next;
}					t_table;

/*### FUNCTIONS ###*/

/*	INITS	*/
int					init_dinner(t_table **table, t_routine_data routine);
t_routine_data		init_routine_data(char **argv);
void    init_fork_mutex(t_table **table);


/*	PARSER	*/
int					parser(int argc, char **argv);
int					check_for_digit(char *argv);

/*	PHILO	*/
void    philo_sleep(t_table *table);
void	philo_eat(t_table *table);
void	philo_think(t_table *table);

/*	THREADS	*/
pthread_t	*init_threads(t_table *table);
void    thread_join(pthread_t *threads_id, int n_philos);

/*	UTILS	*/
t_table				*philo_lstnew(t_routine_data routine, int id);
void				philo_lstadd_back(t_table **table, t_table *chair);
t_table				*philo_lstlast(t_table *lst);
void print_table(t_table *table);

#endif