/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:47:48 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/27 11:09:54 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		i;

	if (ac != 5 && ac != 6)
		print_error("Error: invalid number of arguments\n");
	philo = malloc(sizeof(t_philo));
	if (!philo)
		print_error("Error: malloc failed\n");
	init_and_parse_args(ac, av, philo);
	init_data(philo);
	i = -1;
	while (++i < philo->num_philo)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			print_error("Error: fork failed\n");
		if (philo->pid[i] == 0)
		{
			philo->id = i + 1;
			philo->last_meal = get_time();
			philo_action(philo);
		}
	}
	free_and_close(philo);
	return (0);
}
