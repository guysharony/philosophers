#include "../includes/philo_two.h"

void        *monitor(void *philo)
{
    size_t      time;
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        time = ft_time();
        if (!tmp->eat && tmp->last + tmp->params->tm_to_die <= time)
        {
            msg(tmp, "is dead.", 1);
            sem_unlink("write");
            tmp->stop = 1;
            tmp->params->nw_eat = 0;
            return (NULL);
        }
        if (tmp->params->end || tmp->ceat >= tmp->params->nb_eat_philo)
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
    while (!tmp->stop)
    {
        if (eat(tmp))
            return (NULL);
        if (!(msg(tmp, "is sleeping.", 0)))
    	    usleep(tmp->params->tm_to_sleep * 1000);
        msg(tmp, "is thinking.", 0);
    }
    return (NULL);
}

int         thr(t_philo_two *philo_one)
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
        usleep(50);
        i++;
    }
    while (!philo_one->params->end)
    {
        if (philo_one->params->nw_eat <= 0)
            philo_one->params->end = 1;
    }
    return (0);
}
