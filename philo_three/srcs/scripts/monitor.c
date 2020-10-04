#include "../includes/philo_three.h"

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
    }
}