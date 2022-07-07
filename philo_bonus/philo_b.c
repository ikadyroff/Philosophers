/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni <wlouveni@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:15:33 by wlouveni          #+#    #+#             */
/*   Updated: 2022/06/16 11:59:05 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_b.h"

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

int	main(int argc, char **argv)
{
	t_main			main;

	if (arg_handling(argc, argv, &main) != 0)

		return (1);

}