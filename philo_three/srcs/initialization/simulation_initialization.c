#include "philo_one.h"
#include <stdio.h>
#include <stdlib.h>

int	is_sem_created(sem_t *sem)
{
	if (sem == SEM_FAILED)
	{
		printf("failed to create semaphore");
		return (ERROR);
	}
	return (SUCCESS);
}

int	init_semaphores(t_simulation *simulation, t_config config)
{
	sem_unlink("is_all_processes_created");
	simulation->is_all_forks_created = sem_open("is_all_processes_created", \
												 O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->is_all_forks_created) == ERROR)
		return (ERROR);
	sem_wait(simulation->is_all_forks_created);
	sem_unlink("is_dead_sem");
	simulation->is_sim_end_sem = sem_open("is_dead_sem", \
									   			O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->is_sim_end_sem) == ERROR)
		return (ERROR);
	sem_wait(simulation->is_sim_end_sem);
	sem_unlink("forks_sem");
	simulation->forks_sem = sem_open("forks_sem", O_CREAT | O_EXCL, 0644, \
								  config.number_of_philos);
	if (is_sem_created(simulation->forks_sem) == ERROR)
		return (ERROR);
	sem_unlink("print_sem");
	simulation->print_sem = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->print_sem) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_simulation	*new_simulation(int argc, char **argv)
{
	t_simulation	*simulation;
	t_config		config;

	simulation = (t_simulation *)malloc(sizeof(t_simulation));
	if (!simulation)
		return (NULL);
	init_config(&config, argc, argv);
	simulation->config = config;
	if (init_semaphores(simulation, config) == ERROR)
		return (NULL);
	return (simulation);
}
