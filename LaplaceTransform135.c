#include <stdio.h>
#include <math.h>

double laplace_transform(double s, double t, double f(double)) {
    return f(t) / (s + t);
}

double inverse_laplace_transform(double s, int n, double *t, double *w, double f(double)) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += w[i] * laplace_transform(s, t[i], f);
    }
    return sum;
}

double f(double s) {
    return (s*s + 2*s + 5) / ((s-1) * pow(s-2, 2));
}

int main() {
    int n = 10;
    double t[n], w[n];
    
    for (int i = 0; i < n; i++) {
        t[i] = (i + 0.5) / n;
        w[i] = 1.0 / (i + 1);
    }
    
    double result = 0.0;
    for (double s = 0.1; s < 10.0; s += 0.1) {
        result = inverse_laplace_transform(s, n, t, w, f);
        printf("s = %f, Inverse Laplace transform: %f\n", s, result);
    }

    return 0;
}