/*
Build a failure table. A helper function for the KMP algorithm.
*/

void build_failure_function(char pattern[], int m, int failure[]) {
    int s = 2;
    int c = 0;

    failure[0] = -1;
    failure[1] = 0;

    while (s < m) {
        if (pattern[c] == pattern[s-1]) {
            c++;
            failure[s] = c;
            s++;
        } else if (c > 0) {
            // 4
            c = failure[c];
        } else {
            failure[s] = 0;
            s++;
        }
    }
}