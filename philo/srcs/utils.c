/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:02:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/10 08:41:40 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	long	res;

	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str < '0' || *str > '9')
		return (-1);
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *str++ - '0';
	if (*str)
		return (-1);
	return (res);
}

void	aux_ft_usleep(int time, int num_philos)
{
	if (num_philos >= 150)
		ft_usleep(time);
	else
		usleep(time);
}

int	exit_message(char *str, int flag)
{
	printf("%s\n", str);
	return (flag);
}

unsigned long	real_time(t_philo *philo)
{
	return (get_time() - philo->ref->time);
}

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->ref->num_philo)
		pthread_mutex_destroy(&philo->mutex[i++]);
}
