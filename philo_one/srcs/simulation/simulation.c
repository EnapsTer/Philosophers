#include "philo.h"
#include <stdlib.h>

int	finishing_simulation(t_simulation *simulation, t_philo *philos)
{
	if (g_simulation->forks)
		destroy_forks(simulation->forks, g_simulation->config);
	if (philos)
		destroy_philos(philos);
	if (simulation->print_mutex.__sig)
		pthread_mutex_destroy(&simulation->print_mutex);
	free(simulation);
	return (SUCCESS);
}

int	starting_simulation(t_simulation *simulation, t_philo *philos)
{
	if (create_philo_threads(philos, simulation) == ERROR)
		return (ERROR);
	if (detach_philo_threads(philos, simulation) == ERROR)
		return (ERROR);
	if (check_philos_live(philos, simulation) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
