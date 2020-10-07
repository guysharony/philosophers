/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:57:58 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 16:10:32 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	*mthread(void *philo)
{
	size_t		time;
	t_philos	*tmp;

	tmp = (t_philos*)philo;
	while (1)
	{
		time = ft_time();
		if ((tmp->params->nb_eat_philo > 0 &&
		tmp->ceat >= tmp->params->nb_eat_philo) ||
		(!tmp->eat && tmp->last + tmp->params->tm_to_die < time))
		{
			tmp->stop = 1;
			if (tmp->last + tmp->params->tm_to_die < time)
				exit(2);
			return (NULL);
		}
		usleep(100);
	}
}

void	killeveryone(t_philo_three *tmp)
{
	size_t	i;

	i = 0;
	while (i < tmp->params->nb_of_philosophers)
	{
		kill(tmp->philo[i]->pid, SIGKILL);
		i++;
	}
}

int		status(t_philos *philo)
{
	static int	n;
	int			j;

	j = 0;
	waitpid(philo->pid, &j, WNOHANG);
	if (WIFEXITED(j))
	{
		if (WEXITSTATUS(j) == 1)
		{
			n++;
			if (n >= philo->params->nb_of_philosophers)
				return (1);
		}
		else if (WEXITSTATUS(j) == 2)
			return (2);
	}
	return (0);
}

int		mglobal(t_philo_three *tmp)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < tmp->params->nb_of_philosophers)
	{
		if ((j = status(tmp->philo[i])) > 0)
		{
			if (j == 1)
				return (1);
			msg(tmp->philo[i], "is dead.");
			killeveryone(tmp);
			return (2);
		}
		i++;
		if (i == tmp->params->nb_of_philosophers)
			i = 0;
	}
	return (0);
}
