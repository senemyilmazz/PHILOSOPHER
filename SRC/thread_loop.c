/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:20 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 18:41:12 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	thinking(t_philos *philo)
{
	if (ft_print(philo, THINK))
		return (1);
	return (0);
}

static int	sleeping(t_philos *philo)
{
	unsigned long	time_to_wake_up;

	calculate(&time_to_wake_up, philo, 5);
	if (ft_print(philo, SLEEP))
		return (1);
	while (1)
	{
		if (get_time(philo) >= time_to_wake_up)
			break ;
		if (anybody_dead(philo))
			return (1);
		usleep(100);
	}
	return (0);
}

static int	eating(t_philos *philo)
{
	if (count_of_meal(philo, 0) == 0 || take_forks(philo))
		return (1);
	if (ft_print(philo, EAT))
		return (1);
	calculate(&philo->must_eat_time, philo, 3);
	if (eating_proccess(philo))
		return (1);
	leave_forks(philo);
	return (0);
}

void	*life_cycle(void *ph)
{
	t_philos *philo;

	philo = (t_philos *)ph;
	calculate(philo->start_time, philo, 1);
	calculate(&philo->must_eat_time, philo, 2);
	get_time(philo);
	while (1)
	{
		usleep(200);
		if (eating(philo))
			break ;
		if (count_of_meal(philo, 1) == 0)
			break ;
		if (sleeping(philo) || thinking(philo))
			break ;
	}
	return (NULL);
}
