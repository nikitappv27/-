#include <iostream>
#include <cmath>

int main() {
    double eps = 0.01;
    double term = 1.0;
    double sum = 0.0;
    int n = 1;
    int sign = 1;

    while (true) {
        sum += sign * term;
        n++;
        term /= n;

        if (term < eps) {
            break;
        }

        sign *= -1;
    }

    std::cout << "Сумма S ≈ " << sum << std::endl;
    std::cout << "Погрешность ≤ " << eps << std::endl;

    return 0;
}
