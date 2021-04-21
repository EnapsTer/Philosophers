#include "philo_one.h"
#include <stdlib.h>

t_simulation *new_simulation(char **argv)
{
	t_simulation *simulation;
	t_config config;

	simulation = (t_simulation *)malloc(sizeof(t_simulation));
	init_config(&config, argv);
	simulation->config = config;
	return (simulation);
}
