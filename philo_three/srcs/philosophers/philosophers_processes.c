#include "philo.h"
#include <unistd.h>

void	start_all_processes(t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		sem_post(simulation->is_proc_created);
		i++;
	}
}

void	wait_for_eaten(t_simulation *simulation, t_config config)
{
	unsigned int	i;

	i = 0;
	sem_wait(simulation->is_eaten);
	while (i < config.number_of_philos)
	{
		sem_wait(simulation->is_eaten);
		i++;
	}
	sem_wait(simulation->print_lock);
}

int	create_philo_processes(t_philo *philos, t_simulation *simulation)
{
	unsigned int	i;

	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		philos[i].philo_pid = fork();
		if (philos[i].philo_pid == ERROR)
		{
			kill_all_processes(philos, g_simulation->config);
			return (ERROR);
		}
		else if (philos[i].philo_pid == 0)
			philo_live(philos + i);
		else
			i++;
	}
	start_all_processes(simulation);
	if (g_simulation->config.times_philo_eat != -1)
		wait_for_eaten(simulation, g_simulation->config);
	else
		sem_wait(g_simulation->is_sim_end);
	kill_all_processes(philos, g_simulation->config);
	return (SUCCESS);
}
