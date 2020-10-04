#include "../includes/philo_three.h"

int		ft_atoi(char *str)
{
	int a;
	int c;
	int d;

	a = 0;
	c = 0;
	d = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-')
	{
		c = 1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		d *= 10;
		d += str[a] - 48;
		a++;
	}
	if (c == 1)
		return (-d);
	return (d);
}

int     is_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int     are_numbers(int nb, char **values)
{
    int i;

    i = 1;
    while (i < nb)
    {
        if (is_number(values[i]))
            return (1);
        i++;
    }
    return (0);
}