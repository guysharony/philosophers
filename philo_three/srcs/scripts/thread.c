#include "../includes/philo_three.h"

void        sthr(t_philos *philo)
{
    pthread_t   tid;

    if (pthread_create(&tid, NULL, &mthread, philo))
        exit(0);
    pthread_detach(tid);
    while (!philo->params->end)
    {
        aeat(philo);
        if (philo->stop)
            exit(1);
        asleep(philo);
        athink(philo);
    }
    exit(2);
}

int         thr(t_philo_three *tmp)
{
    size_t      i;
    int         j;
    size_t      n;
    size_t      time;

    i = 0;
    n = 0;
    tmp->params->start = ft_time();
    while (i < tmp->params->nb_of_philosophers)
    {
        tmp->philo[i]->last = tmp->params->start;
        tmp->philo[i]->pid = fork();
        if (!tmp->philo[i]->pid)
            sthr(tmp->philo[i]);
        usleep(100);
        i++;
    }
    mglobal(tmp);
    return (0);
}
