/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaddouri <kaddouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:53:25 by kaddouri          #+#    #+#             */
/*   Updated: 2024/03/26 16:58:02 by kaddouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	parsing(t_philo philo, int ac)
{
	if (ac == 6 && philo.num_each_must_eat <= 0)
		print_error("ERROR: wrong num of meals must eat\n");
	if (philo.num_philo <= 0 || philo.num_philo > 200)
		print_error("ERROR: wrong num of philo\n");
	if (philo.time_to_die < 60)
		print_error("ERROR: wrong time to die\n");
	if (philo.time_to_eat < 60)
		print_error("ERROR: wrong time to eat\n");
	if (philo.time_to_sleep < 60)
		print_error("ERROR: wrong time to sleep\n");
}

void	init_and_parse_args(int ac, char **av, t_philo *philo)
{
	philo->num_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->num_each_must_eat = ft_atoi(av[5]);
	else
		philo->num_each_must_eat = -1;
	parsing(*philo, ac);
}
