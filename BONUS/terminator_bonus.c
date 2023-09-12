/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:54:10 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 19:15:19 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*am_i_dead(void *ph)
{
	t_philos	*philo;

	philo = (t_philos *)ph;
	while (1)
	{
		usleep(200);
		if (count_of_meal(philo, 0) != 0)
		{
			sem_wait(philo->data->starve);
			if (philo->must_eat_time < get_time(philo))
			{
				sem_wait(philo->data->print);
				printf("%lu %d died\n", get_time(philo), philo->id);
				exit (1);
			}
			sem_post(philo->data->starve);
		}
	}
	return (NULL);
}
