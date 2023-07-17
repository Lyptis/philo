/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:10:28 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/08 17:37:43 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "sys/time.h"
#include "unistd.h"

void	msleep(unsigned long ms)
{
	usleep(ms * 1000);
}

unsigned long	gettime(unsigned long start)
{
	struct timeval		tv;
	unsigned long	time;

	gettimeofday(&tv, 0);

	time = tv.tv_sec * 1000 + tv.tv_usec / 1000 - start;
}

int	main(void)
{
	unsigned long	s_time;
	unsigned long	elapsed;


	s_time = gettime(0);
	msleep(1000);
	elapsed = gettime(s_time);
	printf("%lu\n", elapsed);
}
