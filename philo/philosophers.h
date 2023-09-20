/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:45:37 by senyilma          #+#    #+#             */
/*   Updated: 2023/09/20 17:18:22 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"

# define PURPLE "\033[0;95m"
# define CYAN "\033[0;96m"
# define GREEN "\033[0;92m"
# define END "\033[0m"

typedef struct s_philos
{
	int						id;
	int						num_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						count_of_meals;
	int						*fin_flag;
	unsigned long			*start_time;
	unsigned long			must_eat_time;
	pthread_t				thr;
	pthread_mutex_t			*dead;
	pthread_mutex_t			*meal;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			starve;
}							t_philos;

typedef struct s_struct
{
	int				num_philo;
	int				count_of_meals;
	int				fin_flag;
	unsigned long	start_time;
	t_philos		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
	pthread_mutex_t	meal;
}					t_struct;

int				check_arg(int argc, char **argv);
int				print_error(char *str, t_struct *data);
int				ft_atoi(const char *str);
int				fill_data(t_struct	*data, char **argv);
void			*life_cycle(void *ph);
void			kill_or_stop(t_struct *data);
int				count_of_meal(t_philos *philo, int flag);
int				are_they_hungry(t_struct *data);
int				anybody_dead(t_philos *philo);
int				am_i_dead(t_philos *philo);
unsigned long	get_time(t_philos *philo);
int				eating_proccess(t_philos *philo);
void			leave_forks(t_philos *philo);
int				ft_print(t_philos *philo, char *str);
void			calculate(unsigned long *time, t_philos *philo, int f);
int				take_forks(t_philos *philo);
void			free_struct(t_struct *data);

#endif
