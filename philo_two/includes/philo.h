#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <fcntl.h>
# define SUCCESS 0
# define FAIL 1
# define ERROR -1
# define TAKING_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"

typedef struct s_config
{
	unsigned int	number_of_philos;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				times_philo_eat;
	unsigned long	start_time;
}	t_config;

typedef struct s_philo
{
	pthread_t		philo;
	unsigned int	id;
	unsigned long	last_time_eat;
	int				eat_count;
}	t_philo;

typedef struct s_simulation
{
	t_config		config;
	sem_t			*forks_sem;
	sem_t			*print_sem;
	unsigned int	threads_count;
	int				is_philo_dead;
}	t_simulation;

t_simulation	*g_simulation;

int				starting_simulation(t_simulation *simulation, t_philo *philos);

int				create_philo_threads(t_philo *philos, t_simulation *simulation);

int				detach_philo_threads(t_philo *philos, t_simulation *simulation);

int				check_philos_live(t_philo *philos, t_simulation *simulation);

void			*philo_live(void *p_philo);

int				think_philo(t_philo *philo, t_config config);

int				sleep_philo(t_philo *philo, t_config config);

int				eat_philo(t_philo *philo, t_config config);

t_simulation	*new_simulation(int argc, char **argv);

t_philo			*new_philos(void);

void			init_config(t_config *config, int argc, char **argv);

unsigned long	get_time_interval(unsigned long time);

void			my_sleep(unsigned int ms);

void			print_philo_message(t_philo philo, t_config config, char *str);

unsigned long	get_time(void);

int				ft_isdigit(int c);

int				is_valid_arguments(int argc, char **argv);

int				destroy_forks(sem_t *forks, t_config config);

int				destroy_philos(t_philo *philos);

int				finishing_simulation(t_simulation *simulation, t_philo *philos);

void			wait_threads_creation(void);
#endif
