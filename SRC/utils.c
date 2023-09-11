/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:57:26 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 18:36:59 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (!(argc == 5 || argc == 6))
		return (print_error("Invalid Arg!\n", NULL));
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '+' && argv[i][1])
			j++;
		while (argv[i][++j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (print_error("Invalid Arg!\n", NULL));
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

int	print_error(char *str, t_struct *data)
{
	printf("%s", str);
	if (data)
	{
		if (data->philo)
			free(data->philo);
		if (data->forks)
			free(data->forks);
	}
	free(data);
	return (0);
}

int	ft_print(t_philos *philo, char *str)
{
	pthread_mutex_lock(philo->dead);
	if (*philo->fin_flag == 1)
	{
		leave_forks(philo);
		pthread_mutex_unlock(philo->dead);
		return (1);
	}
	printf("%lu %d %s", get_time(philo), philo->id, str);
	pthread_mutex_unlock(philo->dead);
	return (0);
}

void	calculate(unsigned long *time, t_philos *philo, int f)
{
	if (f == 1)
	{
		pthread_mutex_lock(philo->dead);
		if (*time == 0)
			*time = get_time(philo);
		pthread_mutex_unlock(philo->dead);
	}
	if (f == 2)
	{
		pthread_mutex_lock(&philo->starve);
		*time = philo->time_to_die;
		pthread_mutex_unlock(&philo->starve);
	}
	if (f == 3)
	{
		pthread_mutex_lock(&philo->starve);
		*time = get_time(philo) + philo->time_to_die;
		pthread_mutex_unlock(&philo->starve);
	}
	if (f == 4)
		*time = get_time(philo) + philo->time_to_eat;
	if (f == 5)
		*time = get_time(philo) + philo->time_to_sleep;
}
