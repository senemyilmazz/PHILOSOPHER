/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:37:49 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/18 19:36:14 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	take_forks(t_philos *philo)
{
	sem_wait(philo->data->forks);
	ft_print(philo, FORK);
	sem_wait(philo->data->forks);
	ft_print(philo, FORK);
	return (0);
}

void	eating_proccess(t_philos *philo)
{
	unsigned long	time_to_be_full;

	time_to_be_full = get_time(philo) + philo->time_to_eat;
	while (1)
	{
		if (get_time(philo) >= time_to_be_full)
			break ;
		usleep(200);
	}
}

int	count_of_meal(t_philos *philo, int flag)
{
	int		value;

	sem_wait(philo->data->starve);
	if (flag == 1 && philo->count_of_meals != -2)
		philo->count_of_meals--;
	value = philo->count_of_meals;
	sem_post(philo->data->starve);
	return (value);
}

unsigned long	must_eat_time(t_philos *philo, int flag)
{
	int		value;

	sem_wait(philo->data->must_eat);
	if (flag == 1)
		philo->must_eat_time = get_time(philo) + philo->time_to_die;
	value = philo->must_eat_time;
	sem_post(philo->data->must_eat);
	return (value);
}
