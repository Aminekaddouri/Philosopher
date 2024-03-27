/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:42:40 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/27 11:09:08 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_message(t_philo *philo, char *str)
{
	sem_wait(philo->print_sem);
	if (!philo->finished)
		printf("%lld %d %s\n", get_time() - philo->start_time, philo->id, str);
	sem_post(philo->print_sem);
}
