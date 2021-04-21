#include "philo_one.h"

int starting_simulation(t_simulation *simulation, t_philo *philos)
{
	create_philo_threads(philos, simulation);
	detach_philo_threads(philos, simulation);
	check_philos_live(philos, simulation);
	return (SUCCESS);
}