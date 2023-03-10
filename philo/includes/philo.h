/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:37:01 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/10 08:41:22 by jonascim         ###   ########.fr       */
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
	int				num_philo;
	int				completed_meals;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philo_must_eat;
	unsigned long	time;
}	t_helper;

typedef struct s_philo
{
	int				times_got_food;
	int				id;
	int				eat_count;
	unsigned long	last_meal;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print;
	t_helper		*ref;
}	t_philo;

// PARAMETERS
int				param_atribution(t_helper *data, char **argv);
unsigned long	get_time(void);
int				input_error(void);

//PHILO
int				philo_init(t_helper *data, t_philo *philo);
int				free_philo(t_philo *philo, t_helper *data,
					pthread_mutex_t *ini_mutex);

//ROUTINE
void			threads_creation(pthread_t *t_general, t_helper *data,
					t_philo *philo);
void			*routine(void *routine);
void			exec_routine(t_helper *data, t_philo *philo);
void			print_msg(t_philo *philo, unsigned long time, char *action);
void			ft_usleep(int time);

// UTILS
unsigned long	real_time(t_philo *philo);
void			destroy_mutex(t_philo *philo);
int				exit_message(char *str, int flag);
int				ft_atoi(char *str);
void			aux_ft_usleep(int time, int num_philo);

#endif
