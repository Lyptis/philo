/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:31:49 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/23 12:49:20 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkdeath(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&(data->deadlock));
	dead = data->dead;
	pthread_mutex_unlock(&(data->deadlock));
	return (dead);
}

int	isdead(t_philo *philo, t_data *data)
{
	unsigned long	time;

	time = philo->data->start;
	if ((unsigned long)(philo->last_eat + data->ttd) <= gettime(data->start))
	{	
		if (!checkdeath(philo->data))
		{
			pthread_mutex_lock(&(data->deadlock));
			philo->data->dead = 1;
			pthread_mutex_unlock(&(data->deadlock));
			pthread_mutex_lock(&(philo->data->prompt));
			printf("%lu %d %s\n", gettime(time), philo->philo, "died");
			pthread_mutex_unlock(&(philo->data->prompt));
		}
		return (1);
	}
	return (0);
}
