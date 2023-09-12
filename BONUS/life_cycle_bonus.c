/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:20 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 08:11:32 by senyilma         ###   ########.fr       */
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

	calculate(&time_to_wake_up, philo, 5);
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
	calculate(&philo->must_eat_time, philo, 3);
	eating_proccess(philo);
	leave_forks(philo);
}

void	*life_cycle(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	calculate(&philo->must_eat_time, philo, 2);
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
