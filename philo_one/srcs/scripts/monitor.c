#include "../includes/philo_one.h"

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

void    mglobal(t_philo_one *philo_one)
{
    size_t  time;
    size_t  i;

    while (philo_one->params->nw_eat)
    {
        i = 0;
        while (i < philo_one->params->nb_of_philosophers)
        {
            time = ft_time();
            if (philo_one->params->nw_eat > 0 &&
            (!philo_one->philo[i]->eat && philo_one->philo[i]->last + philo_one->params->tm_to_die < time))
            {
                msg(philo_one->philo[i], "is dead.");
                philo_one->params->nw_eat = 0;
            }
            i++;
        }
        usleep(1000);
    }
}