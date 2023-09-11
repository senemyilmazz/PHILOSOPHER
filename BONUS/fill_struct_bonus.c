/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:54:46 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 23:22:07 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void fill_philo(t_data *data, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		data->philo[i].id = i + 1;
		data->philo[i].num_philo = ft_atoi(argv[1]);
		data->philo[i].time_to_die = ft_atoi(argv[2]);
		data->philo[i].time_to_eat = ft_atoi(argv[3]);
		data->philo[i].time_to_sleep = ft_atoi(argv[4]);
		data->philo[i].count_of_meals = -2;
		if(argv[5])
			data->philo[i].count_of_meals = ft_atoi(argv[5]);
		data->philo[i].forks = data->forks;
		data->philo[i].print = data->print;
		data->philo[i].start_time = data->start_time;
		data->philo->must_eat_time = ft_atoi(argv[2]);
	}
}
int	fill_data(t_data *data, char **argv)
{
	data->philo = (t_philos *)malloc(sizeof(t_philos) * ft_atoi(argv[1]));
	if (!data->philo)
		print_error("Allocation Error\n");
	sem_unlink("/forks");
	sem_unlink("/print");
	data->forks = sem_open("/forks", O_CREAT, 0777, ft_atoi(argv[1]));
	data->print = sem_open("/print", O_CREAT, 0777, 1);
	data->start_time = get_time(NULL);
	fill_philo(data, argv);
	return (1);
}

