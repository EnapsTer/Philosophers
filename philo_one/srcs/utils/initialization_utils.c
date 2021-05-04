#include "philo_one.h"
#include <stdlib.h>

pthread_mutex_t	*get_forks(void)
{
	pthread_mutex_t	*forks;
	t_config		config;

	config = g_simulation->config;
	if (config.number_of_philos > 1)
		forks = (pthread_mutex_t *)malloc(\
		sizeof(pthread_mutex_t) * config.number_of_philos);
	else
		forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * 2);
	if (forks && config.number_of_philos == 1)
	{
		pthread_mutex_init(forks, NULL);
		pthread_mutex_init(forks + 1, NULL);
		pthread_mutex_lock(forks);
	}
	g_simulation->forks = forks;
	return (forks);
}
