#include "../includes/philo_two.h"

void        *mthread(void *philo)
{
    size_t      time;
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        time = ft_time();
        if (!tmp->eat && tmp->last + tmp->params->tm_to_die < time)
        {
            sem_wait(tmp->write);
            msg(tmp, "is dead.");
            tmp->params->nw_eat = 0;
            break;
        }
        if (tmp->params->nb_eat_philo > 0 && tmp->ceat >= tmp->params->nb_eat_philo)
        {
            tmp->params->nw_eat--;
            break;
        }
    }
    return (NULL);
}

void    mglobal(t_philo_two *philo_one)
{
    while (1)
        if (philo_one->params->nw_eat <= 0)
            break;
}