/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:20:34 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/22 14:01:20 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCCESS 0
# define FAILURE 1

enum e_bool
{
	false,
	true
};

typedef struct timeval	t_time;
typedef struct s_data	t_data;

typedef struct s_philo
{
	int			id;
	int			eat_count;
	int			should_die;
	long long	last_meal;
	t_data		*data;
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_philo;
	int				num_each_must_eat;
	int				finish_simulation;
	int				all_ate;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
}		t_data;

/* UTILS FUNCTIONS */
int			ft_atoi(const char *str);
void		*ft_malloc(size_t size);
int			ft_strlen(const char *str);
long long	get_time(void);
long long	elapsed_time(t_philo *philo);
int			print_error(char *err);

/* INIT FUNCTIONS */
int			init_data(t_data *data, int ac, char **av);
int			initialize_philosopher(t_data *data);

/* ACT FUNCTIONS */
void		print_message(t_philo *philo, char *msg);
void		*philosophers(void *arg);
void		join_and_destroy(t_data *data);
#endif