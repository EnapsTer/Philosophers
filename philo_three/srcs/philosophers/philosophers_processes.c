#include "philo_one.h"
#include <stdio.h>
#include <unistd.h>

int	create_philo_processes(t_philo *philos, t_simulation *simulation)
{
	unsigned int	i;
	// TODO попробовать дожидаться философов wait for thread creation
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
		{
			philo_live(philos + i);
		}
		else
			i++;
	}
	sem_wait(g_simulation->is_sim_end_sem);
	sem_wait(g_simulation->is_sim_end_sem);
	kill_all_processes(philos, g_simulation->config);
	return (SUCCESS);
}
