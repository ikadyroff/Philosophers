/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:15:56 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/16 12:07:59 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <stdio.h>

# define RED	"\x1b[31m"

typedef struct s_main
{
	int				n_phlsphrs;
	long			t2die;
	long			t2eat;
	long			t2sleep;
	long			start_time;
	int				n_cycles;
	int				n_args;
}	t_main;


#endif