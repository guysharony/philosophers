#ifndef PHILOSOPHERS_H
 #define PHILOSOPHERS_H

 #include <unistd.h>
 #include <stdio.h>
 #include <pthread.h>
 #include <semaphore.h>
 #include <fcntl.h> 
 #include "utils.h"
 
 typedef struct             s_params
 {
    int                     nb_of_philosophers;
    int                     tm_to_die;
    int                     tm_to_eat;
    int                     tm_to_sleep;
    int                     nb_eat_philo;
    int                     nw_eat;
    long long               start;
    sem_t                   *write;
    sem_t                   *fork;
 }                          t_params;

 typedef struct             s_philos
 {
    int                     id;
    int                     lfork;
    int                     rfork;
    int                     eat;
    int                     ceat;
    long long               last;
    pthread_t               thread;
    t_params                *params;
 }                          t_philos;

 typedef struct             s_tmp
 {
    int                     id;
    t_philos                **philo;
 }                          t_tmp;
 
 typedef struct             s_philo_one
 {
    t_params                *params;
    t_philos                **philo;
 }                          t_philo_one;

 int                        err(char *error);
 int                        msg(t_philos *philo, char *str);
 int                        thr(t_philo_one *philo_one);
 int                        init(t_philo_one *philo_one, int argc, char **argv);
 void                       aeat(t_philos *tmp);
 void                       asleep(t_philos *tmp);
 void                       athink(t_philos *tmp);

#endif