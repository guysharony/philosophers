#include "../includes/philo_two.h"

void        *mthread(void *philo)
{
    size_t      time;
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        time = ft_time();
        if ((!tmp->eat && tmp->last + tmp->params->tm_to_die < time) ||
        (tmp->params->nb_eat_philo > 0 && tmp->ceat >= tmp->params->nb_eat_philo))
        {
            tmp->stop = 1;
            if (tmp->last + tmp->params->tm_to_die < time)
            {
                sem_wait(tmp->params->write);
                msg(tmp, "is dead.");
                tmp->params->nw_eat = 0;
            }
            else
                tmp->params->nw_eat--;
            return (NULL);
        }
        usleep(1000);
    }
}

void    mglobal(t_philo_two *philo_two)
{
    while (1)
    {
        if (philo_two->params->nw_eat <= 0)
            break;
        usleep(1000);
    }
}