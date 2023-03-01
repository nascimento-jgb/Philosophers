/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:54:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/01 14:13:30 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threads_creation(pthread_t t_general, t_helper *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philosophers)
	{
		pthread_create(&t_general[i], NULL, routine, philo + i);
		usleep(100);
	}
}

void	exec_routine()
{

}

void	routine()
{

}
