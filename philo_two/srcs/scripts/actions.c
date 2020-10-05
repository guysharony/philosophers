#include "../includes/philo_two.h"

int     aeat(t_philos *tmp)
{
    sem_wait(tmp->fork);
    sem_wait(tmp->fork);
    tmp->eat = 1;
    sem_wait(tmp->write);
    dfork(tmp);
    dfork(tmp);
    deat(tmp);
    sem_post(tmp->write);
    tmp->ceat++;
    tmp->last = ft_time();
    usleep(tmp->params->tm_to_eat * 1000);
    tmp->eat = 0;
    sem_post(tmp->fork);
    sem_post(tmp->fork);
    return (tmp->stop);
}