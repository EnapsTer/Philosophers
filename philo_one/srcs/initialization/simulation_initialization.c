#include "philo_one.h"
#include <stdlib.h>

t_simulation *new_simulation(char **argv)
{
	t_simulation *simulation;
	t_config config;

	simulation = (t_simulation *)malloc(sizeof(t_simulation));
	init_config(&config, 0, argv);
	simulation->config = config;
	pthread_mutex_init(&simulation->print_mutex, NULL);
	return (simulation);
}
