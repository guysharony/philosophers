#include "../includes/philo_one.h"

size_t      ft_time(void)
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

void        ft_putstr(char *str)
{
    size_t  i;

    i = 0;
    while(str[i]) {
        write(1, &str[i], 1);
        i++;
    }
}