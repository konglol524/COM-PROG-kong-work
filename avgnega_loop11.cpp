#include <iostream>
#include <cmath>
#include <vector>

int main(){
    std::vector <double> numbers;
    double input;
    while(true) {
        std::cin >> input;
        if (input == -1.0){
            break;
        }
        numbers.push_back(input);

    } 

    double sum = 0;

    for (int i = 0; i < numbers.size(); i++){
        //std::cout << numbers[i] << " ";
        sum += numbers[i];
    }

    sum = round( (sum / numbers.size())* 1e2 ) / 1e2;

    if (numbers.empty()) {
        std::cout << "No Data" << std::endl;
    } else {
        std::cout << sum << std::endl;
    }


}
