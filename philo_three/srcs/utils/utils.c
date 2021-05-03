#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include "philo_one.h"

unsigned long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}

unsigned long	get_time_interval(unsigned long time)
{
	return (get_time() - time);
}

void	my_sleep(unsigned int ms)
{
	if (ms == 0)
		return ;
	usleep(ms * 1000);
}

void	print_philo_message(t_philo philo, t_config config, char *str)
{
	sem_wait(g_simulation->print_sem);
	printf("%ld %d %s\n", get_time_interval(config.start_time), philo.id, str);
	sem_post(g_simulation->print_sem);
}

void	kill_all_processes(t_philo *philos, t_config config)
{
	int	i;

	i = 0;
	while (i < (int)config.number_of_philos && philos[i].philo_pid != -1)
	{
		kill(philos[i].philo_pid, SIGKILL);
		i++;
	}
}
