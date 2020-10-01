#include "../../includes/utils.h"

int		ft_atoi(const char *str)
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