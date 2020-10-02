#include "../includes/philo_two.h"

int         eat(t_philos *tmp)
{
    int     i;

    sem_wait(tmp->params->fork);
    sem_wait(tmp->params->fork);
    msg(tmp, "has taken a fork.", 0);
    msg(tmp, "has taken a fork.", 0);
    if (!(i = msg(tmp, "is eating.", 0)))
    {
        tmp->eat = 1;
        tmp->ceat++;
        tmp->last = ft_time();
        usleep(tmp->params->tm_to_eat * 1000);
        tmp->eat = 0;
    }
    sem_post(tmp->params->fork);
    sem_post(tmp->params->fork);
    return (i);
}
