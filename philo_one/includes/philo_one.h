#ifndef PHILO_ONE_H
#define PHILO_ONE_H

# include <pthread.h>
# include <sys/time.h>
# define SUCCESS 0
# define TAKING_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct
{
	unsigned int number_of_philos;
	unsigned int time_to_die;
	unsigned int time_to_eat;
	unsigned int time_to_sleep;
	int 		number_of_times_each_philo_must_eat;
	unsigned long start_time;
}	t_config;

typedef struct
{
	pthread_t philo;
	unsigned int id;
	unsigned long last_time_eat;
	int				eat_count;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
}	t_philo;

typedef struct
{
	t_config config;
	pthread_mutex_t print_mutex;
}	t_simulation;

t_simulation *g_simulation;

int starting_simulation(t_simulation *simulation, t_philo *philos);

int create_philo_threads(t_philo *philos, t_simulation *simulation);

int detach_philo_threads(t_philo *philos, t_simulation *simulation);

int check_philos_live(t_philo *philos, t_simulation *simulation);

void	*philo_live(void *p_philo);

int 	think_philo(t_philo *philo, t_config config);

int		sleep_philo(t_philo *philo, t_config config);

int		eat_philo(t_philo *philo, t_config config);

t_simulation * new_simulation(char **argv);

t_philo *new_philos(t_config config);

void init_config(t_config *config, int argc, char **argv);

unsigned long get_time_interval(unsigned long time);

int my_sleep(unsigned int ms);

void	print_philo_message(t_philo philo, t_config config, char *str);

unsigned long	get_time();

pthread_mutex_t	*get_forks();
#endif
