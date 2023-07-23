/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/07/23 12:58:02 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine(t_data info)
{
	while (info->start > gettime(0))
		;
	while (!checkdeath(info))
	{
		if (curr)
			isdead(curr, info);
		else
			curr = *(info->philo);
	}
}

void	simulate(t_data	*info)
{
	t_philo		*curr;
	pthread_t	*tid;
	int			i;

	curr = *(info->philo);
	tid = malloc(sizeof(pthread_t) * info->nb_philo);
	info->start = gettime(0) + info->nb_philo * 10;
	i = 0;
	while (i < info->nb_philo && curr)
	{
		curr->data = info;
		pthread_create(&tid[i], NULL, &life, curr);
		if (curr->next)
			curr = curr->next;
		i++;
	}
	curr = *(info->philo);

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
