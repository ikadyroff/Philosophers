/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:08:37 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/16 12:09:28 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"

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
