#include "philo_one.h"
#include <stdlib.h>

void	init_eat_count(t_philo *philo)
{
	t_config config;

	config = g_simulation->config;
	if (config.number_of_times_each_philo_must_eat == -1)
		philo->eat_count = -2;
	else
		philo->eat_count = 0;
}

void 	init_first_philo(t_philo *philo, pthread_mutex_t *forks)
{
	t_config config;

	config = g_simulation->config;
	philo->id = 1;
	philo->last_time_eat = get_time_interval(config.start_time);
	philo->right_fork = &forks[0];
	philo->left_fork = &forks[1];
	init_eat_count(philo);
}

void	init_last_philo(t_philo *philo, pthread_mutex_t *forks)
{
	t_config config;

	config = g_simulation->config;
	philo->id = 1;
	philo->last_time_eat = get_time_interval(config.start_time);
	philo->left_fork = &forks[0];
	philo->right_fork = &forks[config.number_of_philos - 1];
	init_eat_count(philo);
}

void	init_philo(t_philo *philo, pthread_mutex_t *forks, int i)
{
	t_config config;

	config = g_simulation->config;
	philo->id = i + 1;
	philo->last_time_eat = get_time_interval(config.start_time);
	philo->right_fork = &forks[i];
	philo->left_fork = &forks[i + 1];
	init_eat_count(philo);
}

t_philo *new_philos()
{
	//todo free forks
	//todo destroy forks
	t_philo *philos;
	pthread_mutex_t *forks;
	t_config 	config;
	int i;

	i = 0;
	config = g_simulation->config;
	if (!(forks = get_forks()) ||
	!(philos = (t_philo *)malloc(sizeof(t_philo) * config.number_of_philos)))
		return (NULL);
	init_first_philo(philos + i, forks);
	while (i < config.number_of_philos - 1)
	{
		pthread_mutex_init(&forks[i], NULL);
		if (i == 0)
			init_last_philo(&philos[config.number_of_philos - 1], forks);
		else
			init_philo(philos + i, forks, i);
		i++;
	}
	return (philos);
}
