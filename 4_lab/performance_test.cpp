#include <cmath>

double teorCL(int n, int m) {
    return 1 + ((double)n/(double)m)/2;
}

double sucTeorOA(n, m) {
    double a = (double)n/(double)m;
    return (1 + 1/(1+a))/2;
}

double unsucTeorOA(n, m) {
    return (1 + 1/pow((1+a), 2))/2;
}

