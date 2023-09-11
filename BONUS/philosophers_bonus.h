/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:02:30 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/11 23:20:35 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "is dead\n"

typedef struct s_philos
{
	int						id;
	int						num_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						count_of_meals;
	unsigned long			start_time;
	unsigned long			must_eat_time;
	sem_t					*forks;
	sem_t					*print;
}							t_philos;

typedef struct s_data
{
	sem_t					*forks;
	sem_t					*print;
	t_philos				*philo;
	unsigned long			start_time;
}							t_data;

int				check_arg(int argc, char **argv);
int				print_error(char *str);
int				ft_atoi(const char *str);
void			life_cycle(t_philos *ph);
int				count_of_meal(t_philos *philo, int flag);
int				fill_data(t_data *data, char **argv);
int				am_i_dead(t_philos *philo, int f);
unsigned long	get_time(t_philos *philo);
void			eating_proccess(t_philos *philo);
void			leave_forks(t_philos *philo);
void			ft_print(t_philos *philo, char *str, int f);
void			calculate(unsigned long *time, t_philos *philo, int f);
int				take_forks(t_philos *philo);
//void			free_struct(t_struct *data);

#endif

