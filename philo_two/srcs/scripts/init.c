#include "../includes/philo_two.h"

int             init_options(t_philo_two *tmp, int argc, char **argv)
{
    if (!(tmp->params = malloc(sizeof(t_params))))
        return (1);
    tmp->params->nb_of_philosophers = ft_atoi(argv[1]);
    tmp->params->nw_eat = tmp->params->nb_of_philosophers;
    tmp->params->tm_to_die = ft_atoi(argv[2]);
    tmp->params->tm_to_eat = ft_atoi(argv[3]);
    tmp->params->tm_to_sleep = ft_atoi(argv[4]);
    tmp->params->end = 0;
    tmp->params->nb_eat_philo = -1;
    if (argc == 6)
        tmp->params->nb_eat_philo = ft_atoi(argv[5]);
    return (0);
}

int             init_philos(t_philo_two *tmp, int size)
{
    size_t      i;
    size_t      j;
    sem_t       *fork;
    sem_t       *write;

    sem_unlink("fork");
    if ((fork = sem_open("fork", O_CREAT, S_IRWXU, tmp->params->nb_of_philosophers)) < 0)
        return (1);
    sem_unlink("write");
    if ((write = sem_open("write", O_CREAT, S_IRWXU, 1)) < 0)
        return (1);
    if (!(tmp->philo = malloc(sizeof(t_philos*) * size)))
        return (1);
    j = 0;
    i = 0;
    while (i < size)
    {
        if (!(tmp->philo[i] = malloc(sizeof(t_philos))))
            return (1);
        tmp->philo[i]->id = j + 1;
        tmp->philo[i]->params = tmp->params;
        tmp->philo[i]->fork = fork;
        tmp->philo[i]->write = write;
        tmp->philo[i]->ceat = 0;
        tmp->philo[i]->last = 0;
        tmp->philo[i]->eat = 0;
        tmp->philo[i]->stop = 0;
        i++;
        j += 2;
        if (j >= size)
            j = 1;
    }
    return (0);
}

t_philo_two     *init(int argc, char **argv)
{
    t_philo_two     *tmp;

    if (!(tmp = malloc(sizeof(t_philo_two))))
        return (NULL);
    if (init_options(tmp, argc, argv))
        return (NULL);
    if (init_philos(tmp, tmp->params->nb_of_philosophers))
        return (NULL);
    return (tmp);
}
