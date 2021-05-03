#include "philo_one.h"
#include <stdio.h>
#include <unistd.h>

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
	i = 0;
	while (i < simulation->config.number_of_philos)
	{
		sem_post(simulation->is_all_forks_created);
		i++;
	}
	sem_wait(g_simulation->is_sim_end_sem);
	kill_all_processes(philos, g_simulation->config);
	return (SUCCESS);
}
