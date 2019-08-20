#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mpi.h>

#define DEBUG 0

extern int switch_sum(int key, const float *input, float *output, int count, int size, int rank);

int MPI_Allreduce(const void *sendbuf, void *recvbuf, int count,
        MPI_Datatype datatype, MPI_Op op, MPI_Comm comm) {

    if (sendbuf == MPI_IN_PLACE)
        sendbuf = (const void*)recvbuf;

    static int rank = -1;
    if (rank < 0)
        rank = atoi(getenv("OMPI_COMM_WORLD_RANK"));
    static int size = -1;
    if (size < 0)
        size = atoi(getenv("OMPI_COMM_WORLD_SIZE"));
    static int key = -1;
    if (key < 0)
        key = atoi(getenv("KEY"));
    float *input = (float*)sendbuf;
    float *output = (float*)recvbuf;

    //printf("key = %d\n", key);
#if DEBUG == 1
    printf("\n[DEBUG] ################## Partial input value from member-%d, size-%d = [", rank, size);
    for (int i = 0; i < count; ++i)
        printf(" %f", input[i]);
    puts("]\n");

    printf("\n[DEBUG] ################## TODO: Compute the sum of all input values for member-%d, size-%d = [", rank, size);
#endif
    //printf("switch_sum count:%d\n", count);
	switch_sum(key, input, output, count, size, rank);
    //  for (int i = 0; i < count; ++i)
    //    output[i] = input[i] * 123; // just an example, we want add 2 input from 2 different members and then save the sum to the output array
#if DEBUG == 1
    printf("\n[DEBUG] ################## The final result of sum values for member-%d, size-%d = [", rank, size);
    for (int i = 0; i < count; ++i)
        printf(" %f", output[i]);
    puts("]\n");
#endif
    return 0;
}
