/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:10:08 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/23 11:40:26 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt(t_philo *philo, char *str)
{
	if (checkdeath(philo->data))
		return ;
	pthread_mutex_lock(&(philo->data->prompt));
	printf("%lu %d %s\n", gettime(philo->data->start), philo->philo, str);
	pthread_mutex_unlock(&(philo->data->prompt));
}
