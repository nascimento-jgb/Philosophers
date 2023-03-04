/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:06:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/04 11:16:00 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"


static int	init_semaphores(t_philo *philo)
{
	sem_unlink("philo_forks");
	sem_unlink("philo_action");
	philo->fork = sem_open("philo_forks", O_CREAT, 0700, philo->num_philos);
	philo->action = sem_open("philo_action", O_CREAT, 0700, 1);
	if (philo->fork == SEM_FAILED || philo->action == SEM_FAILED)
	{
		destroy_sem(philo);
		return (0);
	}
	return (1);
}

static int	param_atribution(t_philo *philo, char **argv)
{
	philo->num_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->death = 0;
	philo->birth_time = get_time();
	if (philo->num_philos < 1 || philo->time_to_die < 1
		|| philo->time_to_eat < 1 || philo->time_to_sleep < 1)
		return (0);
	if (argv[5])
	{
		philo->num_philo_must_eat = ft_atoi(argv[5]);
		if (philo->num_philo_must_eat < 1)
			return (0);
	}
	else
		philo->num_philo_must_eat = -1;
	if (!init_semaphores(philo))
		return (0);
	return (1);
}

static int	param_check(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			if (ft_isdigit(argv[i][j++]))
				return (1);
		i++;
	}
	return (0);
}

void	*param_init(t_philo *philo, char **argv)
{
	if (!param_check(argv))
		exit_message("Invalid parameters", 1);
	if (!param_atribution(philo, argv))
	{
		free(philo);
		exit_message("Invalid input for data", 1);
	}
	return (0);
}
