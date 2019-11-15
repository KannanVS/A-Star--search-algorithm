#!/bin/bash

# compiling source code to object file

cc -c aStar.c
cc -c list.c
cc -c main.c
cc -c map.c
cc -c status.c

# creating executable file

cc -o map aStar.o list.o main.o map.o status.o
