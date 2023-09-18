/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:54:10 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/18 19:39:05 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*am_i_dead(t_philos *philo)
{
	pthread_create(&philo->thread, 0, &life_cycle, (void *)philo);
	while (1)
	{
		usleep(200);
		if (count_of_meal(philo, 0) != 0)
		{
			if (must_eat_time(philo, 0) < get_time(philo))
			{
				sem_wait(philo->data->print);
				printf("%lu %d died\n", get_time(philo), philo->id);
				exit (1);
			}
		}
	}
	return (NULL);
}
