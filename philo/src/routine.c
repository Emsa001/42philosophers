/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:55:29 by escura            #+#    #+#             */
/*   Updated: 2024/03/02 16:08:57 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	take_forks(t_philo *philo)
{
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;

	fork1 = philo->r_fork;
	fork2 = philo->l_fork;
	mutex_lock(fork1);
	print_action(philo, GRAY "has taken a fork");
	if (philo->data->input->num_of_philos == 1)
	{
		ft_usleep(philo->data->input->time_to_die);
		mutex_unlock(fork1);
		return (false);
	}
	mutex_lock(fork2);
	print_action(philo, GRAY "has taken a fork");
	return (true);
}

// bool take_forks(t_philo *philo)
// {
//     if (philo->data->input->num_of_philos == 1)
//     {
//         mutex_lock(philo->r_fork);
//         print_action(philo, GRAY "has taken a fork");
//         ft_usleep(philo->data->input->time_to_die);
//         mutex_unlock(philo->r_fork);
//         return (false);
//     }

//     if (philo->id % 2 == 0) {
//         mutex_lock(philo->r_fork);
// 		print_action(philo, GRAY "has taken a fork");
//         mutex_lock(philo->l_fork);
// 		print_action(philo, GRAY "has taken a fork");
//     } else {
//         mutex_lock(philo->l_fork);
// 		print_action(philo, GRAY "has taken a fork");
//         mutex_lock(philo->r_fork);
// 		print_action(philo, GRAY "has taken a fork");
//     }
//     return (true);
// }

void	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return ;
	philo->eating = true;
	print_action(philo, GREEN "is eating");
	mutex_lock(&philo->data->eat_mutex);
	philo->eaten++;
	philo->last_meal = get_time();
	mutex_unlock(&philo->data->eat_mutex);
	ft_usleep(philo->data->input->time_to_eat);
	philo->eating = false;
	mutex_unlock(philo->l_fork);
	mutex_unlock(philo->r_fork);
}

void	sleeep(t_philo *philo)
{
	print_action(philo, YELLOW "is sleeping");
	ft_usleep(philo->data->input->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_action(philo, CYAN "is thinking");
}

void	*routine(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (dead_loop(philo) == false)
	{
		if (philo->data->input->num_to_eat == -1
			|| philo->eaten < philo->data->input->num_to_eat)
		{
			eat(philo);
			if (philo->data->input->num_of_philos == 1)
				break ;
			sleeep(philo);
			think(philo);
		}
	}
	return (NULL);
}
