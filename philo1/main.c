/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:43:11 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/30 12:58:27 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("philo : \x1B[31mInvalid args\n\x1B[0m"));
	data = parse(argv);
	data.philo = init_philo(data);
	set_mutex(&data);
	free(data.philo);
	//mutex_destroy(&data, data.nb_philo);
}
