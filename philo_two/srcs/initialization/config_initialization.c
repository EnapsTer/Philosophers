#include "philo_one.h"
#include "libft.h"

int	is_valid_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || !is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	init_config(t_config *config, int argc, char **argv)
{
	config->number_of_philos = (unsigned int)ft_atoi(argv[1]);
	config->time_to_die = (unsigned int)ft_atoi(argv[2]);
	config->time_to_eat = (unsigned int)ft_atoi(argv[3]);
	config->time_to_sleep = (unsigned int)ft_atoi(argv[4]);
	if (argc > 5)
		config->times_philo_eat = ft_atoi(argv[5]);
	else
		config->times_philo_eat = -1;
	config->start_time = get_time();
}
