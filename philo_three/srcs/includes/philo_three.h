#ifndef PHILO_THREE_H
 #define PHILO_THREE_H
 #include <unistd.h>
 #include <pthread.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <semaphore.h>
 #include <signal.h>
 #include <fcntl.h>
 #include <sys/time.h>

 typedef struct             s_params
 {
     size_t                 nb_of_philosophers;
     size_t                 tm_to_die;
     size_t                 tm_to_eat;
     size_t                 tm_to_sleep;
     size_t                 nb_eat_philo;
     size_t                 nw_eat;
     size_t                 start;
     int                    end;
     sem_t                  *fork;
 }                          t_params;

 typedef struct             s_philos
 {
     size_t                 id;
     int                    eat;
     int                    stop;
     size_t                 ceat;
     size_t                 last;
     pid_t                  pid;
     t_params               *params;     
 }                          t_philos;

 typedef struct             s_philo_three
 {
     t_params               *params;
     t_philos               **philo;
 }                          t_philo_three;
 
 int		                ft_atoi(char *str);
 int                        is_number(char *str);
 int                        are_numbers(int nb, char **values);
 int                        err(char *str, int help);
 int                        msg(t_philos *philo, char *str);
 int                        thr(t_philo_three *philo_three);
 void                       aeat(t_philos *tmp);
 void                       asleep(t_philos *tmp);
 void                       athink(t_philos *tmp);
 char			            *ft_itoa(size_t n);
 void                       ft_putstr(char *str);
 void                       *mthread(void *philo);
 char	                    *ft_strdup(const char *s1);
 char	                    *ft_strcpy(char *dest, const char *src);
 size_t	                    ft_strlen(const char *s);
 void                       mglobal(t_philo_three *philo_three);
 size_t                     ft_time(void);
 t_philo_three              *init(int argc, char **argv);

#endif