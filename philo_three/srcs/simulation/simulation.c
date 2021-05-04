#include "philo.h"
#include <stdlib.h>

int	finishing_simulation(t_simulation *simulation, t_philo *philos)
{
	if (philos)
		destroy_philos(philos);
	if (g_simulation->forks)
		destroy_forks(simulation->forks, g_simulation->config);
	if (g_simulation->print_lock)
	{
		sem_post(g_simulation->print_lock);
		sem_close(g_simulation->print_lock);
	}
	if (g_simulation->is_eaten)
		sem_close(g_simulation->is_eaten);
	if (g_simulation->is_proc_created)
		sem_close(g_simulation->is_proc_created);
	if (g_simulation->is_sim_end)
		sem_close(g_simulation->is_sim_end);
	free(simulation);
	return (SUCCESS);
}

int	starting_simulation(t_simulation *simulation, t_philo *philos)
{
	if (create_philo_processes(philos, simulation) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
