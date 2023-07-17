/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:35:47 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/08 17:50:20 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msleep(unsigned long ms)
{
	usleep(ms * 1000);
}

unsigned long	gettime(unsigned long start)
{
	struct timeval		tv;
	unsigned long long	time;

	gettimeofday(&tv, 0);

	time = tv.tv_sec * 1000 + tv.tv_usec / 1000 - start;
	return (time);
}
