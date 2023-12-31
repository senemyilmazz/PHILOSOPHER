/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:54:46 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/19 05:16:23 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	destroy_all(t_data *data)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_close(data->forks);
	sem_close(data->print);
	free(data->pid);
	free(data->philo);
	free(data);
}

static int	ft_sem_init(t_data *data, int num_philo)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	data->forks = sem_open("/forks", O_CREAT, 0777, num_philo);
	data->print = sem_open("/print", O_CREAT, S_IRWXU, 1);
	if (data->forks == SEM_FAILED || data->print == SEM_FAILED)
		return (print_error("sem_open() error!\n"));
	return (1);
}

static void	fill_philo(t_data *data, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		data->philo[i].id = i + 1;
		data->philo[i].fin_flag = 0;
		data->philo[i].num_philo = ft_atoi(argv[1]);
		data->philo[i].time_to_die = ft_atoi(argv[2]);
		data->philo[i].time_to_eat = ft_atoi(argv[3]);
		data->philo[i].time_to_sleep = ft_atoi(argv[4]);
		data->philo[i].count_of_meals = -2;
		if (argv[5])
			data->philo[i].count_of_meals = ft_atoi(argv[5]);
		data->philo[i].must_eat_time = ft_atoi(argv[2]);
		data->philo[i].data = data;
	}
}

int	fill_data(t_data *data, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	if (ft_sem_init(data, data->num_philo) == 0)
		return (print_error("Sem_Open Error!\n"));
	data->philo = (t_philos *)malloc(sizeof(t_philos) * data->num_philo);
	data->pid = (int *)malloc(sizeof(int) * data->num_philo);
	if (!data->philo || !data->pid)
		return (print_error("Allocation Error\n"));
	fill_philo(data, argv);
	data->start_time = get_time(NULL);
	return (1);
}
