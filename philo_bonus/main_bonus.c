/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:31:06 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/19 05:05:27 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	grim_reaper(int *pid, int philo_num)
{
	int	i;
	int	status;

	i = -1;
	while (++i < philo_num)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < philo_num)
				kill(pid[i], SIGTERM);
			break ;
		}
	}
}

static int	let_the_game_begin(t_data *data, int philo_num)
{
	int			i;
	t_philos	*philo;

	philo = data->philo;
	i = -1;
	while (++i < philo_num)
	{
		data->pid[i] = fork();
		if (data->pid[i] < -1)
			return (print_error("fork() error!\n"));
		if (data->pid[i] == 0)
			life_cycle(&philo[i]);
	}
	grim_reaper(data->pid, philo_num);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_arg(argc, argv))
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (print_error("Allocation Error\n"));
		if (fill_data(data, argv) == 0)
			return (0);
		let_the_game_begin(data, ft_atoi(argv[1]));
		destroy_all(data);
	}
	return (0);
}
