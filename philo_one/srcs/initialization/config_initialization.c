#include "philo_one.h"
#include <stdlib.h>

void init_config(t_config *config, int argc, char **argv)
{
	config->number_of_philos = (unsigned int)atoi(argv[1]); // todo delete atoi and do parsing
	config->time_to_die = (unsigned int)atoi(argv[2]);
	config->time_to_eat = (unsigned int)atoi(argv[3]);
	config->time_to_sleep = (unsigned int)atoi(argv[4]);
	if (argc > 5)
		config->number_of_times_each_philo_must_eat = atoi(argv[5]);
	else
		config->number_of_times_each_philo_must_eat = -1;
	config->start_time = get_time();
}