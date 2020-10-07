/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:56:36 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 15:13:57 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		clean(t_philo_three *tmp)
{
	size_t	i;

	i = 0;
	while (i < tmp->params->nb_of_philosophers)
	{
		free(tmp->philo[i]);
		i++;
	}
	sem_unlink("fork");
	free(tmp->philo);
	free(tmp->params);
	free(tmp);
	return (1);
}

int		args(int argc, char **argv)
{
	if (argc < 5)
		return (err("Too few arguments.", 1));
	if (argc > 6)
		return (err("Too many arguments.", 1));
	if (are_numbers(argc, argv))
		return (err("Arguments must be positive numbers.", 0));
	if (ft_atoi(argv[1]) < 2)
		return (err("At least 2 philosophers are requered.", 0));
	return (0);
}

int		main(int argc, char **argv)
{
	t_philo_three	*philo_three;

	if (args(argc, argv))
		return (1);
	if ((philo_three = init(argc, argv)) == NULL)
		return (clean(philo_three) && err("A problem with malloc.", 0));
	thr(philo_three);
	clean(philo_three);
	return (0);
}
