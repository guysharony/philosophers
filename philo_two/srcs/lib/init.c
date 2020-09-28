#include "../includes/philosophers.h"

int             check_arg(int argc, char **argv)
{
    return (!ft_numbers(argc, argv) && ft_atoi(argv[1]) > 1 &&
    argc > 4 && argc < 7);
}

int             ioptions(t_philo_one *tmp, int argc, char **argv)
{
    if (!(tmp->params = malloc(sizeof(t_params))))
        return (1);
    tmp->params->nb_of_philosophers = ft_atoi(argv[1]);
    sem_unlink("/forks");
    if (!(tmp->params->fork = sem_open("/forks", O_CREAT, S_IRWXU, tmp->params->nb_of_philosophers)))
        return (1);
    sem_unlink("/write");
    if (!(tmp->params->write = sem_open("/write", O_CREAT, S_IRWXU, 1)))
        return (1);
    tmp->params->nw_eat = tmp->params->nb_of_philosophers;
    tmp->params->tm_to_die = ft_atoi(argv[2]);
    tmp->params->tm_to_eat = ft_atoi(argv[3]);
    tmp->params->tm_to_sleep = ft_atoi(argv[4]);
    tmp->params->nb_eat_philo = -1;
    if (argc == 6)
        tmp->params->nb_eat_philo = ft_atoi(argv[5]);
    return (0);
}

int             iphilo(t_philo_one *philo_one, int size)
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
        philo_one->philo[i]->rfork = i + 1;
        philo_one->philo[i]->lfork = ((i + 1) % size) + 1;
        philo_one->philo[i]->params = philo_one->params;
        philo_one->philo[i]->ceat = 0;
        i++;
    }
    return (0);
}

int             init(t_philo_one *philo_one, int argc, char **argv)
{
    if (!check_arg(argc, argv))
        return (err("Bad arguments."));
    if (ioptions(philo_one, argc, argv))
        return (err("Can't malloc."));
    if (iphilo(philo_one, philo_one->params->nb_of_philosophers))
        return (err("Can't malloc."));
    return (0);
}