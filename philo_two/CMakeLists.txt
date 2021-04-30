cmake_minimum_required(VERSION 3.19)
project(Philosophers C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(Philosophers
        includes/philo_one.h
        srcs/main.c srcs/simulation/simulation.c srcs/philosophers/philosophers_threads.c srcs/philosophers/philosophers_live.c srcs/initialization/simulation_initialization.c srcs/initialization/config_initialization.c srcs/initialization/philosophers_initialization.c srcs/utils/utils.c srcs/utils/libft.c includes/libft.h srcs/destroy/destroy.c)