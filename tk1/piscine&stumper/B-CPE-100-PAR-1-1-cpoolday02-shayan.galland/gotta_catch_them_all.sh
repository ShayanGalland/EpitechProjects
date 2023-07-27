#!/bin/bash
cut -d " " -f 2 | cut -d ":" -f 1 | grep ^$1 | wc -l
