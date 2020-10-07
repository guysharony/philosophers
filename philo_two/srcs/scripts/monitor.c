/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:22:08 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 16:12:12 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void		*mthread(void *philo)
{
	size_t		time;
	t_philos	*tmp;

	tmp = (t_philos*)philo;
	while (1)
	{
		time = ft_time();
		if ((!tmp->eat && tmp->last + tmp->params->tm_to_die <= time) ||
		(tmp->params->nb_eat_philo > 0 &&
		tmp->ceat >= tmp->params->nb_eat_philo))
		{
			tmp->stop = 1;
			if (tmp->last + tmp->params->tm_to_die <= time)
			{
				sem_wait(tmp->write);
				msg(tmp, "is dead.");
				tmp->params->nw_eat = 0;
			}
			else
				tmp->params->nw_eat--;
			return (NULL);
		}
		usleep(100);
	}
}

void		mglobal(t_philo_two *philo_two)
{
	while (1)
		if (philo_two->params->nw_eat <= 0)
			break ;
}
