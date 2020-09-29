#include "../includes/philo_one.h"

int     clean(t_philo_one *philo_one)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = philo_one->params->nb_of_philosophers;
    while (i < j)
    {
	    i++;
    }
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
    if (thr(philo_one))
        return (1);
    return (0);
}
