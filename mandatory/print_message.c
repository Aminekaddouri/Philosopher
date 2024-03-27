/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 08:34:13 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/21 08:48:59 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (!philo->data->finish_simulation)
		printf("%lli\t%i\t%s\n", elapsed_time(philo), philo->id + 1, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}
