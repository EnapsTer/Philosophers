#include "philo_one.h"
#include <stdlib.h>

t_philo *new_philos(t_config config)
{
	t_philo *philos;
	int i;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * config.number_of_philos);
	while (i < config.number_of_philos - 1)
	{
		if (i == 0)
		{
			philos[i].id = i + 1;
			philos[i].last_time_eat = get_time_interval(config.start_time);
			pthread_mutex_init(&philos[i].right_fork, NULL);
			pthread_mutex_init(&philos[i].left_fork, NULL);
			philos[config.number_of_philos - 1].id = config.number_of_philos;
			philos[config.number_of_philos - 1].last_time_eat = get_time_interval(config.start_time);
			philos[config.number_of_philos - 1].left_fork = philos[i].right_fork;
		}
		else
		{
			philos[i].id = i + 1;
			philos[i].last_time_eat = get_time_interval(config.start_time);
			philos[i].right_fork = philos[i - 1].left_fork;
			pthread_mutex_init(&philos[i].left_fork, NULL);
		}
		i++;
	}
	return (philos);
}
