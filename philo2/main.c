/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/18 16:08:05 by svanmeen         ###   ########.fr       */
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
	if ((unsigned long)(philo->last_eat + data->ttd) <= gettime(data->start))
	{	
		if (!checkdeath(philo->data))
		{
			pthread_mutex_lock(&(data->deadlock));
			philo->data->dead = 1;
			pthread_mutex_unlock(&(data->deadlock));
			prompt(philo, "died");
		}
		return (1);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_r));
	if (checkdeath(philo->data) || isdead(philo, philo->data))
		return (1);
	prompt(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_l);
	if (!checkdeath(philo->data))
	{
		prompt(philo, "has taken a fork");
		prompt(philo, "is eating");
		philo->last_eat = gettime(philo->data->start);
		msleep(philo->data->tte);
	}
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(&(philo->fork_r));
	
	return (0);
}

int	sleeping(t_philo *philo)
{
	if (!checkdeath(philo->data))
	{
		prompt(philo, "is sleeping");
		msleep(philo->data->tts);
		return (0);
	}
	else
		return (1);
}

void	think(t_philo *philo)
{
	if (!isdead(philo, philo->data) && !checkdeath(philo->data))
		prompt(philo, "is thinking");
}

void	*life(void *arg)
{
	t_philo	*philo;

	philo = ((t_philo *)arg);
	philo->last_eat = (int )philo->data->start;
	while (philo->data->start > gettime(0))
		;
	while (!checkdeath(philo->data))
	{
		if (philo->philo % 2 != 0)
		{
			if (!isdead(philo, philo->data))
				eat(philo);
			if (!sleeping(philo))
				think(philo);
		}
		else
		{
			if (!sleeping(philo))
				think(philo);
			if (!isdead(philo, philo->data))
				eat(philo);
		}
	}
	return (NULL);
}

void	simulate(t_data	*info)
{
	t_philo		*curr;
	pthread_t	*tid;
	int			i;

	curr = *(info->philo);
	tid = malloc(sizeof(pthread_t) * info->nb_philo);
	info->start = gettime(0) + 200;
	i = 0;
	while (i < info->nb_philo && curr)
	{
		curr->data = info;
		pthread_create(&tid[i], NULL, &life, curr);
		if (curr->next)
			curr = curr->next;
		i++;
	}
	i = 0;
	while (i < info->nb_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	*info;

	if (argc != 5)
		return (1);
	info = fill_data(argv);
	simulate(info);
	return (0);
}
