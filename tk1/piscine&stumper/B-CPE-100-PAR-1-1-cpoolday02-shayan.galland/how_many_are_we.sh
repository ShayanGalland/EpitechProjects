#!/bin/bash

if [ $# -eq 0 ]
then
    wc -l
else
    grep -iw $1 | wc -l
fi
