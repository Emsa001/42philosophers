/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:00:11 by escura            #+#    #+#             */
/*   Updated: 2024/02/24 23:04:36 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	create_threads_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input->num_of_philos)
	{
		if (pthread_create(&(data->philos[i].thread), NULL, &routine,
				(void *)&data->philos[i]) != 0)
		{
			printf(RED "Error: Failed to create philo thread\n");
			return (clean(data), false);
		}
		usleep(100);
		i++;
	}
	return (true);
}

static bool	join_threads_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input->num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
		{
			printf(RED "Error: Failed to join philo thread\n");
			return (clean(data), false);
		}
		i++;
	}
	return (true);
}

bool	start_threads(t_data *data)
{
	pthread_t	monitor;
	int			i;

	if (pthread_create(&monitor, NULL, &monitor_death, (void *)data) != 0)
	{
		printf(RED "Error: Failed to create monitor thread\n");
		return (clean(data), false);
	}
	if (create_threads_philos(data) == false)
		return (false);
	if (pthread_join(monitor, NULL) != 0)
	{
		printf(RED "Error: Failed to join monitor thread\n");
		return (clean(data), false);
	}
	if (join_threads_philos(data) == false)
		return (false);
	return (true);
}
