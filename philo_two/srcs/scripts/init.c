#include "../includes/philo_two.h"

/*sem_t   *ft_sem_open(char const *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

char    *make_semaphore_name(char const *base, char *buffer, int position)
{
	int	    i;

	i = ft_strcpy(buffer, base);
	while (position > 0)
	{
		buffer[i++] = (position % 10) + '0';
		position /= 10;
	}
	buffer[i] = 0;
	return (buffer);
}*/

void            open_semaphore(char *str, t_params *params)
{
    char        tmp[5];

    ft_strcpy(tmp, str);
    sem_unlink(tmp);
    params->fork = sem_open(tmp, O_CREAT, S_IRWXU, params->nb_of_philosophers);
}

int             init_options(t_philo_two *tmp, int argc, char **argv)
{
    if (!(tmp->params = malloc(sizeof(t_params))))
        return (1);
    tmp->params->nb_of_philosophers = ft_atoi(argv[1]);
    open_semaphore("/fork", tmp->params);
    tmp->params->nw_eat = tmp->params->nb_of_philosophers;
    tmp->params->tm_to_die = ft_atoi(argv[2]);
    tmp->params->tm_to_eat = ft_atoi(argv[3]);
    tmp->params->tm_to_sleep = ft_atoi(argv[4]);
    tmp->params->end = 0;
    tmp->params->nb_eat_philo = -1;
    if (argc == 6)
        tmp->params->nb_eat_philo = ft_atoi(argv[5]);
    return (0);
}

int             init_philos(t_philo_two *tmp, int size)
{
    int         i;

    i = 0;
    if (!(tmp->philo = malloc(sizeof(t_philos*) * size)))
        return (1);
    while (i < size)
    {
        if (!(tmp->philo[i] = malloc(sizeof(t_philos))))
            return (1);
        tmp->philo[i]->id = i + 1;
        tmp->philo[i]->params = tmp->params;
        tmp->philo[i]->ceat = 0;
        tmp->philo[i]->last = 0;
        tmp->philo[i]->eat = 0;
        tmp->philo[i]->stop = 0;
        i++;
    }
    return (0);
}

t_philo_two     *init(int argc, char **argv)
{
    t_philo_two     *tmp;

    if (!(tmp = malloc(sizeof(t_philo_two))))
        return (NULL);
    if (init_options(tmp, argc, argv))
        return (NULL);
    if (init_philos(tmp, tmp->params->nb_of_philosophers))
        return (NULL);
    return (tmp);
}
