/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:19:04 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/15 14:29:43 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	taking_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_1);
	pthread_mutex_lock(&philo->phl_main->print);
	printf("%d %d has taken a fork\n",
		get_timestamp(philo->phl_main->start_time), philo->id);
	pthread_mutex_unlock(&philo->phl_main->print);
	pthread_mutex_lock(philo->fork_2);
	pthread_mutex_lock(&philo->phl_main->print);
	printf("%d %d has taken a fork\n",
		get_timestamp(philo->phl_main->start_time), philo->id);
	pthread_mutex_unlock(&philo->phl_main->print);
}

void	eating(t_philo *philo)
{
	if (philo->phl_main->death_flag < 0)
		return ;
	pthread_mutex_lock(&philo->phl_main->print);
	printf("%d %d is eating\n",
		get_timestamp(philo->phl_main->start_time), philo->id);
	pthread_mutex_unlock(&philo->phl_main->print);
	pthread_mutex_lock(&philo->phl_main->time_mute);
	philo->lst_eatng_time = get_timestamp(philo->phl_main->start_time);
	pthread_mutex_unlock(&philo->phl_main->time_mute);
	my_usleep((int)philo->phl_main->t2eat);
	if (philo->phl_main->n_args == 5)
	{
		pthread_mutex_lock(&philo->phl_main->p_cycles_mute);
		philo->n_cycles++;
		pthread_mutex_unlock(&philo->phl_main->p_cycles_mute);
	}
	pthread_mutex_unlock(philo->fork_2);
	pthread_mutex_unlock(philo->fork_1);
}

void	sleepeng(t_philo *philo, int d_flag)
{
	if (d_flag < 0)
		return ;
	pthread_mutex_lock(&philo->phl_main->print);
	printf("%d %d is sleeping\n",
		get_timestamp(philo->phl_main->start_time), philo->id);
	pthread_mutex_unlock(&philo->phl_main->print);
	my_usleep((int)philo->phl_main->t2sleep);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->phl_main->print);
	printf("%d %d is thinking\n",
		get_timestamp(philo->phl_main->start_time), philo->id);
	pthread_mutex_unlock(&philo->phl_main->print);
}

void	*lifecycle(void *tmp)
{
	t_philo	*philo;
	int		cycles;
	int		d_flag;

	philo = tmp;
	pthread_mutex_lock(&philo->phl_main->cycles_mute);
	cycles = philo->phl_main->n_cycles;
	pthread_mutex_unlock(&philo->phl_main->cycles_mute);
	pthread_mutex_lock(&philo->phl_main->death_mute);
	d_flag = philo->phl_main->death_flag;
	pthread_mutex_unlock(&philo->phl_main->death_mute);
	if ((philo->id) % 2 == 0)
	{
		thinking(philo);
		my_usleep((int)philo->phl_main->t2eat);
	}
	while (d_flag > 0 && philo->n_cycles != cycles)
	{
		if (d_flag > 0)
			taking_forks(philo);
		eating(philo);
		sleepeng(philo, d_flag);
	}
	return (NULL);
}
