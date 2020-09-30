#include "../includes/philo_one.h"

void        *monitor(void *philo)
{
    t_philos    *tmp;
    size_t      time;

    tmp = (t_philos*)philo;
    while (1)
    {
        time = ft_time();
        if (tmp->last + tmp->params->tm_to_die < time)
        {
            tmp->params->end = 1;
            msg(tmp, "is dead.");
            return (NULL);
        }
    }
    return (NULL);
}

void        *sthr(void *philo)
{
    t_philos    *tmp;
    pthread_t   thread;

    tmp = (t_philos*)philo;
    if (pthread_create(&thread, NULL, &monitor, tmp) != 0) 
        return (NULL);
    pthread_detach(thread);
    while (!tmp->params->end)
    {
        aeat(tmp);
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
    while (1)
    {
        if (philo_one->params->end)
            break;
    }
    return (0);
}
