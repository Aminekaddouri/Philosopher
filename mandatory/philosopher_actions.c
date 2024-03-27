/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:51:05 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/21 10:01:37 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_grap_fork(t_philo *philo, int fork)
{
	pthread_mutex_lock(&philo->data->forks[fork]);
	print_message(philo, "has taken a fork");
}

void	philo_is_eating(t_philo *philo)
{
	print_message(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	philo->last_meal = get_time();
	philo->eat_count++;
	if (philo->eat_count == philo->data->num_each_must_eat)
		philo->data->all_ate++;
}

void	philo_put_fork(t_philo *philo, int right_fork, int left_fork)
{
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
	pthread_mutex_unlock(&philo->data->forks[left_fork]);
}

void	sleep_then_think(t_philo *philo)
{
	print_message(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
	print_message(philo, "is thinking");
}

void	*philosophers(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	while (!philo->should_die && !philo->data->finish_simulation)
	{
		right_fork = philo->id;
		left_fork = (philo->id + 1) % philo->data->num_philo;
		philo_grap_fork(philo, right_fork);
		if (philo->data->num_philo == 1)
		{
			usleep(1000000);
			break ;
		}
		philo_grap_fork(philo, left_fork);
		philo_is_eating(philo);
		philo_put_fork(philo, right_fork, left_fork);
		sleep_then_think(philo);
	}
	return (NULL);
}
