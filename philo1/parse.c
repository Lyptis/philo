/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:38:10 by svanmeen          #+#    #+#             */
/*   Updated: 2023/05/25 14:46:13 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	char	*s;
	int		i;
	int		sign;
	long	result;

	s = (char *)str;
	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] > 8 && s[i] < 14) || s[i] == 32)
		i++;
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45)
			sign = sign * -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if ((result > 2147483648 && sign < 0) || (result > 2147483647 && sign > 0))
		return (-1);
	return (result * sign);
}

// pthread_mutex_t	*mutex_init(int nb_philo)
// {
// 	int				i;
// 	pthread_mutex_t	*locks;

// 	i = 0;
// 	locks = malloc(sizeof(pthread_mutex_t) * nb_philo);
// 	if (!locks)
// 		return (NULL);
// 	while (i < nb_philo)
// 	{
// 		pthread_mutex_init(&locks[i], NULL);
// 		i++;
// 	}
// 	return (locks);
// }

t_data	parse(char **strs)
{
	t_data	data;

	data.nb_philo = ft_atoi(strs[1]);
	data.ttd = ft_atoi(strs[2]);
	data.tte = ft_atoi(strs[3]);
	data.tts = ft_atoi(strs[4]);
	if (strs[5])
		data.noe = ft_atoi(strs[5]);
	else
		data.noe = -1;
	return (data);
}
