#include "../includes/philo_one.h"

void        fork1(t_philos *philo)
{
    pthread_mutex_lock(philo->rfork);
    msg(philo, ft_time(), "has taken a fork.");
    pthread_mutex_lock(philo->lfork);
    msg(philo, ft_time(), "has taken a fork.");
}

void        fork0(t_philos *philo)
{
    pthread_mutex_unlock(philo->rfork);
    pthread_mutex_unlock(philo->lfork);
}

void        aeat(t_philos *tmp)
{
    int     i;

    fork1(tmp);
    tmp->last = ft_time();
    msg(tmp, tmp->last, "is eating.");
    tmp->eat = 1;
    tmp->ceat++;
    usleep(tmp->params->tm_to_eat * 1000);
    tmp->eat = 0;
    fork0(tmp);
}

void        asleep(t_philos *tmp)
{
    msg(tmp, ft_time(), "is sleeping.");
    usleep(tmp->params->tm_to_sleep * 1000);
}

void        athink(t_philos *tmp)
{
    msg(tmp, ft_time(), "is thinking.");
}
