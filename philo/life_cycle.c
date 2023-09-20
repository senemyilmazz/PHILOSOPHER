/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:20 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/20 20:14:30 by senyilma         ###   ########.fr       */
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

	calculate(&time_to_wake_up, philo, 4);
	if (ft_print(philo, SLEEP))
		return (1);
	while (anybody_dead(philo) == 0)
	{
		if (get_time(philo) >= time_to_wake_up)
			return (0);
		usleep(100);
	}
	return (1);
}

static int	eating(t_philos *philo)
{
	if (count_of_meal(philo, 0) == 0 || take_forks(philo))
		return (1);
	if (ft_print(philo, EAT))
		return (1);
	calculate(&philo->must_eat_time, philo, 2);
	if (eating_proccess(philo))
		return (1);
	leave_forks(philo);
	return (0);
}

void	*life_cycle(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	calculate(philo->start_time, philo, 1);
	get_time(philo);
	while (1)
	{
		usleep(50);
		if (eating(philo))
			break ;
		if (count_of_meal(philo, 1) == 0)
			break ;
		if (sleeping(philo) || thinking(philo))
			break ;
	}
	return (NULL);
}
