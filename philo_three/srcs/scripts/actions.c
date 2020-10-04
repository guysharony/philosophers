#include "../includes/philo_three.h"

void        fork1(t_philos *philo)
{
    sem_wait(philo->params->fork);
    sem_wait(philo->params->fork);
    msg(philo, "has taken a fork.");
    msg(philo, "has taken a fork.");
}

void        fork0(t_philos *philo)
{
    sem_post(philo->params->fork);
    sem_post(philo->params->fork);
}

void        aeat(t_philos *tmp)
{
    fork1(tmp);
    msg(tmp, "is eating.");
    tmp->eat = 1;
    tmp->ceat++;
    tmp->last = ft_time();
    usleep(tmp->params->tm_to_eat * 1000);
    tmp->eat = 0;
    fork0(tmp);
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
