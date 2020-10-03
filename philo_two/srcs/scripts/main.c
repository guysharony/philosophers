#include "../includes/philo_two.h"

int     clean(t_philo_two *tmp)
{
    size_t  i;

    i = 0;
    free(tmp->philo);
    free(tmp->params);
    free(tmp);
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
    t_philo_two     *philo_two;

    if (args(argc, argv))
        return (1);
    if ((philo_two = init(argc, argv)) == NULL)
        return (clean(philo_two) && err("A problem occured during malloc.", 0));
    thr(philo_two);
    clean(philo_two);
    return (0);
}
