/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:06:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/10 07:59:44 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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

int	param_atribution(t_helper *data, char **argv)
{
	if (!data)
		return (0);
	if (param_check(argv))
		return (0);
	data->completed_meals = 0;
	data->time = get_time();
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->num_philo <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (0);
	if (argv[5])
	{
		data->num_philo_must_eat = ft_atoi(argv[5]);
		if (data->num_philo_must_eat <= 0)
			return (0);
	}
	else
		data->num_philo_must_eat = -1;
	return (1);
}
