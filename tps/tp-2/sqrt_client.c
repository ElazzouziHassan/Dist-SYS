#include <stdio.h>
#include <stdlib.h>
#include "sqrt.h"

int main(int argc, char *argv[]) {
    CLIENT *cl;
    float *result;
    float number;

    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        exit(1);
    }

    number = atof(argv[1]);

    cl = clnt_create("localhost", SQRT_PROG, SQRT_VERS, "tcp");
    if (cl == NULL) {
        clnt_pcreateerror("Error connecting to server");
        exit(1);
    }

    result = sqrt_1(&number, cl);
    if (result == NULL) {
        clnt_perror(cl, "Error calling remote procedure");
        exit(1);
    }

    if (*result < 0) {
        printf("Error: Cannot calculate square root of a negative number.\n");
    } else {
        printf("Square root of %f is %f\n", number, *result);
    }

    clnt_destroy(cl);
    return 0;
}
