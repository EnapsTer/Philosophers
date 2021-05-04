#include "philo.h"
#include <stdlib.h>

t_simulation	*new_simulation(int argc, char **argv)
{
	t_simulation	*simulation;
	t_config		config;

	simulation = (t_simulation *)malloc(sizeof(t_simulation));
	if (!simulation)
		return (NULL);
	init_config(&config, argc, argv);
	simulation->config = config;
	simulation->forks = NULL;
	pthread_mutex_init(&simulation->print_mutex, NULL);
	if (config.times_philo_eat == 0)
		pthread_mutex_lock(&simulation->print_mutex);
	return (simulation);
}
