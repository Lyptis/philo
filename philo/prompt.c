/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:10:08 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/27 15:02:29 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	prompt(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->prompt));
	if (!checkdeath(philo->data))
		printf("%lu %d %s\n", gettime(philo->data->start), philo->philo, str);
	pthread_mutex_unlock(&(philo->data->prompt));
}
