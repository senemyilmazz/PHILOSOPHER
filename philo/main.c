/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:37:41 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/19 09:23:42 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	kill_or_stop(t_struct *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == data->num_philo)
			i = 0;
		if (are_they_hungry(data))
			break ;
		if (am_i_dead(&data->philo[i++]))
			break ;
		usleep(200);
	}
}

static int	let_the_game_begin(t_struct *data, t_philos *philo)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&philo[i].thr, NULL, &life_cycle, (void *)&philo[i]))
			return (1);
		usleep(50);
	}
	kill_or_stop(data);
	i = -1;
	while (++i < data->num_philo)
		pthread_join(data->philo[i].thr, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*data;

	if (check_arg(argc, argv))
	{
		data = (t_struct *)malloc(sizeof(t_struct));
		if (!data)
			return (print_error("Allocation Error!\n", NULL));
		if (fill_data(data, argv) == 0)
			return (0);
		if (let_the_game_begin(data, data->philo))
			return (print_error("Thread creating error!\n", data));
		free_struct(data);
	}
	return (0);
}
