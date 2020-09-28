#include "../../includes/utils.h"

int ft_numbers(int nb, char **values)
{
    int i;

    i = 1;
    while(i < nb)
    {
        if(ft_number(values[i]))
            return(1);
        i++;
    }
    return (0);
}