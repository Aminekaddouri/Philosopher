/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:32:27 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/27 11:14:37 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_grab_fork(t_philo *philo)
{
	sem_wait(philo->fork_sem);
	print_message(philo, "has taken a fork");
	sem_wait(philo->fork_sem);
	print_message(philo, "has taken a fork");
}

void	ft_down_forks(t_philo *philo)
{
	sem_post(philo->fork_sem);
	sem_post(philo->fork_sem);
}

void	ft_sleep_then_think(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_sleep(philo->time_to_sleep, philo);
	print_message(philo, "is thinking");
}

void	ft_eating(t_philo *philo)
{
	if (philo->num_philo == 1)
	{
		ft_sleep(philo->time_to_die, philo);
		print_message(philo, "died");
		philo->died = 1;
		return ;
	}
	print_message(philo, "is eating");
	ft_sleep(philo->time_to_eat, philo);
	philo->last_meal = get_time();
	philo->num_eat_count += 1;
}

void	philo_action(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, \
			NULL, &check_monitor, philo))
		print_error("Error: Failed to create the thread");
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		ft_grab_fork(philo);
		ft_eating(philo);
		ft_down_forks(philo);
		if (philo->num_each_must_eat != -1
			&& philo->num_eat_count >= philo->num_each_must_eat)
		{
			philo->finished = 1;
			exit(0);
		}
		ft_sleep_then_think(philo);
	}
	if (pthread_join(philo->check_monitor, NULL))
		print_error("Error: Failed to join the thread");
}
