/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:46:03 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/08 17:34:22 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

// typedef struct s_arg
// {
// 	int				val;
// 	pthread_mutex_t	lock;
// 	int				i;
// }					t_arg;

typedef struct s_philo
{
	int				philo;
	
	pthread_mutex_t	fork_r;
	pthread_mutex_t	*fork_l;
	struct t_data	*data;
}				t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				noe;
	struct timeval	*start;
}				t_data;



t_philo	*init_philo(t_data data);
//mutex_destroy
//arg parsing
int		ft_atoi(const char *str);
t_data	parse(char **strs);

#endif
