#include "../../includes/utils.h"

int         ft_nbrlen(long long nbr)
{
    int     i;

    i = 1;
    while ((nbr /= 10) > 0)
        i++;
    return (i);
}