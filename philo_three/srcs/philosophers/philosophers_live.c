#include "philo_one.h"
#include <stdio.h>
#include <unistd.h>

int	eat_philo(t_philo *philo, t_config config)
{
	sem_wait(g_simulation->forks_sem);
	print_philo_message(*philo, config, TAKING_FORK);
	sem_wait(g_simulation->forks_sem);
	print_philo_message(*philo, config, TAKING_FORK);
	print_philo_message(*philo, config, EATING);
	philo->last_time_eat = get_time_interval(config.start_time);
	if (g_simulation->config.times_philo_eat != -1)
		philo->eat_count++;
	my_sleep(config.time_to_eat);
	sem_post(g_simulation->forks_sem);
	sem_post(g_simulation->forks_sem);
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
	start_supervisor(philo);
	if (philo->id % 2 == 0)
		my_sleep(60);
	while (philo->is_eaten == 0)
	{
		eat_philo(philo, g_simulation->config);
		sleep_philo(philo, g_simulation->config);
		think_philo(philo, g_simulation->config);
	}
	sem_post(g_simulation->is_sim_end_sem);
	exit(0);
}
