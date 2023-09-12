/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:22:40 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 20:05:13 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

unsigned long	get_time(t_philos *philo)
{
	struct timeval			tv;
	unsigned long			start_time;

	gettimeofday(&tv, NULL);
	start_time = 0;
	if (philo)
		start_time = philo->data->start_time;
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start_time);
}
