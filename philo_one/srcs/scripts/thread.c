#include "../includes/philo_one.h"

void        *sthr(void *philo)
{
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (tmp->ceat < tmp->params->nb_eat_philo)
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
        i = 0;
        while (i < philo_one->params->nb_of_philosophers)
        {
            t = ft_time();
            if (philo_one->philo[i]->last + philo_one->params->tm_to_die < t)
            {
                msg(philo_one->philo[i], "is dead.");
                pthread_mutex_lock(philo_one->params->write);
                return (0);
            }
            i++;
        }
        usleep(1000);
    }
    return (0);
}
