#include "../includes/philo_two.h"

void        aeat(t_philos *tmp)
{
    sem_wait(tmp->params->fork);
    sem_wait(tmp->params->fork);
    msg(tmp, "has taken a fork.");
    msg(tmp, "has taken a fork.");
    msg(tmp, "is eating.");
    tmp->eat = 1;
    tmp->ceat++;
    tmp->last = ft_time();
    usleep(tmp->params->tm_to_eat * 1000);
    tmp->eat = 0;
    sem_post(tmp->params->fork);
    sem_post(tmp->params->fork);
}

void        asleep(t_philos *tmp)
{
    msg(tmp, "is sleeping.");
    usleep(tmp->params->tm_to_sleep * 1000);
}

void        athink(t_philos *tmp)
{
    msg(tmp, "is thinking.");
}