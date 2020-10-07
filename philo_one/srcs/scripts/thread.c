/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:37:04 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 15:56:03 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void		*sthr(void *philo)
{
	t_philos	*tmp;
	pthread_t	tid;

	tmp = (t_philos*)philo;
	if (pthread_create(&tid, NULL, &mthread, tmp))
		return (NULL);
	pthread_detach(tid);
	while (1)
	{
		if (aeat(tmp))
			return (NULL);
		asleep(tmp);
		athink(tmp);
	}
	return (NULL);
}

int			thr(t_philo_one *philo_one)
{
	size_t		i;
	pthread_t	tid;

	i = 0;
	philo_one->params->start = ft_time();
	while (i < philo_one->params->nb_of_philosophers)
	{
		philo_one->philo[i]->last = philo_one->params->start;
		if (pthread_create(&tid, NULL, &sthr, philo_one->philo[i]))
			return (err("A problem with pthread_create() in \'thread.c\'.", 0));
		pthread_detach(tid);
		usleep(100);
		i++;
	}
	mglobal(philo_one);
	return (0);
}
