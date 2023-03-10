/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:54:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/10 08:40:29 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(int time)
{
	unsigned long	loop;

	loop = get_time() + (unsigned long)time;
	while (get_time() < loop)
		usleep(500);
}

void	threads_creation(pthread_t *t_general, t_helper *data, t_philo *philo)
{
	int	i;

	if (!t_general)
	{
		free(t_general);
		exit_message("Allocation error", 1);
	}
	i = -1;
	while (++i < data->num_philo)
	{
		pthread_create(&t_general[i], NULL, routine, philo + i);
		usleep(100);
	}
}

void	print_msg(t_philo *philo, unsigned long time, char *action)
{
	pthread_mutex_lock(philo->print);
	printf("%lu %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->print);
}

void	exec_routine(t_helper *data, t_philo *philo)
{
	int	j;

	j = 0;
	while (1)
	{
		if (philo[j].ref->completed_meals == philo[j].ref->num_philo)
		{
			destroy_mutex(philo);
			free_philo(philo, data, philo->mutex);
			return ;
		}
		if (get_time() - philo[j].last_meal > (unsigned long)data->time_to_die)
		{
			usleep(100);
			pthread_mutex_lock(philo[j].print);
			printf("%lu %d died\n", real_time(philo), philo->id);
			destroy_mutex(philo);
			free_philo(philo, data, philo->mutex);
			return ;
		}
		j = (j + 1) % data->num_philo;
		aux_ft_usleep(500, philo->ref->num_philo);
	}
}

void	*routine(void *routine)
{
	t_philo	*philo;

	philo = (t_philo *)routine;
	if (philo->id % 2 == 0)
		usleep(10);
	philo->last_meal = get_time();
	while (1)
	{
		pthread_mutex_lock(&philo->mutex[philo->id - 1]);
		print_msg(philo, real_time(philo), "has taken a fork");
		pthread_mutex_lock(&philo->mutex[philo->id % philo->ref->num_philo]);
		print_msg(philo, real_time(philo), "has taken a fork");
		print_msg(philo, real_time(philo), "is eating");
		philo->times_got_food++;
		if (philo->times_got_food == philo->ref->num_philo_must_eat)
			philo->ref->completed_meals++;
		ft_usleep(philo->ref->time_to_eat);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->mutex[philo->id - 1]);
		pthread_mutex_unlock(&philo->mutex[philo->id % philo->ref->num_philo]);
		print_msg(philo, real_time(philo), "is sleeping");
		ft_usleep(philo->ref->time_to_sleep);
		print_msg(philo, real_time(philo), "is thinking");
	}
	return (0);
}
