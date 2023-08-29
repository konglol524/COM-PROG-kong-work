#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
    string input; cin >> input;
    string temp = "";
    bool seen_digit = false;
    bool seen_alpha = false;

    for(int i = 0; i < input.size(); i++){
        if(isalpha(input[i])){
            seen_alpha = true;
            if (i != 0 && isupper(input[i])){
                cout << temp << ", ";
                temp = "";
            } else if(seen_digit){
                cout << temp << ", ";
                temp = "";    
            }
            seen_digit = false;
        } else {
            seen_digit = true;
            if(seen_alpha){
                cout << temp << ", ";
                temp = "";   
            }
            seen_alpha = false;
        }
        temp += input[i];
    }
     cout << temp;
}
