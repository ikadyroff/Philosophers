/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:09:15 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/15 13:27:35 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_handling(int argc, char **argv, t_main *main)
{
	int	i;
	int	*num_arr;

	num_arr = (int *)malloc((argc) * sizeof(int));
	if (argc < 5 || argc > 6)
	{
		printf(RED "Error!\nWrong number of arguments\
				\ne.g.: ./philo 5 800 200 200.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		num_arr[i] = ft_atoi(argv[i]);
		if (num_arr[i] <= 0)
		{
			printf(RED "Error!\nArgumens should be > 0.\n");
			return (2);
		}
		fill_main_struct_1(i, num_arr[i], main);
		i++;
	}
	main->n_args = argc - 1;
	free(num_arr);
	return (0);
}

void	mutex_assignment(long *l_e_t, int *cycles, t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->phl_main->cycles_mute);
	*cycles = philo->phl_main->n_cycles;
	pthread_mutex_unlock(&philo->phl_main->cycles_mute);
	pthread_mutex_lock(&philo->phl_main->time_mute);
	*l_e_t = philo[i].lst_eatng_time;
	pthread_mutex_unlock(&philo->phl_main->time_mute);
	pthread_mutex_lock(&philo->phl_main->print);
	pthread_mutex_unlock(&philo->phl_main->print);
}

int	is_dead(t_philo *philo, t_main *main, int i)
{
	long	l_e_t;
	int		cycles;
	int		p_cycles;

	mutex_assignment(&l_e_t, &cycles, philo, i);
	pthread_mutex_lock(&philo->phl_main->p_cycles_mute);
	p_cycles = philo[i].n_cycles;
	pthread_mutex_unlock(&philo->phl_main->p_cycles_mute);
	if (main->t2die <= get_timestamp(main->start_time) - l_e_t)
	{
		pthread_mutex_lock(&main->death_mute);
		main->death_flag = -1;
		pthread_mutex_unlock(&main->death_mute);
		pthread_mutex_lock(&philo->phl_main->print);
		printf(RED "%d %d died\n",
			get_timestamp(philo->phl_main->start_time), philo->id);
		return (1);
	}
	if (p_cycles == cycles)
	{
		main->completed_cycles++;
		if (main->completed_cycles == main->n_phlsphrs)
			return (1);
	}
	return (0);
}

void	*tracking_funct(void *tmp)
{
	t_philo	*philo;
	t_main	*main;
	int		i;

	philo = tmp;
	main = philo[0].phl_main;
	while (main->death_flag > 0)
	{
		i = 0;
		while (i < main->n_phlsphrs)
		{
			if (is_dead(philo, main, i))
				return (0);
			i++;
			my_usleep(1);
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_main			main;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	if (arg_handling(argc, argv, &main) != 0)
		return (1);
	forks = malloc(sizeof(pthread_mutex_t) * main.n_phlsphrs);
	if (forks == NULL)
		return (exit_fn(1, NULL, NULL, NULL));
	philo = malloc(sizeof(t_philo) * main.n_phlsphrs);
	if (philo == NULL)
		return (exit_fn(1, NULL, NULL, NULL));
	main.threads = malloc(sizeof(pthread_t) * main.n_phlsphrs);
	if (main.threads == NULL)
		return (exit_fn(3, forks, philo, main.threads));
	if (fill_main_struct_2(&main) != 0)
		return (exit_fn(2, forks, philo, main.threads));
	if (philo_init(&main, forks, philo) != 0)
		return (exit_fn(3, forks, philo, main.threads));
	tracking_funct((void *)philo);
	sleep(1);
	jn_dstr_fr(main, philo, forks);
	return (0);
}
