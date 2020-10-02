#include "../includes/philo_one.h"

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    ft_putstr(char *str)
{
    size_t  i;

    i = 0;
    while(str[i]) {
        write(1, &str[i], 1);
        i++;
    }
}

void	ft_putnbr(size_t nb)
{
    char    c;

	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
    {
        c = nb + '0';
		write(1, &c, 1);
    }
}

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

void    ft_getstring(char **dst, char *src)
{
    while (*src)
        *(*dst)++ = *src++;
}

int     msg(t_philos *philo, char *str)
{
    char    *time;
    char    *id;
    size_t  size;
    char    *tmp1;
    char    *tmp2;

    if (philo->stop == 0)
    {
        time = ft_itoa(ft_time() - philo->params->start);
        id = ft_itoa(philo->id);
        size = ft_strlen(time) + ft_strlen(id) + ft_strlen(str) + 4;
        if (!(tmp1 = malloc(sizeof(char) * size)))
            return (1);
        tmp2 = tmp1;
        ft_getstring(&tmp2, time);
        ft_getstring(&tmp2, " ");
        ft_getstring(&tmp2, id);
        ft_getstring(&tmp2, " ");
        ft_getstring(&tmp2, str);
        ft_getstring(&tmp2, "\n");
        *tmp2 = '\0';
        write(1, tmp1, size);
        free(time);
        free(id);
        free(tmp1);
        return (0);
    }
    return (1);
}
