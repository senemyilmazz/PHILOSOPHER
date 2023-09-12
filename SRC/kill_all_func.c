/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:54:10 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 08:34:53 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	anybody_dead(t_philos *philo)
{
	int	value;

	pthread_mutex_lock(philo->dead);
	value = *philo->fin_flag;
	if (value == 1)
		leave_forks(philo);
	pthread_mutex_unlock(philo->dead);
	return (value);
}

static int	terminator(t_philos *philo)
{
	pthread_mutex_lock(philo->dead);
	if (*philo->fin_flag == 0)
	{
		*philo->fin_flag = 1;
		printf("%lu %d died\n", get_time(philo), philo->id);
		leave_forks(philo);
	}
	pthread_mutex_unlock(philo->dead);
	pthread_mutex_unlock(&philo->starve);
	return (1);
}

int	am_i_dead(t_philos *philo)
{
	if (anybody_dead(philo) == 0 && count_of_meal(philo, 0) != 0)
	{
		pthread_mutex_lock(&philo->starve);
		if (philo->must_eat_time < get_time(philo))
			return (terminator(philo));
		pthread_mutex_unlock(&philo->starve);
	}
	return (0);
}
