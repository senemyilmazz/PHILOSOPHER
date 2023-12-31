/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:02:30 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/20 19:35:10 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define FORK "\033[0;95mhas taken a fork\n\033[0m"
# define EAT "\033[0;93mis eating\n\033[0m"
# define SLEEP "\033[0;92mis sleeping\n\033[0m"
# define THINK "\033[0;96mis thinking\n\033[0m"

# define BLUE "\033[0;94m"
# define END "\033[0m"

typedef struct s_philos
{
	int				id;
	int				fin_flag;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_meals;
	unsigned long	must_eat_time;
	struct s_data	*data;
}					t_philos;

typedef struct s_data
{
	int				num_philo;
	sem_t			*forks;
	sem_t			*print;
	t_philos		*philo;
	int				*pid;
	unsigned long	start_time;
}					t_data;

int					check_arg(int argc, char **argv);
int					print_error(char *str);
int					ft_atoi(const char *str);
int					fill_data(t_data *data, char **argv);
unsigned long		get_time(t_philos *philo);
void				*life_cycle(t_philos *philo);
void				ft_print(t_philos *philo, char *str);
void				eating_proccess(t_philos *philo);
int					am_i_dead(t_philos *philo);
int					count_of_meal(t_philos *philo, int flag);
void				destroy_all(t_data *data);

#endif
