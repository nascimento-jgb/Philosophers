/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:06:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/02 15:42:14 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	printf("%s num philo\n", argv[1]);
	printf("%s time to die\n", argv[2]);
	printf("%s time to eat\n", argv[3]);
	printf("%s time to sleep\n", argv[4]);
	printf("%s must eat\n", argv[5]);
	data->completed_meals = 0;
	data->time = get_time();
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	printf("%lu time\n", data->time);
	printf("%d num philo\n", data->num_philo);
	printf("%d time to die\n", data->time_to_die);
	printf("%d time to eat\n", data->time_to_eat);
	printf("%d time to sleep\n", data->time_to_sleep);
	if (data->num_philo < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		return (0);
	if (argv[5])
	{
		data->num_philo_must_eat = ft_atoi(argv[5]);
		if (data->num_philo_must_eat < 1)
			return (0);
		printf("%d must eat\n", data->num_philo_must_eat);
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
			if (ft_isdigit(argv[i][j++]))
				return (1);
		i++;
	}
	return (0);
}

void	*param_init(t_helper *data, char **argv)
{
	if (!param_check(argv))
		exit_message("Invalid parameters", 1);
	if (!param_atribution(data, argv))
	{
		// printf("%lu time\n", data->time);
		// printf("%d num philo\n", data->num_philo);
		// printf("%d time to die\n", data->time_to_die);
		// printf("%d time to eat\n", data->time_to_die);
		// printf("%d time to sleep\n", data->time_to_die);
		// printf("%d must eeat\n", data->num_philo_must_eat);
		free(data);
		exit_message("Invalid input for data", 1);
	}
	return (0);
}
