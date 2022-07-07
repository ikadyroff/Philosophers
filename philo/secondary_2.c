/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:13:41 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/16 11:14:02 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_destroy(t_main *main, pthread_mutex_t *forks)
{
	int	i;

	pthread_mutex_destroy(&main->print);
	i = 0;
	while (i < main->n_phlsphrs)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	destroy_forks(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_unlock(&forks[i]);
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	joining_threads(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->n_phlsphrs)
		pthread_join(main->threads[i], NULL);
	pthread_join(main->tracking, NULL);
}

void	jn_dstr_fr(t_main main, t_philo *philo, pthread_mutex_t	*forks)
{
	joining_threads(&main);
	destroy_forks(forks, main.n_phlsphrs);
	free(forks);
	free(philo);
	free(main.threads);
}
