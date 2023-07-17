/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:46:03 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/08 18:27:47 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				philo;

	pthread_mutex_t	fork_r;
	pthread_mutex_t	*fork_l;
	struct s_philo	*next;
	struct t_data	*data;
}				t_philo;

typedef struct s_data
{
	t_philo			**philo;
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nbe;
	unsigned long	*start;
}				t_data;

/*****Initialize*****/
t_data			*fill_data(int argc, char **argv);
t_philo			**bornphilo(int nb_philo);

/********Time********/
void			msleep(unsigned long ms);
unsigned long	gettime(unsigned long start);

#endif
