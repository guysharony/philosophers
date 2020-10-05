#include "../includes/philo_two.h"

int     err(char *str, int help)
{
    if (help >= 0 && help < 2)
    {
        ft_putstr("philo_one: ");
        ft_putstr(str);
        write(1, "\n", 2);
        if (help)
        {
            ft_putstr("\n");
            ft_putstr("[1] number of philosophers (at least 2 are requiered).\n");
            ft_putstr("[2] time to die (in ms).\n");
            ft_putstr("[3] time to eat (in ms).\n");
            ft_putstr("[4] time to sleep (in ms).\n\n");
            ft_putstr("[5] (optional) number of time each philosopher must eat.\n");
        }
    }
    return (1);
}

void    get_string(char **dst, char *src)
{
    while (*src)
        *(*dst)++ = *src++;
}

size_t  ft_size(t_philos *philo, size_t time)
{
    size_t  n;
    size_t  i;
    size_t  t;

    n = 0;
    t = time;
    i = philo->id;
    while (time /= 10)
        n++;
    while (i /= 10)
        n++;
    return (n);
}

void    get_number(char **dst, size_t nbr)
{
    char    c;

	if (nbr >= 10)
	{
		get_number(dst, nbr / 10);
		get_number(dst, nbr % 10);
	}
	else
    {
        c = nbr + '0';
		*(*dst)++ = c;
    }
}

int     dfork(t_philos *philo)
{
    size_t      time;
    size_t      size;
    char        *msg;
    char        *tmp;

    time = ft_time() - philo->params->start;
    size = ft_size(philo, time) + 21;
    if (!(msg = malloc(sizeof(char) * (size + 1))))
        return (1);
    tmp = msg;
    get_number(&tmp, time);
    get_string(&tmp, " ");
    get_number(&tmp, philo->id);
    get_string(&tmp, " is taking a fork.\n");
    *tmp++ = '\0';
    write(1, msg, size + 1);
    free(msg);
    return (0);
}

int     deat(t_philos *philo)
{
    size_t      time;
    size_t      size;
    char        *msg;
    char        *tmp;

    time = ft_time() - philo->params->start;
    size = ft_size(philo, time) + 14;
    if (!(msg = malloc(sizeof(char) * (size + 1))))
        return (1);
    tmp = msg;
    get_number(&tmp, time);
    get_string(&tmp, " ");
    get_number(&tmp, philo->id);
    get_string(&tmp, " is eating.\n");
    *tmp++ = '\0';
    write(1, msg, size + 1);
    free(msg);
    return (0);
}

int     ddie(t_philos *philo)
{
    size_t      time;
    size_t      size;
    char        *msg;
    char        *tmp;

    time = ft_time() - philo->params->start;
    size = ft_size(philo, time) + 12;
    if (!(msg = malloc(sizeof(char) * (size + 1))))
        return (1);
    tmp = msg;
    get_number(&tmp, time);
    get_string(&tmp, " ");
    get_number(&tmp, philo->id);
    get_string(&tmp, " is dead.\n");
    *tmp++ = '\0';
    write(1, msg, size + 1);
    free(msg);
    return (0);
}

int     dsleep(t_philos *philo)
{
    size_t      time;
    size_t      size;
    char        *msg;
    char        *tmp;

    time = ft_time() - philo->params->start;
    size = ft_size(philo, time) + 16;
    if (!(msg = malloc(sizeof(char) * (size + 1))))
        return (1);
    tmp = msg;
    get_number(&tmp, time);
    get_string(&tmp, " ");
    get_number(&tmp, philo->id);
    get_string(&tmp, " is sleeping.\n");
    *tmp++ = '\0';
    write(1, msg, size + 1);
    free(msg);
    return (0);
}

int     dthink(t_philos *philo)
{
    size_t      time;
    size_t      size;
    char        *msg;
    char        *tmp;

    time = ft_time() - philo->params->start;
    size = ft_size(philo, time) + 16;
    if (!(msg = malloc(sizeof(char) * (size + 1))))
        return (1);
    tmp = msg;
    get_number(&tmp, time);
    get_string(&tmp, " ");
    get_number(&tmp, philo->id);
    get_string(&tmp, " is thinking.\n");
    *tmp++ = '\0';
    write(1, msg, size + 1);
    free(msg);
    return (0);
}