#include "../includes/philo_one.h"

void        fork1(t_philos *philo)
{
    pthread_mutex_lock(philo->rfork);
    msg(philo, "has taken a fork.");
    pthread_mutex_lock(philo->lfork);
    msg(philo, "has taken a fork.");
}

void        fork0(t_philos *philo)
{
    pthread_mutex_unlock(philo->rfork);
    pthread_mutex_unlock(philo->lfork);
}

int         eat(t_philos *tmp)
{
    int     i;

    fork1(tmp);
    if (!(i = msg(tmp, "is eating.")))
    {
        tmp->eat = 1;
        tmp->ceat++;
        tmp->last = ft_time();
        usleep(tmp->params->tm_to_eat * 1000);
        tmp->eat = 0;
    }
    fork0(tmp);
    return (i);
}
