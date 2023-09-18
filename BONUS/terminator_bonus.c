/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:54:10 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/18 23:46:38 by senyilma         ###   ########.fr       */
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
			if (must_eat_time(philo, 0) < get_time(philo))
			{
				sem_wait(philo->data->print);
				printf("%lu %d died\n", get_time(philo), philo->id);
				sem_wait(philo->data->death);
				*philo->fin_flag = 1;
				sem_post(philo->data->death);
				break ;
			}
		}
	}
	return (NULL);
}
