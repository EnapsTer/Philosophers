#include <stdio.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (!is_valid_arguments(argc, argv))
	{
		printf("invalid arguments!\n");
		return (1);
	}
	g_simulation = new_simulation(argc, argv);
	if (!g_simulation)
		return (1);
	philos = new_philos();
	if (!philos)
	{
		finishing_simulation(g_simulation, philos);
		return (1);
	}
	starting_simulation(g_simulation, philos);
	finishing_simulation(g_simulation, philos);
	return (0);
}
