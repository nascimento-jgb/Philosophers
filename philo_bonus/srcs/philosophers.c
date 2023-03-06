/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:24:08 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/06 08:32:17 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*check_death(t_helper *philo)
{
	unsigned long	now;

	while (1)
	{
		now = get_time();
		if (philo->got_food == philo->ref->num_philo_must_eat)
			return (NULL);
		if ((now - philo->last_meal)
			>= (unsigned long long)philo->ref->time_to_die)
		{
			philo->death_flag = 1;
			sem_wait(philo->ref->action);
			printf("%lu %d died\n",
				(now - philo->ref->birth_time), philo->id);
			process_kill(philo->ref);
			destroy_sem(philo->ref);
			free(philo->ref->pid);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	philo_loop(long long time, t_philo *philo)
{
	long long	i;

	i = get_time();
	while (!(philo->death))
	{
		if ((long long)get_time() - i >= time)
			break ;
		usleep(50);
	}
}

void	philo_eat(t_helper *philo)
{
	sem_wait(philo->ref->fork);
	philo_msg(philo, "has taken a fork", philo->id);
	sem_wait(philo->ref->fork);
	philo_msg(philo, "has taken a fork", philo->id);
	philo_msg(philo, "is eating", philo->id);
	philo_loop(philo->ref->time_to_eat, philo->ref);
	philo->last_meal = get_time();
	sem_post(philo->ref->fork);
	sem_post(philo->ref->fork);
	philo->got_food++;
}

void	philo_alive(t_helper *philo)
{
	while (!philo->death_flag
		&& philo->got_food != philo->ref->num_philo_must_eat)
	{
		philo_eat(philo);
		philo_msg(philo, "is sleeping", philo->id);
		philo_loop(philo->ref->time_to_sleep, philo->ref);
		philo_msg(philo, "is thinking", philo->id);
	}
}

void	*philos_processes(t_philo *philos, int i)
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
