#include "philo_one.h"
#include <stdio.h>
#include <stdlib.h>

int	destroy_philos(t_philo *philos)
{
	free(philos);
	return (1);
}

int	destroy_forks(sem_t *forks, t_config config)
{
	int		i;

	i = 0;
	if (forks)
	{
		while (i < (int)config.number_of_philos)
		{
			sem_post(forks);
			i++;
		}
		sem_unlink("forks_sem");
		sem_close(forks);
	}
	return (1);
}
