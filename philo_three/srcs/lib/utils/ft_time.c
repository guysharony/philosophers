#include "../../includes/utils.h"

long long   ft_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}