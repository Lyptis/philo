/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/17 15:34:00 by svanmeen         ###   ########.fr       */
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

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_r));
	prompt(philo, "has taken a fork");
	if (!philo->fork_l)
	{
		msleep(philo->data->ttd);
		return (1);
	}
	pthread_mutex_lock(philo->fork_l);
	if (!checkdeath(philo->data))
	{
		prompt(philo, "has taken a fork");
		prompt(philo, "is eating");
		msleep(philo->data->tte);
	}
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(&(philo->fork_r));
	philo->last_eat = gettime(philo->data->start);
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
	if ((unsigned long)(philo->last_eat + philo->data->ttd) < gettime(philo->data->start))
	{
		pthread_mutex_lock(&(philo->data->deadlock));
		philo->data->dead = 1;
		pthread_mutex_unlock(&(philo->data->deadlock));
		prompt(philo, "died");
	}
	else
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
			eat(philo);
			if (!sleeping(philo))
				think(philo);
		}
		else
		{
			if (!sleeping(philo))
				think(philo);
			if (!checkdeath(philo->data))
				eat(philo);
		}
	}
	// printf("philo[%d] {\nstart :%lu\ncurrent :%lu\n}\n", philo->philo, philo->data->start, gettime(0));
	// printf("elapsed : %lu, philo[%d] - DONE\n", gettime(philo->data->start), philo->philo);
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
