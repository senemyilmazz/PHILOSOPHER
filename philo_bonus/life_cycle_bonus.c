/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:20 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/19 04:32:03 by senyilma         ###   ########.fr       */
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
	while (am_i_dead(philo))
	{
		if (get_time(philo) >= time_to_wake_up)
			break ;
		usleep(100);
	}
}

static void	eating(t_philos *philo)
{
	count_of_meal(philo, 0);
	sem_wait(philo->data->forks);
	ft_print(philo, FORK);
	sem_wait(philo->data->forks);
	ft_print(philo, FORK);
	ft_print(philo, EAT);
	eating_proccess(philo);
	philo->must_eat_time = get_time(philo) + philo->time_to_die;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*life_cycle(t_philos *philo)
{
	get_time(philo);
	if (philo->num_philo == 1)
	{
		ft_print(philo, FORK);
		usleep(1000 * philo->time_to_die);
	}
	while (am_i_dead(philo) || count_of_meal(philo, 0))
	{
		eating(philo);
		count_of_meal(philo, 1);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
