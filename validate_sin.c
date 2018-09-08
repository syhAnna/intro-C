#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    if (argc == 2) {

        if (argv[1][0] != '0') {
            int input_sin = strtol(argv[1], NULL, 10);
            int sin_array[9];

            int check_length = populate_array(input_sin, sin_array);
            int check_valid = check_sin(sin_array);

            if (check_length == 0 && check_valid == 0) {
                printf("Valid SIN\n");
            } else {
                printf("Invalid SIN\n");
            }

        } else {
            printf("Invalid SIN\n");
        }

        return 0;
    } else {
        return 1;
    }
}


