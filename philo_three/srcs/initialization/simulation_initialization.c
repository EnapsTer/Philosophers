#include "philo.h"
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
	sem_unlink("is_proc_created");
	simulation->is_proc_created = sem_open("is_proc_created", \
												 O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->is_proc_created) == ERROR)
		return (ERROR);
	sem_wait(simulation->is_proc_created);
	sem_unlink("is_dead");
	simulation->is_sim_end = sem_open("is_dead", O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->is_sim_end) == ERROR)
		return (ERROR);
	sem_wait(simulation->is_sim_end);
	sem_unlink("forks");
	simulation->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, \
								  config.number_of_philos);
	if (is_sem_created(simulation->forks) == ERROR)
		return (ERROR);
	sem_unlink("print_lock");
	simulation->print_lock = sem_open("print_lock", O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->print_lock) == ERROR)
		return (ERROR);
	sem_unlink("is_eaten");
	simulation->is_eaten = sem_open("is_eaten", O_CREAT | O_EXCL, 0644, 1);
	if (is_sem_created(simulation->is_eaten) == ERROR)
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
