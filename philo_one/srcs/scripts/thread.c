#include "../includes/philo_one.h"

void        *sthr(void *philo)
{
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
      	pthread_mutex_lock(tmp->params->fork[tmp->rfork - 1]);
	msg(tmp, "has taken a fork.");
	pthread_mutex_lock(tmp->params->fork[tmp->lfork - 1]);
	msg(tmp, "has taken a fork.");
	msg(tmp, "is eating.");
	usleep(tmp->params->tm_to_eat * 1000);
	tmp->ceat++;
	pthread_mutex_unlock(tmp->params->fork[tmp->rfork - 1]);
	pthread_mutex_unlock(tmp->params->fork[tmp->lfork - 1]);
	if (tmp->ceat >= tmp->params->nb_eat_philo)
	{
		tmp->params->nw_eat--;
		return (NULL);
	}
	msg(tmp, "is sleeping.");
	usleep(tmp->params->tm_to_sleep * 1000);
	msg(tmp, "is thinking.");
    }
    return (NULL);
}

int         thr(t_philo_one *philo_one)
{
    size_t      i;
    size_t      t;
    pthread_t   tid;

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
    while (1)
    {
	if (philo_one->params->nw_eat <= 0)
	{
		usleep(1000);
		return (0);
	}
	usleep(1000);
    }
    return (0);
}
