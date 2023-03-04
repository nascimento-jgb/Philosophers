/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:22:24 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/04 11:15:59 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo_bonus.h"

int	exit_message(char *str, int flag)
{
	printf("%s\n", str);
	exit (flag);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		exit_message("Input error: Please insert num_philosophers \
		time_to_die time_to_eat time_to_sleep (ammount_of_meals)", 1);
	init_param(&philo, argv);
	routine(&philo);
	return (0);
}
