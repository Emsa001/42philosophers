/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:14:52 by escura            #+#    #+#             */
/*   Updated: 2024/02/29 20:32:12 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *msg)
{
	const size_t	time = get_time() - philo->start_time;

	// if (check_if_eaten(philo->data))
	// 	return ;
	if (!mutex_lock(&philo->data->print_mutex))
		return ;
	if (!dead_loop(philo) && !check_if_eaten(philo->data))
		printf("%5zu" MAGENTA " %d %s\n" RESET, time, philo->id, msg);
	mutex_unlock(&philo->data->print_mutex);
}

bool	dead_loop(t_philo *philo)
{
	pthread_mutex_t	*dead_mutex;
	bool			is_dead;

	dead_mutex = &philo->data->dead_mutex;
	if (!mutex_lock(dead_mutex))
		return (true);
	is_dead = philo->data->dead;
	mutex_unlock(dead_mutex);
	return (is_dead);
}
