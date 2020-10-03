#include "../includes/philo_two.h"

void        *mthread(void *philo)
{
    size_t      time;
    t_philos    *tmp;

    tmp = (t_philos*)philo;
    while (1)
    {
        if (tmp->params->nb_eat_philo > 0 && tmp->ceat >= tmp->params->nb_eat_philo)
        {
            tmp->stop = 1;
            tmp->params->nw_eat--;
            return (NULL);
        }
        usleep(1000);
    }
}

void    mglobal(t_philo_two *tmp)
{
    size_t  time;
    size_t  i;

    while (tmp->params->nw_eat)
    {
        i = 0;
        while (i < tmp->params->nb_of_philosophers)
        {
            time = ft_time();
            if (tmp->params->nw_eat > 0 &&
            (!tmp->philo[i]->eat && tmp->philo[i]->last + tmp->params->tm_to_die < time))
            {
                msg(tmp->philo[i], "is dead.");
                tmp->params->nw_eat = 0;
            }
            i++;
        }
        usleep(1000);
    }
}