#include "philo_one.h"

int	detach_supervisor(pthread_t *supervisor)
{
	int	status;

	status = pthread_detach(*supervisor);
	if (status)
	{
		printf("threads detach error!\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	create_supervisor(pthread_t *supervisor, t_philo *philo)
{
	int status;

	status = pthread_create(supervisor, NULL, check_philo_live, (void *)philo);
	if (status)
	{
		printf("threads creation error!\n");
		detach_supervisor(supervisor);
		return (ERROR);
	}
	return (SUCCESS);
}

int	start_supervisor(t_philo *philo)
{
	pthread_t	supervisor;

	if (create_supervisor(&supervisor, philo) == ERROR)
		return (ERROR);
	if (detach_supervisor(&supervisor) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
