#include "../includes/philo_two.h"

void        *sthr(void *philo)
{
    t_philos    *tmp;
    pthread_t   tid;

    tmp = (t_philos*)philo;
    if (pthread_create(&tid, NULL, &mthread, tmp))
        return (NULL);
    pthread_detach(tid);
    while (1)
    {
        sem_wait(tmp->params->fork);
        sem_wait(tmp->params->fork);
        sem_wait(tmp->params->write);
        msg(tmp, "has taken a fork.");
        msg(tmp, "has taken a fork.");
        sem_post(tmp->params->write);
        sem_wait(tmp->params->write);
        msg(tmp, "is eating.");
        sem_post(tmp->params->write);
        tmp->eat = 1;
        tmp->ceat++;
        tmp->last = ft_time();
        usleep(tmp->params->tm_to_eat * 1000);
        tmp->eat = 0;
        sem_post(tmp->params->fork);
        sem_post(tmp->params->fork);
        sem_wait(tmp->params->write);
        msg(tmp, "is sleeping.");
        sem_post(tmp->params->write);
        usleep(tmp->params->tm_to_sleep * 1000);
        sem_wait(tmp->params->write);
        msg(tmp, "is thinking.");
        sem_post(tmp->params->write);
    }
    return (NULL);
}

int         thr(t_philo_two *tmp)
{
    size_t      i;
    pthread_t   tid;

    i = 0;
    tmp->params->start = ft_time();
    while (i < tmp->params->nb_of_philosophers)
    {
        tmp->philo[i]->last = tmp->params->start;
        if (pthread_create(&tid, NULL, &sthr, tmp->philo[i]))
            return (err("A problem with pthread_create() in \'thread.c\'.", 0));
        pthread_detach(tid);
        usleep(100);
        i++;
    }
    mglobal(tmp);
    return (0);
}
