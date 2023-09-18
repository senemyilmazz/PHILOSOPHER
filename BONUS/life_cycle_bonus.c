/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:30:20 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/18 23:53:17 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	thinking(t_philos *philo)
{
	ft_print(philo, THINK, 0);
}

static void	sleeping(t_philos *philo)
{
	unsigned long	time_to_wake_up;

	time_to_wake_up = get_time(philo) + philo->time_to_sleep;
	ft_print(philo, SLEEP, 0);
	while (1)
	{
		sem_wait(philo->data->death);
		if (*philo->fin_flag == 1)
		{
			sem_post(philo->data->death);
			exit (1);
		}
		sem_post(philo->data->death);
		if (get_time(philo) >= time_to_wake_up)
			break ;
		usleep(100);
	}
}

void	eating(t_philos *philo)
{
	if (count_of_meal(philo, 0) == 0)
		exit (0);
	take_forks(philo);
	ft_print(philo, EAT, 2);
	must_eat_time(philo, 1);
	eating_proccess(philo);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*life_cycle(t_philos *philo)
{
	pthread_create(&philo->thread, 0, &am_i_dead, (void *)philo);
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
