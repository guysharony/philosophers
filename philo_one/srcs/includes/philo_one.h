/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:38:00 by gsharony          #+#    #+#             */
/*   Updated: 2020/10/07 13:38:01 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct			s_params
{
	size_t				nb_of_philosophers;
	size_t				tm_to_die;
	size_t				tm_to_eat;
	size_t				tm_to_sleep;
	size_t				nb_eat_philo;
	size_t				nw_eat;
	size_t				start;
	pthread_mutex_t		*write;
	pthread_mutex_t		**fork;
}						t_params;

typedef struct			s_philos
{
	size_t				id;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	int					eat;
	int					stop;
	size_t				ceat;
	size_t				last;
	t_params			*params;
}						t_philos;

typedef struct			s_philo_one
{
	t_params			*params;
	t_philos			**philo;
}						t_philo_one;

int						ft_atoi(char *str);
int						is_number(char *str);
int						are_numbers(int nb, char **values);
int						err(char *str, int help);
int						msg(t_philos *philo, char *str);
int						thr(t_philo_one *philo_one);
int						aeat(t_philos *tmp);
void					asleep(t_philos *tmp);
void					athink(t_philos *tmp);
char					*ft_itoa(size_t n);
void					ft_putstr(char *str);
void					*mthread(void *philo);
void					mglobal(t_philo_one *philo_one);
size_t					ft_time(void);
t_philo_one				*init(int argc, char **argv);

#endif
