#!/bin/bash

for x in `cat $1`
do
    echo $x
    g++ -Wall -c $x
done
