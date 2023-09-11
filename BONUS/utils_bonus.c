/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:57:26 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 23:19:05 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (!(argc == 5 || argc == 6))
		return (print_error("Invalid Arg!\n"));
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '+' && argv[i][1])
			j++;
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (print_error("Invalid Arg!\n"));
		}
	}
	if (!ft_atoi(argv[1]))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;
	int			sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = 10 * result + (str[i] - 48);
		i++;
	}
	result = result * sign;
	return ((int)result);
}

int	print_error(char *str)
{
	printf("%s", str);
	return (0);
}

void	ft_print(t_philos *philo, char *str, int f)
{
	if (am_i_dead(philo, f))
		exit(1);
	sem_wait(philo->print);
	printf("%lu %d %s", get_time(philo), philo->id, str);
	sem_post(philo->print);
}
