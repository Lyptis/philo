/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:01:20 by svanmeen          #+#    #+#             */
/*   Updated: 2023/09/05 17:26:25 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	single(t_philo *philo)
{
	prompt(philo, "has taken a fork");
	msleep(philo, philo->data->ttd);
	pthread_mutex_lock(&(philo->data->deadlock));
	philo->data->dead = 1;
	pthread_mutex_unlock(&(philo->data->deadlock));
	pthread_mutex_lock(&(philo->data->prompt));
	printf("%d %d %s\n", philo->data->ttd, philo->philo, "died");
	pthread_mutex_unlock(&(philo->data->prompt));
	return (1);
}

int	border(t_philo *philo)
{
	if (!philo->fork_l)
		return (single(philo));
	pthread_mutex_lock(&(philo->fork_r));
	prompt(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_l);
	prompt(philo, "has taken a fork");
	prompt(philo, "is eating");
	pthread_mutex_lock(&(philo->le_lock));
	philo->last_eat = gettime(philo->data->start);
	pthread_mutex_unlock(&(philo->le_lock));
	pthread_mutex_lock(&(philo->eats));
	philo->eat++;
	pthread_mutex_unlock(&(philo->eats));
	msleep(philo, philo->data->tte);
	pthread_mutex_unlock(&(philo->fork_r));
	pthread_mutex_unlock(philo->fork_l);
	return (0);
}
