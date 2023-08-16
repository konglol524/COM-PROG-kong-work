#include <iostream>
#include <cmath>
#include <algorithm>

int main() {
     double L = 0;
     double a; std::cin >> a;
     double U = sqrt(a);
     double x = (L + U) / 2.0;

     double aprox = pow(10, x);

    while(fabs(aprox - a) > (1e-10 * std::max(a, aprox))){
        
        if (pow(10, x) > a){
            U = x;
        } else if (pow(10, x) < a) {
            L = x;
        }

        x = (L + U) / 2.0;
        aprox = pow(10, x);
        
    }

    std::cout << x << std::endl;

}
