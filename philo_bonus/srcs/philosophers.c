/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:08 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/03 15:45:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

void	check_death()

void	philo_sleep()


void	philo_eat()

void	philo_alive(t_helper *philo)
{
	while (!philo->death_flag &&
			philo->got_food != philo->ref->num_philo_must_eat)
	{
		philo_eat(philo);
		philo_msg();
		philo_sleep(philo->ref->time_to_sleep, philo->ref);
		philo_msg();
	}

}

void	*philo_processes(t_philo *philos, int i)
{
	t_helper	philo;

	philo.ref = philos;
	philo.id = i + 1;
	philo.death_flag = 0;
	philo.got_food = 0;
	philo.last_meal = get_time();
	pthread_create(philo.philo_thread, NULL, (void *)check_death, &philo);
	philo_alive(&philo);
	pthread_detach(*philo.philo_thread);
	return (NULL);
}
