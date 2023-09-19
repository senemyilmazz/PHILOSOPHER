/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:37:49 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/19 04:51:59 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	leave_forks(t_philos *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	eating_proccess(t_philos *philo)
{
	unsigned long	time_to_be_full;

	calculate(&time_to_be_full, philo, 4);
	while (anybody_dead(philo) == 0)
	{
		if (get_time(philo) >= time_to_be_full)
			return (0);
		usleep(200);
	}
	return (1);
}

int	take_forks(t_philos *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (ft_print(philo, FORK))
		return (1);
	pthread_mutex_lock(philo->right_fork);
	if (ft_print(philo, FORK))
		return (1);
	return (0);
}
