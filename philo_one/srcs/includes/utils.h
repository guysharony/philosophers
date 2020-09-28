#ifndef UTILS_H
 #define UTILS_H

 #include <unistd.h>
 #include <stdlib.h>
 #include <sys/time.h>
 
 int            ft_isdigit(char c);
 int	        ft_atoi(const char *str);
 int            ft_number(char *str);
 int            ft_numbers(int nb, char **values);
 int            ft_strlen(char *str);
 int            ft_nbrlen(long long nbr);
 char	        *ft_strcpy(char *dest, const char *src);
 char	        *ft_itoa(int n);
 void           ft_putchar(char c);
 void           ft_putstr(char *str);
 void	        ft_putnbr(long long nb);
 long long      ft_time(void);
#endif