#!/bin/bash

clear

gcc -c main.c convert_to_csv.c read_csv.c

gcc -o tester main.o convert_to_csv.o read_csv.o

./tester
