/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:02:01 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 17:26:01 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void		sthr(t_philos *philo)
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, &mthread, philo))
		exit(0);
	pthread_detach(tid);
	while (1)
	{
		if (aeat(philo))
			exit(1);
		asleep(philo);
		athink(philo);
	}
	exit(2);
}

int			thr(t_philo_three *tmp)
{
	size_t		i;

	i = 0;
	tmp->params->start = ft_time();
	while (i < tmp->params->nb_of_philosophers)
	{
		tmp->philo[i]->last = tmp->params->start;
		tmp->philo[i]->pid = fork();
		if (!tmp->philo[i]->pid)
			sthr(tmp->philo[i]);
		i++;
	}
	mglobal(tmp);
	return (0);
}
