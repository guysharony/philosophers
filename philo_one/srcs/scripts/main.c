#include "../includes/philo_one.h"

int     clean(t_philo_one *philo_one)
{
    size_t  i;

    i = 0;
    while (i < philo_one->params->nb_of_philosophers)
    {
        pthread_mutex_destroy(philo_one->params->fork[i]);
	free(philo_one->params->fork[i]);
        free(philo_one->philo[i]);
        i++;
    }
    pthread_mutex_destroy(philo_one->params->write);
    free(philo_one->params->write);
    free(philo_one->params->fork);
    free(philo_one->philo);
    free(philo_one->params);
    free(philo_one);
    return (1);
}

int     args(int argc, char **argv)
{
    if (argc < 5)
        return (err("Too few arguments.", 1));
    if (argc > 6)
        return (err("Too many arguments.", 1));
    if (are_numbers(argc, argv))
        return (err("Arguments must be positive numbers.", 0));
    if (ft_atoi(argv[1]) < 2)
        return (err("At least 2 philosophers are requered.", 0));
    return (0);
}

int     main(int argc, char **argv)
{
    t_philo_one     *philo_one;

    if (args(argc, argv))
        return (1);
    if ((philo_one = init(argc, argv)) == NULL)
        return (clean(philo_one) && err("A problem occured during malloc.", 0));
    thr(philo_one);
    clean(philo_one);
    return (0);
}
