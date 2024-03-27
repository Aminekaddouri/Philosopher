/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:08:28 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/27 11:14:24 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_monitor(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!philo->finished)
	{
		usleep(100);
		if (get_time() - philo->last_meal > philo->time_to_die)
		{
			philo->died = 1;
			sem_wait(philo->print_sem);
			printf("%lld %d %s\n", \
					get_time() - philo->start_time, philo->id, "died");
			philo->finished = 1;
			exit(1);
		}
		if (philo->num_each_must_eat != -1
			&& philo->num_eat_count >= philo->num_each_must_eat)
		{
			philo->finished = 1;
			break ;
		}
	}
	exit(0);
}
