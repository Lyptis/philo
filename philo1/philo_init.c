/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:24:48 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/30 13:04:27 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_philo	*init_philo(t_data data)
{
	t_philo	*philo;
	t_philo	*curr;
	t_philo	*prev;
	int		i;

	philo = malloc(data.nb_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < data.nb_philo)
	{
		philo[i].philo = i + 1;
		philo[i].data = &data;
		i++;
	}
	return (philo);
}

void	set_mutex(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&(data->philo[i].fork_l), NULL);
		i++;
	}
}
