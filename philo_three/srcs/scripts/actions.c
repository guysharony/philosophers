/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:48:00 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 15:14:14 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

int		aeat(t_philos *tmp)
{
	sem_wait(tmp->fork);
	sem_wait(tmp->fork);
	tmp->eat = 1;
	sem_wait(tmp->write);
	msg(tmp, "has taken a fork.");
	msg(tmp, "has taken a fork.");
	msg(tmp, "is eating.");
	sem_post(tmp->write);
	tmp->ceat++;
	tmp->last = ft_time();
	usleep(tmp->params->tm_to_eat * 1000);
	tmp->eat = 0;
	sem_post(tmp->fork);
	sem_post(tmp->fork);
	return (tmp->stop);
}
