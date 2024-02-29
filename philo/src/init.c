/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:55:19 by escura            #+#    #+#             */
/*   Updated: 2024/02/29 20:08:03 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	validate_input(int nb, char **args)
{
	int	i;

	if (nb != 5 && nb != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (false);
	}
	i = 0;
	while (args[i])
	{
		if (!is_digit(args[i]))
		{
			printf("Error: Invalid input\n");
			return (false);
		}
		if(i == 4 && ft_atoi(args[i]) <= 0)
		{
			printf("Error: Num to eat must be greater than 0\n");
			return (false);
		}
		i++;
	}
	if (ft_atoi(args[0]) > 200)
	{
		printf("Error: Number of philosophers must be less than 200\n");
		return (false);
	}
	return (true);
}

bool	init_input(int nb, char **args, t_input *input)
{
	if (!validate_input(nb, args + 1))
		return (false);
	input->num_of_philos = ft_atoi(args[1]);
	input->time_to_die = ft_atoi(args[2]);
	input->time_to_eat = ft_atoi(args[3]);
	input->time_to_sleep = ft_atoi(args[4]);
	if (nb == 6)
		input->num_to_eat = ft_atoi(args[5]);
	else
		input->num_to_eat = -1;
	return (true);
}

void	init_philos(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	while (i < data->input->num_of_philos)
	{
		philo = &data->philos[i];
		philo->id = i + 1;
		philo->eating = false;
		philo->eaten = 0;
		philo->last_meal = 0;
		philo->start_time = get_time();
		philo->data = data;
		philo->r_fork = &data->forks[i];
		philo->l_fork = &data->forks[(i + 1) % data->input->num_of_philos];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, size_t num_of_philos)
{
	int	i;

	i = 0;
	while (i < (int)num_of_philos)
	{
		mutex_init(&forks[i]);
		i++;
	}
}

void	init_data(t_data *data, t_input input)
{
	data->dead = false;
	data->input = &input;
	mutex_init(&data->print_mutex);
	mutex_init(&data->dead_mutex);
	mutex_init(&data->eat_mutex);
	mutex_init(&data->waiter_mutex);
	init_forks(data->forks, input.num_of_philos);
}
