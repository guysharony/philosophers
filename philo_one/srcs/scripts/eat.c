#include "../includes/philo_one.h"

int         eat(t_philos *tmp)
{
    int     i;

    pthread_mutex_lock(tmp->rfork);
    msg(tmp, "has taken a fork.", 0);
    pthread_mutex_lock(tmp->lfork);
    msg(tmp, "has taken a fork.", 0);
    if (!(i = msg(tmp, "is eating.", 0)))
    {
        tmp->eat = 1;
        tmp->ceat++;
        tmp->last = ft_time();
        usleep(tmp->params->tm_to_eat * 1000);
        tmp->eat = 0;
    }
    pthread_mutex_unlock(tmp->rfork);
    pthread_mutex_unlock(tmp->lfork);
    return (i);
}
