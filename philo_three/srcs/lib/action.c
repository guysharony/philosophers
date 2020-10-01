#include "../includes/philosophers.h"

void        forks1(t_philos *tmp)
{
    sem_wait(tmp->params->fork);
    msg(tmp, "has taken a fork.");
    sem_wait(tmp->params->fork);
    msg(tmp, "has taken a fork.");
}

void        forks0(t_philos *tmp)
{
    sem_post(tmp->params->fork);
    sem_post(tmp->params->fork);
}

void        aeat(t_philos *tmp)
{
    if (tmp->params->end == 0)
    {
        forks1(tmp);
        tmp->eat = 1;
        msg(tmp, "is eating.");
        tmp->last = ft_time();
        usleep(tmp->params->tm_to_eat * 1000);
        tmp->ceat++;
        tmp->eat = 0;
        forks0(tmp);
    }
}

void        asleep(t_philos *tmp)
{
    if (tmp->params->end == 0)
    {
        msg(tmp, "is sleeping.");
        usleep(tmp->params->tm_to_sleep * 1000);
    }
}

void        athink(t_philos *tmp)
{
    if (tmp->params->end == 0)
        msg(tmp, "is thinking.");
}