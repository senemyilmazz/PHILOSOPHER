/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:31:06 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 23:55:40 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	kill_all_process(int *pid, int philo_num)
{
	int	i;

	i = 0;
	while (i++ < philo_num)
	{
		printf("aaa\n");
		kill(pid[i], SIGTERM);
	}
}

static void	let_the_game_begin(t_philos *philo, int philo_num)
{
	int	*pid;
	int	i;
	int	status;

	pid = (int *)malloc(sizeof(int) * philo_num);
	if (!pid)
		print_error("Allocation Error\n");
	i = -1;
	while (++i < philo_num)
	{
		if ((pid[i] = fork()) < -1)
		{
			print_error("fork() error!\n");
			break ;
		}
		if (pid[i] == 0)
			life_cycle(&philo[i]);
		usleep(200);
	}
	waitpid(-1, &status, 0);
	if (status == 1)
		kill_all_process(pid, philo_num);
}

int	main(int argc, char **argv)
{
	t_data			*data;

	if (check_arg(argc, argv))
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			print_error("Allocation Error\n");
		if (fill_data(data, argv) == 0)
			return (0);
		let_the_game_begin(data->philo, ft_atoi(argv[1]));
	}
	return (0);
}
