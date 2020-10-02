#include <libc.h>

void    get_number(char **dst, size_t nbr)
{
	if (nbr >= 10)
	{
		get_number(dst, nbr / 10);
		get_number(dst, nbr % 10);
	}
	else
		*(*dst)++ = nbr + '0';
}

size_t  ft_nbrlen(size_t nbr)
{
    size_t  i;
    size_t  n;

    n = 1;
    i = nbr;
    while (i /= 10)
        n++;
    return (n);
}

int     main(void)
{
    char    *str;
    char    *tmp;

    printf("[%ld]\n", ft_nbrlen(0));
    str = malloc(sizeof(char) * 4);
    tmp = str;
    get_number(&tmp, 0);
    printf("%s\n", str);
    return (0);
}