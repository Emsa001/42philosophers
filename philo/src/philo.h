/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:47:28 by escura            #+#    #+#             */
/*   Updated: 2024/03/02 19:06:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define GRAY "\033[90m"

typedef struct s_data	t_data;

typedef struct s_input
{
	size_t				num_of_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					num_to_eat;
}						t_input;

typedef struct s_philo
{
	pthread_t			thread;

	int					id;
	int					eaten;
	bool				eating;
	bool				slept;
	bool				thought;

	size_t				last_meal;
	size_t				start_time;

	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;

	t_data				*data;
}						t_philo;

typedef struct s_data
{
	bool				dead;
	bool	canStart;
	int routine_round;

	t_input				*input;

	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		waiter_mutex;

	pthread_mutex_t		forks[200];
	t_philo				philos[200];
}						t_data;

// init data
bool					init_input(int nb, char **args, t_input *input);
void					init_data(t_data *data, t_input input);
void					init_forks(pthread_mutex_t *forks,
							size_t num_of_philos);
void					init_philos(t_data *data);

// clean data
void					clean(t_data *data);

// do magic (start threads and routine)
bool					start_threads(t_data *data);
void					*routine(void *philo_ptr);

// magic utils (routine utils)
bool					dead_loop(t_philo *philo);
void					print_action(t_philo *philo, char *msg);

// monitor
void					*monitor_death(void *arg);
bool					check_if_eaten(t_data *data);

// mutex
bool					mutex_unlock(pthread_mutex_t *mutex);
bool					mutex_lock(pthread_mutex_t *mutex);
bool					mutex_init(pthread_mutex_t *mutex);
bool					mutex_destroy(pthread_mutex_t *mutex);

// utils
int						ft_atoi(char *str);
size_t					get_time(void);
int						ft_usleep(size_t time);
bool					is_digit(char *str);

#endif