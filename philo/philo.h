/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:09:17 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/16 11:16:46 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

# define RED	"\x1b[31m"

typedef struct s_main
{
	int				death_flag;
	int				n_phlsphrs;
	long			t2die;
	long			t2eat;
	long			t2sleep;
	long			start_time;
	int				n_cycles;
	int				completed_cycles;
	int				n_args;
	pthread_t		tracking;
	pthread_t		*threads;
	pthread_mutex_t	time_mute;
	pthread_mutex_t	death_mute;
	pthread_mutex_t	cycles_mute;
	pthread_mutex_t	p_cycles_mute;
	pthread_mutex_t	print;
}	t_main;

typedef struct s_philo
{
	int				n_cycles;
	int				id;
	int				n_phlsphrs;
	long			lst_eatng_time;
	pthread_mutex_t	*fork_2;
	pthread_mutex_t	*fork_1;
	t_main			*phl_main;
}	t_philo;

// secondary
int		ft_atoi(const char *str);
int		exit_fn(int flag, pthread_mutex_t *forks,
			t_philo *philo, pthread_t *threads);
int		get_timestamp(long t_start);
long	get_current_time(void);
void	my_usleep(int ms);

// actions
void	taking_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleepeng_thinging(t_philo *philo);
void	*lifecycle(void *tmp);

// init
void	fill_main_struct_1(int i, int arg, t_main *main);
int		init_mutex(pthread_mutex_t time_mute, pthread_mutex_t print);
int		fill_main_struct_2(t_main *main);
int		philo_init(t_main *main, pthread_mutex_t *forks, t_philo *philo);

// secondary_2
long	get_time(t_main *main);
void	mutex_destroy(t_main *main, pthread_mutex_t *forks);
void	destroy_forks(pthread_mutex_t *forks, int n);
void	jn_dstr_fr(t_main main, t_philo *philo, pthread_mutex_t	*forks);
void	joining_threads(t_main *main);
#endif