/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:58:42 by escura            #+#    #+#             */
/*   Updated: 2024/02/29 20:30:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_data *data, t_philo *philo)
{
	size_t	last_meal;
	const size_t	time_to_die = data->input->time_to_die;
	const size_t	current_time = get_time();

	mutex_lock(&(data->eat_mutex));
	last_meal = philo->last_meal;
	if ((current_time - last_meal) >= time_to_die && !philo->eating)
	{
		mutex_unlock(&(data->eat_mutex));
		return (true);
	}
	mutex_unlock(&(data->eat_mutex));
	return (false);
}

bool	check_if_dead(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->input->num_of_philos)
	{
		if (is_dead(data, &data->philos[i]))
		{
			print_action(&data->philos[i], "died");
			mutex_lock(&data->dead_mutex);
			data->dead = true;
			mutex_unlock(&data->dead_mutex);
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_if_eaten(t_data *data)
{
	unsigned int	i;
	int	eaten;

	i = 0;
	eaten = 0;
	if(data->input->num_to_eat == -1)
		return (false);
	while (i < data->input->num_of_philos)
	{
		mutex_lock(&data->eat_mutex);
		if (data->philos[i].eaten >= data->input->num_to_eat)
			eaten++;
		mutex_unlock(&data->eat_mutex);
		i++;
	}
	if (eaten == (int)data->input->num_of_philos)
	{
		mutex_lock(&data->dead_mutex);
		data->dead = true;
		mutex_unlock(&data->dead_mutex);
		return (true);
	}
	return (false);
}

void	*monitor_death(void *arg)
{
	t_data			*data;
	unsigned int	i;

	data = (t_data *)arg;
	i = 0;
	ft_usleep(data->input->time_to_die);
	while (1)
	{
		if (check_if_dead(data) || check_if_eaten(data))
		{
			return (NULL);
		}
	}
	return (NULL);
}
