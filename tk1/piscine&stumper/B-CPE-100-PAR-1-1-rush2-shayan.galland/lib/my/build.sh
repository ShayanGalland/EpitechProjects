#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## build
## File description:
## no
##

gcc -c *.c*
ar rc libmy.a *.o*
rm *.o*
