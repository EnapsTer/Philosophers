#include "philo_one.h"
#include <stdio.h>
#include <unistd.h>

int	create_philo_threads(t_philo *philos, t_simulation *simulation)
{
	unsigned int	i;
	int				status;

	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		status = pthread_create(&philos[i].philo, NULL, philo_live, philos + i);
		if (status)
		{
			printf("threads creation error!\n");
			detach_philo_threads(philos, simulation);
			return (ERROR);
		}
		++g_simulation->threads_count;
		i++;
	}
	return (SUCCESS);
}

int	detach_philo_threads(t_philo *philos, t_simulation *simulation)
{
	unsigned int	i;
	int				status;

	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		status = pthread_detach(philos[i].philo);
		if (status)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_philo_death(t_philo philo, t_config config)
{
	usleep(10);
	if (get_time_interval(config.start_time) - philo.last_time_eat > \
													config.time_to_die + 5)
	{
		g_simulation->is_philo_dead = 1;
		sem_wait(g_simulation->print_sem);
		printf("%ld %d %s\n", get_time_interval(config.start_time), \
															philo.id, DIED);
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_philos_live(t_philo *philos, t_simulation *simulation)
{
	unsigned int	i;
	unsigned int	cnt;
	t_config		config;

	config = simulation->config;
	while (1)
	{
		i = 0;
		cnt = 0;
		while (i < config.number_of_philos)
		{
			if (philos[i].eat_count >= g_simulation->config.times_philo_eat)
				cnt++;
			if (check_philo_death(philos[i], config) == FAIL)
				return (FAIL);
			i++;
		}
		if (cnt == config.number_of_philos)
			return (SUCCESS);
	}
}