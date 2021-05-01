#include "philo_one.h"
#include <stdio.h>
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
	sem_unlink("is_dead_sem");
	simulation->is_sim_end_sem = sem_open("is_dead_sem", O_CREAT | O_EXCL, 0644, 1);
	if (simulation->is_sim_end_sem == SEM_FAILED)
	{
		printf("failed to create semaphore");
		return (NULL);
	}
	sem_unlink("forks_sem");
	simulation->forks_sem = sem_open("forks_sem", O_CREAT | O_EXCL, 0644, \
								  config.number_of_philos);
	if (simulation->forks_sem == SEM_FAILED)
	{
		printf("failed to create semaphore");
		return (NULL);
	}
	sem_unlink("print_sem");
	simulation->print_sem = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 1);
	if (simulation->print_sem == SEM_FAILED)
	{
		printf("failed to create semaphore");
		return (NULL);
	}
	return (simulation);
}
