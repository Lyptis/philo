/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:34:37 by svanmeen          #+#    #+#             */
/*   Updated: 2023/09/05 16:56:38 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data	*info)
{
	t_philo	*curr;
	t_philo	*tmp;

	curr = *(info->philo);
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(info->philo);
	free(info->tid);
}

void	destroy(t_data	*info)
{
	t_philo	*curr;

	curr = *(info->philo);
	while (curr)
	{
		pthread_mutex_destroy(&(curr->fork_r));
		curr = curr->next;
	}
	pthread_mutex_destroy(&(info->deadlock));
	pthread_mutex_destroy(&(info->prompt));
	ft_free(info);
}

void	routine(t_data *info)
{
	t_philo		*curr;

	curr = *(info->philo);
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
	info->tid = tid;
	routine(info);
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

	if (argc != 5 && argc != 6)
		return (printf("Invalid Args\n"));
	if (input(argc, argv))
		return (printf("Invalid Args\n"));
	info = fill_data(argv);
	simulate(info);
	destroy(info);
	free(info);
	return (0);
}
