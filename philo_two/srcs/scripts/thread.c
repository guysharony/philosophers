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
        aeat(tmp);
        asleep(tmp);
        athink(tmp);
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
        usleep(50);
        i++;
    }
    mglobal(tmp);
    return (0);
}
