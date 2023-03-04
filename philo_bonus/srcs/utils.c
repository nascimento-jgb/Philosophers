/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 09:02:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/04 12:03:23 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	ft_atoi(char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *str++ - '0';
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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

void	philo_msg(t_helper *philo, char *str, int id)
{
	sem_wait(philo->ref->action);
	if (!(philo->ref->death))
	{
		printf("%lums\t", get_time() - philo->ref->birth_time);
		printf("philo %d ", id);
		printf("%s\n", str);
	}
	sem_post(philo->ref->action);
}
