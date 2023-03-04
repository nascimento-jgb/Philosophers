/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:54:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/04 11:16:01 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

static void	create_processes(t_philo *philo, int *pid)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			philos_processes(philo, i);
		i++;
	}
}

void	process_kill(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philos)
	{
		kill(philo->pid[i], SIGINT);
		i++;
	}
}

void	destroy_sem(t_philo *philo)
{
	sem_close(philo->fork);
	sem_close(philo->action);
	sem_unlink("philo_fork");
	sem_unlink("philo_action");
}

void	*routine(t_philo *philo)
{
	int	i;

	i = 0;
	philo->pid = malloc(sizeof(int) * philo->num_philos);
	if (!philo->pid)
		exit_message("Creation of processes failed.", 1);
	crete_processes(philo, philo->pid);
	while (i < philo->num_philos)
		waitpid(philo->pid[i++], 0, 0);
	process_kill(philo);
	destroy_sem(philo);
	return (0);
}
