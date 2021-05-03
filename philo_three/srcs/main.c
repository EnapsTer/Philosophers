#include <stdio.h>
#include "philo_one.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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
		return (1);
	if (g_simulation->config.times_philo_eat)
	{
		starting_simulation(g_simulation, philos);
		finishing_simulation(g_simulation, philos);
	}
	return (0);
}
