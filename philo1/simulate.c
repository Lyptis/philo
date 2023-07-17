/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:46:33 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/30 12:21:23 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*void	*philos(void *param)
{
	t_philo	*philo;

	philo = ((t_philo *)param);
	printf("test philo %d\n", philo->data->philo);
	//usleep(10000);

	return (NULL);

}

void	simulate(t_philo *philo)
{
	int			i;
	pthread_t	*tid;
	
	i = 0;
	tid = malloc(sizeof(tid) * philo->data->nb_philo);
	while (i < philo->data->nb_philo)
	{
		philo->data->philo = i;
		pthread_create(&(tid[i]), NULL, &philos, philo);
		i++;
	}
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}*/
