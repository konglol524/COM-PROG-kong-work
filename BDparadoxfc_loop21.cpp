#include <iostream>
#include <cmath>

int main(){
    double p; std::cin >> p;
    double k = 1;
    double t = 1;

    t = t * (365 - (k - 1)) / 365.0;
    
    while ( 1 - t < p) {
        k++;
        t = t * (365 - (k - 1)) / 365.0;
    }

    std::cout << k;

}
