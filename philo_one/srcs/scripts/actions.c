/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guysharony <guysharony@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 08:14:27 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 13:01:38 by guysharony       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

int			aeat(t_philos *tmp)
{
	pthread_mutex_lock(tmp->rfork);
	pthread_mutex_lock(tmp->lfork);
	pthread_mutex_lock(tmp->params->write);
	msg(tmp, "has taken a fork.");
	msg(tmp, "has taken a fork.");
	msg(tmp, "is eating.");
	pthread_mutex_unlock(tmp->params->write);
	tmp->eat = 1;
	tmp->ceat++;
	tmp->last = ft_time();
	usleep(tmp->params->tm_to_eat * 1000);
	tmp->eat = 0;
	pthread_mutex_unlock(tmp->rfork);
	pthread_mutex_unlock(tmp->lfork);
	return (tmp->stop);
}

void		asleep(t_philos *tmp)
{
	pthread_mutex_lock(tmp->params->write);
	msg(tmp, "is sleeping.");
	pthread_mutex_unlock(tmp->params->write);
	usleep(tmp->params->tm_to_sleep * 1000);
}

void		athink(t_philos *tmp)
{
	pthread_mutex_lock(tmp->params->write);
	msg(tmp, "is thinking.");
	pthread_mutex_unlock(tmp->params->write);
}
