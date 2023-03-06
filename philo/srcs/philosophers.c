/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:08 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/06 08:17:45 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philo(t_philo *philo, t_helper *data,
		pthread_mutex_t *ini_mutex)
{
	if (philo)
		free(philo);
	if (data)
		free(data);
	if (ini_mutex)
		free(ini_mutex);
	exit_message("end of program", 1);
}

static void	assign_philo(t_philo *philo, t_helper *data,
		pthread_mutex_t *ini_mutex, pthread_mutex_t *ini_print)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].times_got_food = 0;
		philo[i].id = i + 1;
		philo[i].mutex = ini_mutex;
		philo[i].print = ini_print;
		philo[i].ref = data;
		i++;
	}
}

t_philo	*philo_init(t_helper *data, t_philo *philo)
{
	pthread_mutex_t	*ini_mutex;
	pthread_mutex_t	ini_print;
	int				i;

	i = 0;
	ini_mutex = (pthread_mutex_t *)malloc((sizeof(pthread_mutex_t))
			* data->num_philo);
	if (!ini_mutex || !philo)
		free_philo(philo, data, ini_mutex);
	while (i < data->num_philo)
		if (pthread_mutex_init(&ini_mutex[i++], NULL))
			free_philo(philo, data, ini_mutex);
	if (pthread_mutex_init(&ini_print, NULL))
		free_philo(philo, data, ini_mutex);
	assign_philo(philo, data, ini_mutex, &ini_print);
	return (philo);
}
