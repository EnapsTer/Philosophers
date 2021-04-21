#include "philo_one.h"
#include <stdio.h>
#include <unistd.h>

int create_philo_threads(t_philo *philos, t_simulation *simulation)
{
	// todo check errors for create
	int i;

	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		pthread_create(&philos[i].philo, NULL, philo_live, philos + i);
		i++;
	}
	return (SUCCESS);
}

int detach_philo_threads(t_philo *philos, t_simulation *simulation)
{
// todo check error for detach
	int i;

	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		pthread_detach(philos[i].philo);
		i++;
	}
	return (SUCCESS);
}

int check_philos_live(t_philo *philos, t_simulation *simulation)
{
	int i;
	t_philo philo;
	t_config config;

	config = simulation->config;
	while (1)
	{
		i = 0;
		while (i < config.number_of_philos)
		{
			philo = philos[i];
			if (get_time_interval(config.start_time) - philo.last_time_eat > config.time_to_die)
			{
				printf("%d %d\n", get_time_interval(config.start_time) - philo.last_time_eat, config.time_to_die);
				print_philo_message(philo, config, DIED);
				return (SUCCESS);
			}
			i++;
		}
	}
}