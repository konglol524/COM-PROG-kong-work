#include <iostream>
#include <string>

using namespace std;

int main() {

    //take input 
    string input;
    cin >> input;

    char current = input[0];
    int count = 0;
    //initialize first checker and counter
    for(int i = 0; i < input.size(); i++){

        if(input[i] != current){
            //when find different character, print out last character and its counter
            //change checker, start counting at 1
            cout << current << " " << count << " ";
            current = input[i];
            count = 1;
        } else {
        //if found same character, add 1
            count++;
        }
    }
    //print out result for last character
    cout << current << " " << count << " ";

}
