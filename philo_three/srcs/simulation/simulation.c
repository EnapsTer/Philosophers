#include "philo_one.h"
#include <stdlib.h>

int	finishing_simulation(t_simulation *simulation, t_philo *philos)
{
	if (g_simulation->forks_sem)
		destroy_forks(simulation->forks_sem, g_simulation->config);
	if (philos)
		destroy_philos(philos);
	if (g_simulation->print_sem)
	{
		sem_unlink("forks_sem");
		sem_post(g_simulation->print_sem);
		sem_close(g_simulation->print_sem);
	}
	free(simulation);
	return (SUCCESS);
}

int	starting_simulation(t_simulation *simulation, t_philo *philos)
{
	if (create_philo_processes(philos, simulation) == ERROR)
		return (ERROR);
//	if (detach_philo_threads(philos, simulation) == ERROR)
//		return (ERROR);
//	if (check_philo_live(philos, simulation) == ERROR)
//		return (ERROR);
	return (SUCCESS);
}
