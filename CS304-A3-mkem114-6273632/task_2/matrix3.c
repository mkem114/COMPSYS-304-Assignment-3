/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime() {
    struct timeval t;
    double sec, msec;

    while (gettimeofday(&t, NULL) != 0);
    sec = t.tv_sec;
    msec = t.tv_usec;

    sec = sec + msec / 1000000.0;

    return sec;
}

/* for task 1 only */
void usage(void) {
    fprintf(stderr, "Usage: matrix1/2/3 [--repetitions M] [--matrix_size N] [--block_size K]\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    double t1, t2;
    /* variables for task 1 */
    unsigned int M = 5;
    unsigned int N = 1000;
    unsigned int B = 16;
    unsigned int i;

    /* declare variables; examples, adjust for task */
    double **a;
    double **b;
    double **c;
    double sum;
    double swap;
    unsigned int j;
    unsigned int k;
    unsigned int jj;
    unsigned int kk;
    unsigned int repititions;

    /* parameter parsing task 1 */
    for (i = 1; i < (unsigned) argc; i++) {
        if (strcmp(argv[i], "--repetitions") == 0) {
            i++;
            if (i < argc)
                sscanf(argv[i], "%u", &M);
            else
                usage();
        } else if (strcmp(argv[i], "--matrix_size") == 0) {
            i++;
            if (i < argc)
                sscanf(argv[i], "%u", &N);
            else
                usage();
        } else if (strcmp(argv[i], "--block_size") == 0) {
            i++;
            if (i < argc)
                sscanf(argv[i], "%u", &B);
            else
                usage();
        } else usage();
    }


    /* allocate memory for arrays; examples, adjust for task */
    a = malloc(N * sizeof(double **));
    b = malloc(N * sizeof(double **));
    c = malloc(N * sizeof(double **));
    for (i = 0; i < N; i++) {
        a[i] = malloc(N * sizeof(double));
        b[i] = malloc(N * sizeof(double));
        c[i] = malloc(N * sizeof(double));
    }

    /* initialise arrray elements */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = 1;
            b[i][j] = 1;
            c[i][j] = 0;
        }
    }


    t1 = getTime();
    /* code to be measured goes here */
    /***************************************/
    for (repititions = 0; repititions < M; repititions++) {
        for (jj = 0; jj < N; jj += B) {
            for (kk = 0; kk < N; kk += B) {
                for (i = 0; i < N; i++) {
                    for (j = jj; j < (N < jj + B ? N : jj + B); j++) {
                        sum = c[i][j];
                        for (k = kk; k < (N < kk + B ? N : kk + B); k++) {
                            sum += a[i][k] * b[k][j];
                        }
                        c[i][j] = sum;
                    }
                }
            }
        }
    }
    /***************************************/
    t2 = getTime();

    /* output; examples, adjust for task */
    printf("time: %6.2f secs\n", (t2 - t1));

    /* IMPORTANT: also print the result of the code, e.g. the sum,
     * otherwise compiler might optimise away the code */
    printf("printing result for compiler %d\n", c[0][0]);

    /* free memory; examples, adjust for task */
    for (i = 0; i < N; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}
