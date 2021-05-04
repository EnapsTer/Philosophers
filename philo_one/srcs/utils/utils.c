#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include "philo.h"

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
	pthread_mutex_lock(&g_simulation->print_mutex);
	printf("%ld %d %s\n", get_time_interval(config.start_time), philo.id, str);
	pthread_mutex_unlock(&g_simulation->print_mutex);
}

void 	wait_threads_creation(void)
{
	while (g_simulation->threads_count != g_simulation->config.number_of_philos)
		;
}
