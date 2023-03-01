/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:37:01 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/01 14:11:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


typedef struct s_helper
{
	int				num_philosophers;
	int				num_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philo_must_eat;
	unsigned long	time;
}	t_helper;

typedef struct s_philo
{
	int				got_food;
	int				philo_id;
	int				eat_count;
	unsigned long	last_meal;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	t_helper		*get_data;
}	t_philo;

// PARAMETERS
t_helper		*param_init(t_helper *data, char **argv);
unsigned long	get_time(void);
void			free_param(t_helper *data);

//PHILO
t_philo			*philo_init(t_philo *philo, t_helper *data);

//ROUTINE
void			threads_creation(pthread_t t_general, t_helper *data,
					t_philo *philo);

// UTILS
void			destroy_mutex(t_philo *philo);
void			exit_message(char *str, int flag);
void			free_param(t_helper *data);
int				ft_atoi(char *str);
int				ft_isdigit(int c);

#endif
