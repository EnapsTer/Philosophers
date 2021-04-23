#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include "philo_one.h"

unsigned long	get_time()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}

unsigned long get_time_interval(unsigned long time)
{
	return (get_time() - time);
}

int my_sleep(unsigned int ms)
{
	unsigned long	current_time;
	unsigned long	required_time;

	current_time = get_time();
	required_time = current_time + ms;
	while (current_time <= required_time)
	{
		if (usleep(10) == 1)
			return (1);
		current_time = get_time();
	}
	return (SUCCESS);
}

void	print_philo_message(t_philo philo, t_config config, char *str)
{
	pthread_mutex_lock(&g_simulation->print_mutex);
	printf("%ld - %d %s\n", get_time_interval(config.start_time), philo.id, str);
	pthread_mutex_unlock(&g_simulation->print_mutex);
}
