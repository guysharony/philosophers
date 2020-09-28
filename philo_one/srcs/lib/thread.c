#include "../includes/philosophers.h"

void        *sthr(void *philo)
{
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        if (tmp->params->nb_eat_philo != -1)
            if (tmp->ceat >= tmp->params->nb_eat_philo)
                tmp->params->nw_eat--;
        aeat(tmp);
        asleep(tmp);
        athink(tmp);
    }
    return (NULL);
}

int         monitor(t_philo_one *philo_one)
{
    int         i;
    long long   t;

    while (1)
    {
        i = 0;
        while (i < philo_one->params->nb_of_philosophers)
        {
            t = ft_time();
            if ((philo_one->params->nb_eat_philo != -1 && philo_one->params->nw_eat <= 0) ||
            (philo_one->philo[i]->eat == 0 && (philo_one->philo[i]->last + philo_one->params->tm_to_die < t)))
            {
                if (philo_one->philo[i]->last + philo_one->params->tm_to_die < t)
                    msg(philo_one->philo[i], "is dead.");
                pthread_mutex_lock(&philo_one->params->write);
                return (0);
            }
            i++;
        }
        usleep(1000);
    }
}

int         thr(t_philo_one *philo_one)
{
    int         i;

    i = 0;
    philo_one->params->start = ft_time();
    while (i < philo_one->params->nb_of_philosophers)
    {
        philo_one->philo[i]->last = philo_one->params->start;
        if (pthread_create(&philo_one->philo[i]->thread, NULL, sthr, philo_one->philo[i]))
            return (err("Can't start threading."));
        pthread_detach(philo_one->philo[i]->thread);
        usleep(100);
        i++;
    }
    monitor(philo_one);
    return (0);
}