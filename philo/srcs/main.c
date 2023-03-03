/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:22:24 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/03 11:07:47 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	main(int argc, char **argv)
{
	t_helper	*data;
	t_philo		*philo;
	pthread_t	*t_general;

	if (argc != 6)
		exit_message("Input error: Please insert num_philosophers \
		time_to_die time_to_eat time_to_sleep (ammount_of_meals)", 1);
	data = (t_helper *)malloc(sizeof(t_helper));
	param_init(data, argv);
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	philo_init(data, philo);
	t_general = (pthread_t *)malloc(sizeof(pthread_t) * data->num_philo);
	threads_creation(t_general, data, philo);
	exec_routine(data, philo);
	free(t_general);
	return (0);
}
