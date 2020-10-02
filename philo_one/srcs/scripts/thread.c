#include "../includes/philo_one.h"

int         status(t_philos *tmp)
{
    if (tmp->last + tmp->params->tm_to_die <= ft_time())
        return (1);
    if (tmp->ceat >= tmp->params->nb_eat_philo)
        return (2);
    return (0);
}

void        *monitor(void *philo)
{
    int         i;
    size_t      time;
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        if ((i = status(tmp)))
        {
            if (i == 1)
            {
                msg(tmp, "is dead.");
                pthread_mutex_lock(tmp->params->write);
                tmp->params->nw_eat = 0;
            }
            else
            {
                tmp->stop = 1;
                tmp->params->nw_eat--;
            }
            return (NULL);
        }
	usleep(1000);
    }
}

void        *sthr(void *philo)
{
    t_philos    *tmp;
    pthread_t   tid;

    tmp = (t_philos*)philo;
    if (pthread_create(&tid, NULL, &monitor, tmp))
        return (NULL);
    pthread_detach(tid);
    while (!tmp->stop)
    {
        if (aeat(tmp))
            return (NULL);
        asleep(tmp);
        athink(tmp);
    }
    return (NULL);
}

int         thr(t_philo_one *philo_one)
{
    size_t      i;
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
    while (!philo_one->params->end)
    {
        if (philo_one->params->nw_eat <= 0)
            philo_one->params->end = 1;
	usleep(1000);
    }
    return (0);
}
