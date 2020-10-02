#include "../includes/philo_two.h"

void        fork1(t_philos *philo)
{
    sem_wait(philo->params->fork);
    msg(philo, "has taken a fork.");
    sem_wait(philo->params->fork);
    msg(philo, "has taken a fork.");
}

void        fork0(t_philos *philo)
{
    sem_post(philo->params->fork);
    sem_post(philo->params->fork);
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
