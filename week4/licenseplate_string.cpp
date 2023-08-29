#include <string>
#include <iostream>

using namespace std;

int main(){
    string input; cin >> input;
    string output = "0AA-000";
    long int current_num = 100 * (input[4] - '0') + 10 * (input[5] - '0') + (input[6] - '0'); //+ 1;
    current_num += (input[0] - '0') * 1000 * 26 * 26 + (toupper(input[1]) - 'A') * 1000 * 26 + (toupper(input[2]) - 'A') * 1000;
    long int adder; cin >> adder;
    current_num += adder;

    if(current_num > 1000 * 26 * 26){
        adder = current_num / (1000 * 26 * 26);
        current_num %= (adder * 1000 * 26 * 26);
        output[0] = adder + (int)'0';
    }

    if(current_num > 1000 * 26){
        adder = current_num / (1000 * 26);
        current_num %= (adder * 1000 * 26);
        output[1] = adder + (int)'A';
    }

    if(current_num > 1000){
        adder = current_num / (1000);
        current_num %= (adder * 1000);
        output[2] = adder + (int)'A';
    }

    output[4] = '0' + current_num / 100;
    output[5] = '0' + (current_num % 100) / 10;
    output[6] =  '0' + (current_num % 10);
    cout << output << endl;

}
