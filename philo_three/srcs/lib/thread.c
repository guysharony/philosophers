#include "../includes/philosophers.h"

void        *monitor(void *philo)
{
    t_philos    *tmp;
    long long   t;

    tmp = (t_philos*)philo;
    while (1)
    {
        t = ft_time();
        if ((tmp->params->nb_eat_philo != -1 && tmp->ceat >= tmp->params->nb_eat_philo) ||
        (tmp->eat == 0 && (tmp->last + tmp->params->tm_to_die < t)))
        {
            if (tmp->last + tmp->params->tm_to_die < t)
                msg(tmp, "is dead.");
            exit(0);
        }
        usleep(1000);
    }
    return (NULL);
}

int         routine(t_philos **philo)
{
    t_philos    *tmp;

    tmp = *philo;
    if (pthread_create(&tmp->monitor, NULL, monitor, tmp))
        return (err("Can't start threading."));
    pthread_detach(tmp->monitor);
    while (1)
    {
        aeat(tmp);
        asleep(tmp);
        athink(tmp);
    }
    return (0);
}

int         thr(t_philo_one *philo_one)
{
    int         i;
    int         t;

    i = 0;
    philo_one->params->start = ft_time();
    while (i < philo_one->params->nb_of_philosophers)
    {
        philo_one->philo[i]->last = philo_one->params->start;
        philo_one->philo[i]->proc = fork();
        if (philo_one->philo[i]->proc < 0)
            return (1);
        else if (philo_one->philo[i]->proc == 0)
        {
            routine(&philo_one->philo[i]);
            exit(0);
        }
        usleep(100);
        i++;
    }
    i = 0;
    while (i < philo_one->params->nb_of_philosophers)
    {
        
        waitpid(philo_one->philo[i]->proc, &t, 0);
        i++;
    }
    return (0);
}