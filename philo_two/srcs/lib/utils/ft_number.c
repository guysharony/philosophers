#include "../../includes/utils.h"

int ft_number(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return(1);
        i++;
    }
    return(0);
}