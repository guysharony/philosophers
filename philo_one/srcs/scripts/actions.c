#include "../includes/philo_one.h"

void        forks1(t_philos *tmp)
{
    pthread_mutex_lock(tmp->params->fork[tmp->rfork - 1]);
    msg(tmp, "has taken a fork.");
    pthread_mutex_lock(tmp->params->fork[tmp->lfork - 1]);
    msg(tmp, "has taken a fork.");
}

void        forks0(t_philos *tmp)
{
    pthread_mutex_unlock(tmp->params->fork[tmp->rfork - 1]);
    pthread_mutex_unlock(tmp->params->fork[tmp->lfork - 1]);
}

void        aeat(t_philos *tmp)
{
    if (!tmp->params->end)
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
    if (!tmp->params->end)
    {
        msg(tmp, "is sleeping.");
        usleep(tmp->params->tm_to_sleep * 1000);
    }
}

void        athink(t_philos *tmp)
{
    if (!tmp->params->end)
        msg(tmp, "is thinking.");
}