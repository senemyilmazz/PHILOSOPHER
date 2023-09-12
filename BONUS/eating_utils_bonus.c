/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:37:49 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 19:08:26 by senyilma         ###   ########.fr       */
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

	calculate(&time_to_be_full, philo, 4);
	while (1)
	{
		if (get_time(philo) >= time_to_be_full)
			break ;
		usleep(200);
	}
}

void	leave_forks(t_philos *philo)
{
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

int	count_of_meal(t_philos *philo, int flag)
{
	int	value;

	if (flag == 1 && philo->count_of_meals != -2)
		philo->count_of_meals--;
	value = philo->count_of_meals;
	return (value);
}