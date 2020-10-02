#include "../includes/philo_one.h"

size_t      ft_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

static	size_t  ft_len(size_t nbr)
{
	size_t  a;
	size_t	b;

	a = 0;
	b = nbr;
	if (nbr < 0)
	{
		b = -b;
		a++;
	}
	while (b)
	{
		b /= 10;
		a++;
	}
	return (a);
}

static	void	ft_strrev(char *str, size_t nbr)
{
	size_t	a;
	size_t  b;
	char	c;

	a = 0;
	b = 0;
	if (nbr < 0)
		a++;
	while (str[b])
		b++;
	b -= 1;
	while (a < b)
	{
		c = str[a];
		str[a] = str[b];
		str[b] = c;
		a++;
		b--;
	}
}

static	void	ft_fill(size_t nb, size_t a, char *s)
{
	char	c;

	while (nb > 0)
	{
		c = ((nb % 10) + '0');
		s[a] = c;
		nb /= 10;
		a++;
	}
	s[a] = '\0';
}

char			*ft_itoa(size_t n)
{
	size_t  a;
	size_t  nb;
	char	*s;

	a = 0;
	nb = n;
	if (n == 0)
	{
		if (!(s = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (!(s = (char *)malloc(sizeof(char) * ft_len(n) + 1)))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		s[a] = '-';
		a++;
	}
	ft_fill(nb, a, s);
	ft_strrev(s, n);
	return (s);
}