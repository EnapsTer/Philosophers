#include "philo.h"
#include <stdio.h>

int	eat_philo(t_philo *philo, t_config config)
{
	pthread_mutex_lock(philo->left_fork);
	print_philo_message(*philo, config, TAKING_FORK);
	pthread_mutex_lock(philo->right_fork);
	print_philo_message(*philo, config, TAKING_FORK);
	print_philo_message(*philo, config, EATING);
	philo->last_time_eat = get_time_interval(config.start_time);
	if (g_simulation->config.times_philo_eat != -1)
		philo->eat_count++;
	my_sleep(config.time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (SUCCESS);
}

int	sleep_philo(t_philo *philo, t_config config)
{
	print_philo_message(*philo, config, SLEEPING);
	my_sleep(config.time_to_sleep);
	return (SUCCESS);
}

int	think_philo(t_philo *philo, t_config config)
{
	print_philo_message(*philo, config, THINKING);
	return (SUCCESS);
}

void	*philo_live(void *p_philo)
{
	t_philo	*philo;

	philo = (t_philo *)p_philo;
	wait_threads_creation();
	philo->last_time_eat = get_time_interval(g_simulation->config.start_time);
	if (philo->id % 2 == 0)
		my_sleep(60);
	while (1)
	{
		eat_philo(philo, g_simulation->config);
		if (philo->eat_count >= g_simulation->config.times_philo_eat)
			break ;
		sleep_philo(philo, g_simulation->config);
		think_philo(philo, g_simulation->config);
	}
	return (NULL);
}
