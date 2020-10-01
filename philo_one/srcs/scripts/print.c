#include "../includes/philo_one.h"

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

int     msg(t_philos *philo, char *str)
{
    if (philo->stop == 0)
    {
        pthread_mutex_lock(philo->params->write);
        ft_putnbr(ft_time() - philo->params->start);
        write(1, " ", 1);
        ft_putnbr(philo->id);
        write(1, " ", 1);
        ft_putstr(str);
        write(1, "\n", 1);
        pthread_mutex_unlock(philo->params->write);
        return (0);
    }
    return (1);
}
