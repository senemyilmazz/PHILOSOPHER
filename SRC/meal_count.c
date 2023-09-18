/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mealCount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:12:58 by senyilma          #+#    #+#             */
/*   Updated: 2023/08/23 19:34:05 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	count_of_meal(t_philos *philo, int flag)
{
	int	value;

	pthread_mutex_lock(philo->meal);
	if (flag == 1 && philo->count_of_meals != -2)
		philo->count_of_meals--;
	value = philo->count_of_meals;
	pthread_mutex_unlock(philo->meal);
	return (value);
}

int	are_they_hungry(t_struct *data)
{
	int	i;

	i = -1;
	if (data->count_of_meals < 0)
		return (0);
	while (++i < data->num_philo)
		if (count_of_meal(&data->philo[i], 0) != 0)
			return (0);
	return (1);
}
