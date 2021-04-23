#include <stdlib.h>
#include "philo_one.h"

int main(int argc, char **argv)
{
	// todo последний аругумент
	// todo один философ
	// todo парсинг аргументов
	// todo free
	// todo тесты глобальные
	t_philo *philos;

	g_simulation = new_simulation(argv);
	philos = new_philos(g_simulation->config);
	starting_simulation(g_simulation, philos);
	return (0);
}
