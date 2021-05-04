#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	awake_is_eaten_sem(t_config config)
{
	unsigned int	i;

	i = 0;
	while (i < config.number_of_philos)
	{
		sem_post(g_simulation->is_eaten);
		i++;
	}
}

int	check_philo_death(t_philo philo, t_config config)
{
	usleep(20);
	if (get_time_interval(config.start_time) - philo.last_time_eat > \
													config.time_to_die + 5)
	{
		sem_wait(g_simulation->print_lock);
		awake_is_eaten_sem(config);
		printf("%ld %d %s\n", get_time_interval(config.start_time), \
															philo.id, DIED);
		sem_post(g_simulation->is_sim_end);
		return (FAIL);
	}
	return (SUCCESS);
}

void	*check_philo_live(void *p_philo)
{
	t_philo		*philo;
	t_config	config;

	philo = (t_philo *)p_philo;
	config = g_simulation->config;
	while (1)
	{
		if (philo->eat_count >= g_simulation->config.times_philo_eat)
		{
			sem_post(g_simulation->is_eaten);
			return (NULL);
		}
		else if (check_philo_death(*philo, config) == FAIL)
			return (NULL);
	}
}
