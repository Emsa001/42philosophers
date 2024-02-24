/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:00:01 by escura            #+#    #+#             */
/*   Updated: 2024/02/24 23:11:47 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->input->num_of_philos)
	{
		mutex_destroy(&data->forks[i]);
		i++;
	}
	mutex_destroy(&data->print_mutex);
	mutex_destroy(&data->dead_mutex);
	mutex_destroy(&data->eat_mutex);
	mutex_destroy(&data->waiter_mutex);
}
