#include <stdio.h>
#include <stdlib.h>


int check_permissions(char *file_permission, char *required_permission) {
    int count_match = 0;
    int count_permission = 0;
    int i;

    for (i = 0; i < 9; i++) {
        if (required_permission[i] != '-') {
            count_permission++;
        }
        if ((file_permission[i] == required_permission[i])
            && (required_permission[i] != '-')) {
            count_match++;
        }
    }

    if (count_match == count_permission) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char** argv) {
    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "USAGE: count_large size [permissions]\n");
        return 1;
    }

    int large_size = strtol(argv[1], NULL, 10);
    char *permission;

    if (argc == 3) {
        permission = argv[2];
    } else {
        permission = NULL;
    }

    int flag = 0;
    int count = 0;
    char total[10];
    int total_number;

    char file_permission[11];
    int number_file;
    char user[32];
    char group[32];
    int file_size;
    char month[10];
    int day;
    char time[10];
    char file_name[32];

    scanf("%s %d", total, &total_number);

    while (scanf("%s %d %s %s %d %s %d %s %s",
                 file_permission,
                 &number_file,
                 user,
                 group,
                 &file_size,
                 month,
                 &day,
                 time,
                 file_name) != EOF) {
        if (file_permission[0] != 'd') {

            if (permission != NULL) {
                flag = check_permissions(&file_permission[1], permission);
            }

            if ((file_size > large_size) && (flag == 0)) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}


