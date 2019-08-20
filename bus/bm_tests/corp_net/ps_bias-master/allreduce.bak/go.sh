#!/bin/bash -ex

#mpiexec --allow-run-as-root -np 3 -x LD_PRELOAD=/tmp/mpi_allreduce ./sum-example-test.py
mpiexec --allow-run-as-root -np $1 ../samples/sum-example-test3.py
#gcc allreduce.c -I /usr/lib/openmpi/include/ -fPIC -shared -o /tmp/mpi_allreduce 
