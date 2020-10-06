#include "../includes/philo_three.h"

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

size_t	    ft_strlen(const char *s)
{
	size_t	t;

	t = 0;
	while (s[t] != '\0')
		t++;
	return (t);
}