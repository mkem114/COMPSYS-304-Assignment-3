/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#define MATRIX_SIZE 1000

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
    fprintf(stderr, "Usage: cachetest1/2 [--repetitions M]\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    double t1, t2;

    /* variables for task 1 */
    unsigned int M = 5;
    unsigned int N = MATRIX_SIZE;
    unsigned int i;

    /* declare variables; examples, adjust for task */
    unsigned int j;
    unsigned int k;
    unsigned int repititions;
    double sum;
    static double a[MATRIX_SIZE][MATRIX_SIZE];
    static double b[MATRIX_SIZE][MATRIX_SIZE];
    static double c[MATRIX_SIZE][MATRIX_SIZE];
    static double temp[MATRIX_SIZE][MATRIX_SIZE];

    /* parameter parsing task 1 */
    for (i = 1; i < (unsigned) argc; i++) {
        if (strcmp(argv[i], "--repetitions") == 0) {
            i++;
            if (i < argc)
                sscanf(argv[i], "%u", &M);
            else
                usage();
        } else usage();
    }

    /* allocate memory for arrays; examples, adjust for task */

    /* initialise arrray elements */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            a[i][j] = i;
            b[i][j] = j;
        }
    }

    t1 = getTime();
    /* code to be measured goes here */
    /***************************************/
    for (repititions = 0; repititions < M; repititions++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                temp[i][j] = b[j][i];
            }
        }

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                sum = 0;
                for (k = 0; k < N; k++) {
                    sum += a[i][k] * temp[j][k];
                }
                c[i][j] = sum;
            }
        }
    }
    /***************************************/
    t2 = getTime();

    /* output; examples, adjust for task */
    printf("time: %6.2f secs\n", (t2 - t1));

    /* IMPORTANT: also print the result of the code, e.g. the sum,
     * otherwise compiler might optimise away the code */
    printf("print out result for compiler %d\n", c[0][0]);

    /* free memory; examples, adjust for task */

    return 0;
}
