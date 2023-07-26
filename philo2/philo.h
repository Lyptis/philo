/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:46:03 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/25 17:24:42 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

struct	s_data;

typedef struct s_philo
{
	int				philo;

	pthread_mutex_t	fork_r;
	pthread_mutex_t	*fork_l;
	int				last_eat;
	int				eat;
	struct s_philo	*next;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	t_philo			**philo;
	pthread_t		*tid;
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nbe;
	pthread_mutex_t	deadlock;
	pthread_mutex_t	prompt;
	int				dead;
	unsigned long	start;
}				t_data;

/*****Initialize*****/
t_data			*fill_data(char **argv);
t_philo			**bornphilo(int nb_philo);

/***DeathCheckers****/
int				checkdeath(t_data *data);
int				isdead(t_philo *philo, t_data *data);

/*****PhiloLife******/
int				eat(t_philo *philo);
int				sleeping(t_philo *philo);
void			think(t_philo *philo);
void			*life(void *arg);

/********Time********/
void			msleep(t_philo *philo, unsigned long ms);
unsigned long	gettime(unsigned long start);

/*******Prompt*******/
void			prompt(t_philo *philo, char *str);

/********Utils*******/
int				ft_atoi(const char *str);

#endif
