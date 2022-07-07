/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:14:28 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/16 11:13:56 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_main_struct_1(int i, int arg, t_main *main)
{
	if (i == 1)
		main->n_phlsphrs = arg;
	if (i == 2)
		main->t2die = arg;
	if (i == 3)
		main->t2eat = arg;
	if (i == 4)
		main->t2sleep = arg;
	main->n_cycles = 0;
	if (i == 5)
		main->n_cycles = arg;
}

int	init_mutex(pthread_mutex_t time_mute, pthread_mutex_t print)
{
	if (pthread_mutex_init(&time_mute, NULL) != 0)
	{
		pthread_mutex_destroy(&print);
		return (4);
	}
	return (0);
}

int	fill_main_struct_2(t_main *main)
{
	main->completed_cycles = 0;
	main->death_flag = 1;
	main->start_time = get_current_time();
	if (pthread_mutex_init(&main->print, NULL) != 0)
		return (7);
	if (pthread_mutex_init(&main->time_mute, NULL) != 0)
		return (7);
	if (pthread_mutex_init(&main->death_mute, NULL) != 0)
		return (7);
	if (pthread_mutex_init(&main->cycles_mute, NULL) != 0)
		return (7);
	if (pthread_mutex_init(&main->p_cycles_mute, NULL) != 0)
		return (7);
	return (0);
}

void	init_philosophers(t_main *main,
			pthread_mutex_t *forks, t_philo *philo, int i)
{
	pthread_mutex_init(&forks[i], NULL);
	philo[i].phl_main = main;
	philo[i].lst_eatng_time = 0;
	philo[i].id = i + 1;
	philo[i].fork_1 = &forks[i];
	if (i != main->n_phlsphrs - 1)
		philo[i].fork_2 = &forks[i + 1];
	else
		(philo[i].fork_2 = &forks[0]);
	if (main->n_args == 4)
		philo[i].n_cycles = -1;
	else
		philo[i].n_cycles = 0;
	if (pthread_create(&main->threads[i], NULL,
			lifecycle, (void *)(&philo[i])) != 0)
		main->death_flag = -1;
	pthread_detach(main->threads[i]);
}

int	philo_init(t_main *main, pthread_mutex_t *forks, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < main->n_phlsphrs)
		init_philosophers(main, forks, philo, i);
	if (main->death_flag < 0)
	{
		mutex_destroy(main, forks);
		return (5);
	}
	return (0);
}
