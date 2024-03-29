/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bornphilo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:51:06 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/27 14:56:04 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*get_last(t_philo **philos)
{
	t_philo	*curr;

	if (!*philos)
		return (NULL);
	curr = *philos;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

static t_philo	*create_philo(int i)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->philo = i + 1;
	pthread_mutex_init(&(new->fork_r), NULL);
	new->fork_l = 0;
	pthread_mutex_init(&(new->le_lock), NULL);
	new->last_eat = 0;
	pthread_mutex_init(&(new->eats), NULL);
	new->eat = 0;
	new->next = 0;
	new->data = 0;
	return (new);
}

t_philo	**bornphilo(int nb_philo)
{
	int		i;
	t_philo	*last;
	t_philo	*new;
	t_philo	**philos;

	philos = malloc(sizeof(t_philo *));
	if (!philos)
		return (NULL);
	*philos = 0;
	i = -1;
	while (++i < nb_philo)
	{
		new = create_philo(i);
		last = get_last(philos);
		if (!last)
			(*philos) = new;
		else
		{
			new->fork_l = &(last->fork_r);
			last->next = new;
		}
	}
	if (i > 1)
		(*philos)->fork_l = &(new->fork_r);
	return (philos);
}
