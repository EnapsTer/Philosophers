#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include "philo_one.h"

long	get_time_interval(struct timeval time_start)
{
	struct timeval	time_end;
	long			ret;

	gettimeofday(&time_end, NULL);
	ret = ((time_end.tv_sec - time_start.tv_sec) * 1000000L +
		   time_end.tv_usec) - time_start.tv_usec;
	return (ret);
}

void my_sleep(unsigned int ms)
{
	int cnt;

	cnt = 0;
	while (cnt <= ms)
	{
		usleep(5);
		cnt += 5;
	}
}

void	print_philo_message(t_philo philo, t_config config, char *str)
{
	printf("%ld - %d %s\n", get_time_interval(config.start_time), philo.id, str);
}