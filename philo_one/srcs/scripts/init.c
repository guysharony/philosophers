#include "../includes/philo_one.h"

int             init_options(t_philo_one *tmp, int argc, char **argv)
{
    size_t      i;

    i = 0;
    if (!(tmp->params = malloc(sizeof(t_params))))
        return (1);
    if (!(tmp->params->fork = malloc(sizeof(pthread_mutex_t*) * ft_atoi(argv[1]))))
        return (1);
    tmp->params->nb_of_philosophers = ft_atoi(argv[1]);
    tmp->params->nw_eat = tmp->params->nb_of_philosophers;
    tmp->params->tm_to_die = ft_atoi(argv[2]);
    tmp->params->tm_to_eat = ft_atoi(argv[3]);
    tmp->params->tm_to_sleep = ft_atoi(argv[4]);
    tmp->params->end = 0;
    while (i < tmp->params->nb_of_philosophers)
    {
        if (!(tmp->params->fork[i] = malloc(sizeof(pthread_mutex_t))))
            return (1);
        pthread_mutex_init(tmp->params->fork[i], NULL);
        i++;
    }
    tmp->params->nb_eat_philo = -1;
    if (argc == 6)
        tmp->params->nb_eat_philo = ft_atoi(argv[5]);
    return (0);
}

int             init_philos(t_philo_one *philo_one, int size)
{
    int         i;

    i = 0;
    if (!(philo_one->philo = malloc(sizeof(t_philos*) * size)))
        return (1);
    while (i < size)
    {
        if (!(philo_one->philo[i] = malloc(sizeof(t_philos))))
            return (1);
        philo_one->philo[i]->id = i + 1;
        philo_one->philo[i]->rfork = philo_one->params->fork[i];
        philo_one->philo[i]->lfork = philo_one->params->fork[((i + 1) % size)];
        philo_one->philo[i]->params = philo_one->params;
        philo_one->philo[i]->ceat = 0;
        philo_one->philo[i]->last = 0;
        philo_one->philo[i]->eat = 0;
        philo_one->philo[i]->stop = 0;
        i++;
    }
    return (0);
}

t_philo_one     *init(int argc, char **argv)
{
    t_philo_one     *tmp;

    if (!(tmp = malloc(sizeof(t_philo_one))))
        return (NULL);
    if (init_options(tmp, argc, argv))
        return (NULL);
    if (init_philos(tmp, tmp->params->nb_of_philosophers))
        return (NULL);
    return (tmp);
}
