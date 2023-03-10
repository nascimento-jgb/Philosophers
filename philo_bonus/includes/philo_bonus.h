/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 08:37:01 by jonascim          #+#    #+#             */
/*   Updated: 2023/03/10 09:19:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdint.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_helper
{
	int				id;
	int				got_food;
	int				death_flag;
	unsigned long	last_meal;
	pthread_t		*philo_thread;
	struct s_philo	*ref;
}	t_helper;

typedef struct s_philo
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philo_must_eat;
	int				death;
	int				*pid;
	unsigned long	birth_time;
	sem_t			*fork;
	sem_t			*action;
	t_helper		*ref;
}	t_philo;

// MAIN
int				exit_message(char *str, int flag);

// PARAMETERS
void			*param_init(t_philo *philo, char **argv);
unsigned long	get_time(void);

//PHILO
void			*philos_processes(t_philo *philos, int i);
void			philo_alive(t_helper *philo);
void			philo_eat(t_helper *philo);
void			philo_loop(long long time, t_philo *philo);
void			*check_death(t_helper *philo);

//ROUTINE
int				*routine(t_philo *philo);
void			destroy_sem(t_philo *philo);
void			process_kill(t_philo *philo);

// UTILS
int				ft_atoi(char *str);
int				ft_isdigit(int c);
unsigned long	get_time(void);
void			philo_msg(t_helper *philo, char *str, int id);
void			ft_usleep(int time, int num_philos);

#endif
