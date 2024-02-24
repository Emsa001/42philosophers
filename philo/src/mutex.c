/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:59:45 by escura            #+#    #+#             */
/*   Updated: 2024/02/24 23:15:34 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf(RED "Error: Failed to lock mutex\n");
		return (false);
	}
	return (true);
}

bool	mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf(RED "Error: Failed to unlock mutex\n");
		return (false);
	}
	return (true);
}

bool	mutex_init(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		printf(RED "Error: Failed to initialize mutex\n");
		return (false);
	}
	return (true);
}

bool	mutex_destroy(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
	{
		printf(RED "Error: Failed to destroy mutex\n");
		return (false);
	}
	return (true);
}
