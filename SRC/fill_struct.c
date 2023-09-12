/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:55:36 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 08:26:49 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	fill_philo(t_philos *philo, t_struct *data, char **argv, int i)
{
	philo->id = i + 1;
	philo->num_philo = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->count_of_meals = -2;
	if (argv[5])
		philo->count_of_meals = ft_atoi(argv[5]);
	philo->fin_flag = &data->fin_flag;
	philo->start_time = &data->start_time;
	philo->dead = &data->dead;
	philo->meal = &data->meal;
	philo->right_fork = &data->forks[i + 1];
	philo->left_fork = &data->forks[i % philo->num_philo];
	if (philo->id == philo->num_philo)
		philo->right_fork = &data->forks[0];
	if (pthread_mutex_init(&philo->starve, 0))
		return (print_error("Mutex init error!\n", data));
	return (1);
}

int	fill_data(t_struct	*data, char **argv)
{
	int	i;

	data->num_philo = ft_atoi(argv[1]);
	data->count_of_meals = -2;
	if (argv[5])
		data->count_of_meals = ft_atoi(argv[5]);
	data->fin_flag = 0;
	data->start_time = 0;
	data->philo = (t_philos *)malloc(sizeof(t_philos) * data->num_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->philo || !data->forks)
		return (print_error("Allocation error!\n", data));
	i = -1;
	if (pthread_mutex_init(&data->dead, 0))
		return (print_error("Mutex init error!\n", data));
	if (pthread_mutex_init(&data->meal, 0))
		return (print_error("Mutex init error!\n", data));
	while (++i < data->num_philo)
		if (pthread_mutex_init(&data->forks[i], 0))
			return (print_error("Mutex init error!\n", data));
	i = -1;
	while (++i < data->num_philo)
		if (fill_philo(&data->philo[i], data, argv, i) == 0)
			return (0);
	return (1);
}

void	free_struct(t_struct *data)
{
	int	i;

	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->meal);
	i = -1;
	while (++i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	free(data->philo);
}
