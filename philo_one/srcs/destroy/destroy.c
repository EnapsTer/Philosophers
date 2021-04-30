#include "philo_one.h"
#include <stdlib.h>

int destroy_philos(t_philo *philos)
{
	free(philos);
	return (1);
}

int	destroy_forks(pthread_mutex_t *forks, t_config config)
{
	unsigned int	i;

	i = 0;
	if (config.number_of_philos == 1)
	{
		pthread_mutex_destroy(forks);
		pthread_mutex_destroy(forks + 1);
	}
	else
	{
		while (i < config.number_of_philos)
		{
			if (forks[i].__sig)
				pthread_mutex_destroy(forks + i);
			i++;
		}
	}
	free(forks);
	return (1);
}
