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

int     msg(t_philos *philo, char *str)
{
    sem_wait(philo->params->write);
    ft_putnbr(ft_time() - philo->params->start);
    write(1, " ", 1);
    ft_putnbr(philo->id);
    write(1, " ", 1);
    ft_putstr(str);
    write(1, "\n", 1);
    sem_post(philo->params->write);
    return (0);
}
