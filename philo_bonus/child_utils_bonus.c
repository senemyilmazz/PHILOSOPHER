/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:37:49 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/20 19:46:53 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eating_proccess(t_philos *philo)
{
	unsigned long	time_to_be_full;

	time_to_be_full = get_time(philo) + philo->time_to_eat;
	while (am_i_dead(philo))
	{
		if (get_time(philo) >= time_to_be_full)
			break ;
		usleep(200);
	}
}

int	count_of_meal(t_philos *philo, int flag)
{
	int		value;

	if (flag == 1 && philo->count_of_meals != -2)
		philo->count_of_meals--;
	value = philo->count_of_meals;
	if (value == 0)
		exit (0);
	return (value);
}

int	am_i_dead(t_philos *philo)
{
	if (count_of_meal(philo, 0) != 0)
	{
		if (philo->must_eat_time < get_time(philo))
		{
			philo->fin_flag = 1;
			sem_wait(philo->data->print);
			printf("\033[0;91m%lu	%d	died\n\033[0m", get_time(philo),
				philo->id);
			exit (1);
		}
	}
	return (1);
}

void	ft_print(t_philos *philo, char *str)
{
	if (am_i_dead(philo))
	{
		sem_wait(philo->data->print);
		printf("%s%lu	%d%s	%s", BLUE, get_time(philo),
			philo->id, END, str);
		sem_post(philo->data->print);
	}
}

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
