/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:58:52 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/27 11:08:25 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_data(t_philo *philo)
{
	philo->num_eat_count = 0;
	philo->finished = 0;
	philo->died = 0;
	philo->start_time = get_time();
	philo->num_forks = philo->num_philo;
	philo->pid = (int *)malloc(sizeof(int) * philo->num_forks);
	if (!philo->pid)
		print_error("Error: malloc failed\n");
	sem_unlink("/print_sem");
	sem_unlink("/fork_sem");
	philo->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	philo->fork_sem = sem_open("/fork_sem", O_CREAT, \
								0644, philo->num_forks);
	if (philo->print_sem == SEM_FAILED || philo->fork_sem == SEM_FAILED)
		print_error("Error: semaphore open error");
}
