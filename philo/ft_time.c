/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:35:47 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/23 12:46:23 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(t_philo *philo, unsigned long ms)
{
	unsigned long	end_time;

	end_time = gettime(philo->data->start) + ms;
	while (gettime(philo->data->start) < end_time)
	{
		if (isdead(philo, philo->data))
			return ;
		usleep(100);
	}
}

unsigned long	gettime(unsigned long start)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, 0);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000 - start;
	return (time);
}
