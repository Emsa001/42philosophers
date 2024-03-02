/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:51:57 by escura            #+#    #+#             */
/*   Updated: 2024/03/02 15:12:35 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int nb, char **args)
{
	t_data	data;
	t_input	input;

	if (init_input(nb, args, &input) == false)
		return (1);
	init_data(&data, input);
	init_philos(&data);
	if (start_threads(&data) == false)
		return (1);
	clean(&data);
	return (0);
}
