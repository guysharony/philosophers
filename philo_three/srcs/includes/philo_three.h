/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:47:52 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 15:11:55 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/time.h>

typedef struct				s_params
{
	size_t					nb_of_philosophers;
	size_t					tm_to_die;
	size_t					tm_to_eat;
	size_t					tm_to_sleep;
	size_t					nb_eat_philo;
	size_t					nw_eat;
	size_t					start;
	int						end;
}							t_params;

typedef struct				s_philos
{
	size_t					id;
	int						eat;
	int						stop;
	size_t					ceat;
	size_t					last;
	pid_t					pid;
	sem_t					*write;
	sem_t					*fork;
	t_params				*params;
}							t_philos;

typedef struct				s_philo_three
{
	t_params				*params;
	t_philos				**philo;
}							t_philo_three;

int							ft_atoi(char *str);
int							is_number(char *str);
int							are_numbers(int nb, char **values);
int							err(char *str, int help);
int							msg(t_philos *philo, char *str);
int							thr(t_philo_three *philo_three);
int							mglobal(t_philo_three *tmp);
int							aeat(t_philos *tmp);
char						*ft_itoa(size_t n);
void						ft_putstr(char *str);
void						*mthread(void *philo);
size_t						ft_strlen(const char *s);
size_t						ft_time(void);
t_philo_three				*init(int argc, char **argv);

#endif
