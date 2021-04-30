#include "philo_one.h"
#include <stdlib.h>

void	init_eat_count(t_philo *philo)
{
	t_config	config;

	config = g_simulation->config;
	if (config.times_philo_eat == -1)
		philo->eat_count = -2;
	else
		philo->eat_count = 0;
}

t_philo	*new_philos(void)
{
	t_philo			*philos;
	t_config		config;
	unsigned int	i;

	i = 0;
	config = g_simulation->config;
	philos = (t_philo *)malloc(sizeof(t_philo) * config.number_of_philos);
	while (i < config.number_of_philos)
	{
		philos[i].id = i + 1;
		init_eat_count(philos + i);
		philos[i].last_time_eat = get_time_interval(config.start_time);
		i++;
	}
	return (philos);
}
