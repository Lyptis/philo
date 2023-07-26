/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:31:49 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/26 11:24:07 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkeat(t_data *info)
{
	t_philo	*curr;

	curr = *(info->philo);
	while (curr)
	{
		if (info->nbe < 0 || curr->eat < info->nbe)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	checkdeath(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&(data->deadlock));
	dead = data->dead;
	pthread_mutex_unlock(&(data->deadlock));
	if (!dead)
		dead = checkeat(data);
	return (dead);
}

int	isdead(t_philo *philo, t_data *data)
{
	unsigned long	time;
	int	ttd;

	time = data->start;
	pthread_mutex_lock(&(philo->le_lock));
	ttd = philo->last_eat + data->ttd;
	pthread_mutex_unlock(&(philo->le_lock));
	if ((unsigned long)ttd <= gettime(data->start))
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
