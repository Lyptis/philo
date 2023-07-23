/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:33:05 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/23 12:46:52 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (!isdead(philo, philo->data))
	{
		pthread_mutex_lock(philo->fork_l);
		prompt(philo, "has taken a fork");
	}
	if (!isdead(philo, philo->data))
	{
		pthread_mutex_lock(&(philo->fork_r));
		prompt(philo, "has taken a fork");
	}
	prompt(philo, "is eating");
	philo->last_eat = gettime(philo->data->start);
	msleep(philo, philo->data->tte);
	pthread_mutex_unlock(&(philo->fork_r));
	pthread_mutex_unlock(philo->fork_l);
	return (0);
}

int	sleeping(t_philo *philo)
{
	prompt(philo, "is sleeping");
	msleep(philo, philo->data->tts);
	return (0);
}

void	think(t_philo *philo)
{
	prompt(philo, "is thinking");
}

void	*life(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	philo->last_eat = (int )philo->data->start;
	while (philo->data->start > gettime(0))
		;
	if (philo->philo % 2 == 0)
	{
		prompt(philo, "is thinking");
		msleep(philo, philo->data->tte);
	}
	while (!checkdeath(philo->data))
	{
		eat(philo);
		sleeping(philo);
		think(philo);
	}
	return (NULL);
}
