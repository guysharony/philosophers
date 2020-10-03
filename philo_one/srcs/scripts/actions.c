#include "../includes/philo_one.h"

void        aeat(t_philos *tmp)
{
    pthread_mutex_lock(tmp->rfork);
    msg(tmp, "has taken a fork.");
    pthread_mutex_lock(tmp->lfork);
    msg(tmp, "has taken a fork.");
    msg(tmp, "is eating.");
    tmp->eat = 1;
    tmp->ceat++;
    tmp->last = ft_time();
    usleep(tmp->params->tm_to_eat * 1000);
    tmp->eat = 0;
    pthread_mutex_unlock(tmp->rfork);
    pthread_mutex_unlock(tmp->lfork);
}
