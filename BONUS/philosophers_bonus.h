/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:02:30 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/12 20:05:18 by senyilma         ###   ########.fr       */
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

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"

typedef struct s_philos
{
	int				id;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_meals;
	unsigned long	must_eat_time;
	int				*pid;
	pthread_t		*thread;
	struct s_data	*data;
}					t_philos;

typedef struct s_data
{
	int				num_philo;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*starve;
	pthread_t		*threads;
	int				*pid;
	t_philos		*philo;
	unsigned long	start_time;
}					t_data;

int					check_arg(int argc, char **argv);
int					print_error(char *str);
int					ft_atoi(const char *str);
void				*life_cycle(void *ph);
int					count_of_meal(t_philos *philo, int flag);
int					fill_data(t_data *data, char **argv);
void				*am_i_dead(t_philos *philo);
unsigned long		get_time(t_philos *philo);
void				eating_proccess(t_philos *philo);
void				ft_print(t_philos *philo, char *str);
int					take_forks(t_philos *philo);
// void			free_struct(t_struct *data);

#endif
