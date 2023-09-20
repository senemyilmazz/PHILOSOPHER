/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 04:53:39 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/20 17:27:08 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_time(t_philos *philo)
{
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - *philo->start_time);
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
	printf("%s%lu%s %s%d%s %s%s%s", CYAN, get_time(philo),
		END, GREEN, philo->id, END, PURPLE, str, END);
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
