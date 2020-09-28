#include "../includes/philosophers.h"

int     err(char *str) {
    ft_putstr("Error: ");
    ft_putstr(str);
    ft_putchar('\n');
    return (1);
}

int     msg(t_philos *philo, char *str)
{
    pthread_mutex_lock(&philo->params->write);
    ft_putnbr(ft_time() - philo->params->start);
    write(1, " ", 1);
    ft_putnbr(philo->id);
    write(1, " ", 1);
    ft_putstr(str);
    write(1, "\n", 1);
    pthread_mutex_unlock(&philo->params->write);
    return (0);
}