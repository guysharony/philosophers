#include "../includes/philo_two.h"

int         aeat(t_philos *tmp)
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
    return (tmp->stop);
}
