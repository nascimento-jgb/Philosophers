/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:06:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/01 13:00:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_param(t_helper *data)
{
	if (data->num_philosophers)
	{
		free(data->num_philosophers);
		free(data->num_forks);
	}
	if (data->time_to_die)
		free(data->time_to_die);
	if (data->time_to_eat)
		free(data->time_to_eat);
	if (data->time_to_sleep)
		free(data->time_to_sleep);
	if (data->num_philo_must_eat)
		free(data->num_philo_must_eat);
	free(data);
}

unsigned long	get_time(void)
{
	struct timeval	time;
	unsigned long	total;
	unsigned long	sec;
	unsigned long	usec;

	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000);
	usec = (time.tv_usec / 1000);
	total = sec + usec;
	return (total);
}

static int	param_atribution(t_helper *data, char **argv)
{
	data->num_philosophers = ft_atoi(argv[1]);
	data->num_forks = data->num_philosophers;
	data->time = get_time();
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->num_philosophers < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		return (0);
	if (argv[5])
	{
		data->num_philo_must_eat = ft_atoi(argv[5]);
		if (data->num_philo_must_eat < 1)
			return (0);
	}
	else
		data->num_philo_must_eat = -1;
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
			if (!ft_isdigit(argv[i][j++]))
				return (0);
		i++;
	}
	return (1);
}

t_helper	*param_init(t_helper *data, char **argv)
{
	if (!param_check(argv))
		exit_message("Invalid parameters", 1);
	if (!param_atribution(data, argv))
	{
		free_param(data);
		exit_message("Invalid input for data", 1);
	}
	return (data);
}
