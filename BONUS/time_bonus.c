/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:22:40 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 19:04:57 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

unsigned long	get_time(t_philos *philo)
{
	struct timeval			tv;
	unsigned long			start_time;

	gettimeofday(&tv, NULL);
	start_time = 0;
	if (philo)
		start_time = philo->data->start_time;
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start_time);
}

void	calculate(unsigned long *time, t_philos *philo, int f)
{
	if (f == 2)
	{
		sem_wait(philo->data->starve);
		*time = philo->time_to_die;
		sem_post(philo->data->starve);
	}
	if (f == 3)
		*time = get_time(philo) + philo->time_to_die;
	if (f == 4)
		*time = get_time(philo) + philo->time_to_eat;
	if (f == 5)
		*time = get_time(philo) + philo->time_to_sleep;
}
