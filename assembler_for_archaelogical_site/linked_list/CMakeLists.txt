cmake_minimum_required(VERSION 3.18)
project(linked_list C)

set(CMAKE_C_STANDARD 99)

add_executable(linked_list main.c
        linked_list.c)
