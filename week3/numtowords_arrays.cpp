#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    long long int number; cin >> number;

    if (number == 0){
        cout << "zero";
        return 0;
    }

    string unique[] = {
        "", "one",       "two",      "three",
        "four",    "five",      "six",      "seven",
        "eight",   "nine",      "ten",      "eleven",
        "twelve",  "thirteen",  "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen"
    };

    if (number < 20){
        cout << unique[number];
        return 0;
    }

    string mult[] = {"trillion", "billion", "million", "thousand", "" };

    string tens[]
        = {"", "", "twenty",  "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    string output = "";
    bool case_valid;

    for(int i = 0; i < 5; i++){
        int x;

        if (number >= (long long)pow(10, 12 - 3 * i)){
            case_valid = true;
        } else {
            case_valid = false;
        }

        if(number >= (long long)pow(10, 14 - 3 * i))
        {
            output += unique[number / (long long)pow(10, 14 - 3 * i)];
            output += " hundred ";
            number = number % (long long)pow(10, 14 - 3 * i);
        }

        if(number >= (long long)pow(10, 13 - 3 * i)){
            x = number / (long long)pow(10, 13 - 3 * i);
            if (x > 1){
                output += tens[x];
                number = number % (long long)pow(10, 13 - 3 * i);
                if(number >= (long long)pow(10, 12 - 3 * i)){
                    x = number / (long long)pow(10, 12 - 3 * i);
                    output += " ";
                    output += unique[x];
                    number = number % (long long)pow(10, 12 - 3 * i);
                }
            } else {
                x = number / (long long)pow(10, 12 - 3 * i);
                output += unique[x];
                number = number % (long long)pow(10, 12 - 3 * i);
            }
            
        } else if (case_valid){
                x = number / (long long)pow(10, 12 - 3 * i);
                output += unique[x];
                number = number % (long long)pow(10, 12 - 3 * i);
        }

        if (case_valid){
            output += " ";
            output += mult[i];
            output += " ";
        }
        
    }

    cout << output;

}
