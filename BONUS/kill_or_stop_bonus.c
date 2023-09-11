/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_or_stop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:54:10 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 23:33:45 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	am_i_dead(t_philos *philo, int f)
{
	if (count_of_meal(philo, 0) != 0)
	{
		if (philo->must_eat_time < get_time(philo))
		{
			if (f == 1)
				sem_post(philo->forks);
			if (f == 2)
				leave_forks(philo);
			sem_wait(philo->print);
			printf("%lu %d is dead\n", get_time(philo), philo->id);
			return (1);
		}
	}
	return (0);
}
