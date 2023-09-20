/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_or_stop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:48:11 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/20 19:10:10 by senyilma         ###   ########.fr       */
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
		printf("\033[0;91m%lu	%d	died\n\033[0m", get_time(philo), philo->id);
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

int	count_of_meal(t_philos *philo, int flag)
{
	int	value;

	pthread_mutex_lock(philo->meal);
	if (flag == 1 && philo->count_of_meals != -2)
		philo->count_of_meals--;
	value = philo->count_of_meals;
	pthread_mutex_unlock(philo->meal);
	return (value);
}

int	are_they_hungry(t_struct *data)
{
	int	i;

	i = -1;
	if (data->count_of_meals < 0)
		return (0);
	while (++i < data->num_philo)
		if (count_of_meal(&data->philo[i], 0) != 0)
			return (0);
	return (1);
}
