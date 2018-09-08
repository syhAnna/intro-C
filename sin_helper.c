/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
    for (int i = 8; i > -1; i--) {
        sin_array[i] = sin % 10;
        sin /= 10;
    }

    if (sin == 0) {
        return 0;
    } else {
        return 1;
    }
}


/*
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {
    int check_code[9] = {1, 2, 1, 2, 1, 2, 1, 2, 1};
    int sum_up[9];
    int total = 0;

    if (sin_array[0] != 0) {
        for (int i = 0; i < 9; i++) {
            int multiple = sin_array[i] * check_code[i];
            if (multiple < 10) {
                sum_up[i] = multiple;
            } else {
                sum_up[i] = (multiple % 10) + (multiple / 10);
            }
        }

        for (int j = 0; j < 9; j++) {
            total += sum_up[j];
        }

        if (total % 10 == 0) {
            return 0;
        } else {
            return 1;
        }

    } else {
        return 1;
    }
}

