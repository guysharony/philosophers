#include "../includes/philo_two.h"

void        aeat(t_philos *tmp)
{
    sem_wait(tmp->fork);
    sem_wait(tmp->fork);
    sem_wait(tmp->write);
    msg(tmp, "has taken a fork.");
    msg(tmp, "has taken a fork.");
    msg(tmp, "is eating.");
    sem_post(tmp->write);
    tmp->eat = 1;
    tmp->ceat++;
    tmp->last = ft_time();
    usleep(tmp->params->tm_to_eat * 1000);
    tmp->eat = 0;
    sem_post(tmp->fork);
    sem_post(tmp->fork);
}

void        asleep(t_philos *tmp)
{
    sem_wait(tmp->write);
    msg(tmp, "is sleeping.");
    sem_post(tmp->write);
    usleep(tmp->params->tm_to_sleep * 1000);
}

void        athink(t_philos *tmp)
{
    sem_wait(tmp->write);
    msg(tmp, "is thinking.");
    sem_post(tmp->write);
}
