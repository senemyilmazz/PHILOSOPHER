/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:20 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/18 19:36:27 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	thinking(t_philos *philo)
{
	ft_print(philo, THINK);
}

static void	sleeping(t_philos *philo)
{
	unsigned long	time_to_wake_up;

	time_to_wake_up = get_time(philo) + philo->time_to_sleep;
	ft_print(philo, SLEEP);
	while (1)
	{
		if (get_time(philo) >= time_to_wake_up)
			break ;
		usleep(100);
	}
}

static void	eating(t_philos *philo)
{
	if (count_of_meal(philo, 0) == 0)
		exit (0);
	take_forks(philo);
	ft_print(philo, EAT);
	must_eat_time(philo, 1);
	eating_proccess(philo);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*life_cycle(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	get_time(philo);
	while (1)
	{
		usleep(200);
		eating(philo);
		if (count_of_meal(philo, 1) == 0)
			exit (0);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
