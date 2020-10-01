#include "srcs/includes/philosophers.h"

int                 main(int argc, char **argv)
{
    t_philo_one     *philo_one;

    if (!(philo_one = malloc(sizeof(t_philo_one))))
        return (err("Can't malloc."));
    if (init(philo_one, argc, argv))
        return (1);
    if (thr(philo_one))
        return (1);
    return (0);
}