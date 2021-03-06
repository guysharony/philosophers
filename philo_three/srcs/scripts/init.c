/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:49:12 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 15:47:54 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int				init_semaphore(sem_t **fork, sem_t **write, size_t size)
{
	sem_unlink("fork");
	sem_unlink("write");
	if ((*fork = sem_open("fork", O_CREAT, S_IRWXU, size)) < 0)
		return (1);
	if ((*write = sem_open("write", O_CREAT, S_IRWXU, 1)) < 0)
		return (1);
	return (0);
}

int				init_options(t_philo_three *tmp, int argc, char **argv)
{
	if (!(tmp->params = malloc(sizeof(t_params))))
		return (1);
	tmp->params->nb_of_philosophers = ft_atoi(argv[1]);
	tmp->params->nw_eat = tmp->params->nb_of_philosophers;
	tmp->params->tm_to_die = ft_atoi(argv[2]);
	tmp->params->tm_to_eat = ft_atoi(argv[3]);
	tmp->params->tm_to_sleep = ft_atoi(argv[4]);
	tmp->params->end = 0;
	tmp->params->nb_eat_philo = -1;
	if (argc == 6)
		tmp->params->nb_eat_philo = ft_atoi(argv[5]);
	return (0);
}

int				init_philos(t_philo_three *tmp, int size)
{
	int			i;
	sem_t		*fork;
	sem_t		*write;

	i = 0;
	init_semaphore(&fork, &write, size);
	if (!(tmp->philo = malloc(sizeof(t_philos*) * size)))
		return (1);
	while (i < size)
	{
		if (!(tmp->philo[i] = malloc(sizeof(t_philos))))
			return (1);
		tmp->philo[i]->id = i + 1;
		tmp->philo[i]->params = tmp->params;
		tmp->philo[i]->fork = fork;
		tmp->philo[i]->write = write;
		tmp->philo[i]->ceat = 0;
		tmp->philo[i]->last = 0;
		tmp->philo[i]->eat = 0;
		tmp->philo[i]->stop = 0;
		i++;
	}
	return (0);
}

t_philo_three	*init(int argc, char **argv)
{
	t_philo_three	*tmp;

	if (!(tmp = malloc(sizeof(t_philo_three))))
		return (NULL);
	if (init_options(tmp, argc, argv))
		return (NULL);
	if (init_philos(tmp, tmp->params->nb_of_philosophers))
		return (NULL);
	return (tmp);
}
