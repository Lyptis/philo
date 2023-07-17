/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filldata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:40:40 by svanmeen          #+#    #+#             */
/*   Updated: 2023/06/11 16:02:17 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
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

t_data	*fill_data(int argc, char **argv)
{
	t_data	*info;

	info = malloc(sizeof(t_data));
	info->nb_philo = ft_atoi(argv[1]);
	info->philo = bornphilo(info->nb_philo);
	if (!info->philo)
		return (NULL);
	info->ttd = ft_atoi(argv[2]);
	info->tte = ft_atoi(argv[3]);
	info->tts = ft_atoi(argv[4]);
	if (argv[5])
		info->nbe = ft_atoi(argv[5]);
	else
		info->nbe = -1;
	info->start = 0;
	return (info);
}
