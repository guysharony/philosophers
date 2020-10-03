#include "../includes/philo_one.h"

void        *monitor(void *philo)
{
    size_t      time;
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        if (tmp->params->nb_eat_philo > 0 && tmp->ceat >= tmp->params->nb_eat_philo)
        {
            tmp->stop = 1;
            tmp->params->nw_eat--;
            return (NULL);
        }
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
    while (1)
    {
        aeat(tmp);
        if (tmp->stop)
            return (NULL);
        asleep(tmp);
        athink(tmp);
    }
    return (NULL);
}

int         thr(t_philo_one *philo_one)
{
    size_t      i;
    size_t      time;
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
    while (philo_one->params->nw_eat)
    {
        i = 0;
        while (i < philo_one->params->nb_of_philosophers)
        {
            time = ft_time();
            if (philo_one->params->nw_eat > 0 &&
            (!philo_one->philo[i]->eat && philo_one->philo[i]->last + philo_one->params->tm_to_die <= time))
            {
                msg(philo_one->philo[i], time, "is dead.");
                philo_one->params->nw_eat = 0;
            }
            i++;
        }
    }
    return (0);
}
