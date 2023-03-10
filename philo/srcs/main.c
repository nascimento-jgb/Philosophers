/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:22:24 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/10 08:44:18 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	input_error(void)
{
	printf("Input error - Please Insert:\n");
	printf("num philos - tm to die - tm to eat - tm to sleep (num of meals)\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_helper	*data;
	t_philo		*philo;
	pthread_t	*t_general;

	if (argc < 5 || argc > 6)
		return (input_error());
	data = (t_helper *)malloc(sizeof(t_helper));
	if (!param_atribution(data, argv))
		return (exit_message("initialization error", 1));
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (philo_init(data, philo))
		return (exit_message("initialization error", 1));
	t_general = (pthread_t *)malloc(sizeof(pthread_t) * data->num_philo);
	threads_creation(t_general, data, philo);
	exec_routine(data, philo);
	free(t_general);
	return (0);
}
