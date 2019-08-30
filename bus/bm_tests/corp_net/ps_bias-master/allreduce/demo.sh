#!/bin/bash -ex

gcc -c debug.c -I  /usr/lib/openmpi/include/ -fPIC && \
gcc -c fifo_cs.c -I  /usr/lib/openmpi/include/ -fPIC && \
gcc -c allreduce.c  -I /usr/lib/openmpi/include/ -fPIC && \
gcc -c switch_sum.c -lpython3.5m -I /usr/lib/openmpi/include/ -fPIC && \
gcc allreduce.o switch_sum.o debug.o fifo_cs.o -I /usr/lib/openmpi/include/  -fPIC -shared -o /tmp/mpi_allreduce && \
mpiexec --allow-run-as-root -np $1 -x LD_PRELOAD=/tmp/mpi_allreduce -x KEY=$2 ../samples/sum-example.py
#gcc allreduce.c -I /usr/lib/openmpi/include/ -fPIC -shared -o /tmp/mpi_allreduce 
