/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:08 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/01 14:09:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	free_philo(t_philo *philo, t_helper *data,
		pthread_mutex_t *ini_mutex)
{
	if (philo)
		free(philo);
	if (data)
		free_param(data);
	if (ini_mutex)
		free(ini_mutex);
	exit_message("initialization error", 1);
}

static void	assign_philo(t_philo *philo, t_helper *data,
		pthread_mutex_t *ini_mutex, pthread_mutex_t *ini_print)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		philo[i].got_food = 0;
		philo[i].philo_id = i + 1;
		philo[i].mutex = ini_mutex;
		philo[i].print = ini_print;
		philo[i].get_data = data;
		i++;
	}
}

t_philo	*philo_init(t_philo *philo, t_helper *data)
{
	pthread_mutex_t	*ini_mutex;
	pthread_mutex_t	ini_print;
	int				i;

	i = 0;
	ini_mutex = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t))
			* data->num_philosophers);
	if (!ini_mutex)
		free_philo(philo, data, ini_mutex);
	while (i < data->num_philosophers)
		if (pthread_mutex_init(&ini_mutex[i++], NULL))
			free_philo(philo, data, ini_mutex);
	if (pthread_mutex_init(&ini_print, NULL))
		free_philo(philo, data, ini_mutex);
	assign_philo(philo, data, ini_mutex, &ini_print);
	return (philo);
}
