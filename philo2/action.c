/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:33:05 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/26 11:51:12 by svanmeen         ###   ########.fr       */
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


/*Check if change order of taking fork for the last or first change and remove 'lock-order-inversion'*/
int	eat(t_philo *philo)
{
	if (!philo->fork_l)
		return(single(philo));
	pthread_mutex_lock(philo->fork_l);
	prompt(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->fork_r));
	prompt(philo, "has taken a fork");
	prompt(philo, "is eating");
	pthread_mutex_lock(&(philo->le_lock));
	philo->last_eat = gettime(philo->data->start);
	pthread_mutex_unlock(&(philo->le_lock));
	philo->eat++;
	msleep(philo, philo->data->tte);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(&(philo->fork_r));
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
	pthread_mutex_lock(&(philo->le_lock));
	philo->last_eat = (int )philo->data->start;
	pthread_mutex_unlock(&(philo->le_lock));
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
