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

size_t  ft_size(t_philos *philo, char *str, size_t time)
{
    size_t  n;
    size_t  a;
    size_t  id;

    n = 5;
    a = 0;
    id = philo->id;
    while (time /= 10)
        n++;
    while (id /= 10)
        n++;
    while (str[a])
    {
        n++;
        a++;
    }
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

int     msg(t_philos *philo, char *str, int status)
{
    size_t  time;
    size_t  size;
    char    *msg;
    char    *tmp;

    if (philo->stop)
        return (1);
    time = ft_time() - philo->params->start;
    size = ft_size(philo, str, time);
    if (!(msg = malloc(sizeof(char) * (size + 1))))
        return (1);
    tmp = msg;
    get_number(&tmp, time);
    get_string(&tmp, " ");
    get_number(&tmp, philo->id);
    get_string(&tmp, " ");
    get_string(&tmp, str);
    get_string(&tmp, "\n");
    *tmp++ = '\0';
    sem_wait(philo->params->write);
    write(1, msg, size);
    if (!status)
        sem_post(philo->params->write);
    free(msg);
    return (0);
}
