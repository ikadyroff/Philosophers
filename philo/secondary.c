/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:03:16 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/07 13:03:39 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long int	digit;
	int			znak;

	digit = 0;
	znak = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			znak = -1;
	}
	while (*str && *str > 47 && *str < 58)
	{
		digit = (digit * 10) + ((*str++) - 48);
		if (digit < 0)
		{
			if (znak < 0)
				return (0);
			return (-1);
		}
	}
	return (digit * znak);
}

int	exit_fn(int flag, pthread_mutex_t *forks,
			t_philo *philo, pthread_t *threads)
{
	if (forks != NULL)
	{
		free(forks);
		forks = NULL;
	}
	if (philo != NULL)
	{
		free(philo);
		philo = NULL;
	}
	if (threads != NULL)
	{
		free(threads);
		threads = NULL;
	}
	if (flag == 1)
		printf(RED "Error caused by memory allocation\n");
	if (flag == 2)
		printf(RED "Error caused by mutex initialization\n");
	if (flag == 3)
		printf(RED "Error caused by thread creation");
	return (3);
}

void	my_usleep(int ms)
{
	long	time;

	time = get_current_time() + ms;
	while (get_current_time() < time)
		usleep(10);
}

long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_timestamp(long t_start)
{
	return ((int)(get_current_time() - t_start));
}
