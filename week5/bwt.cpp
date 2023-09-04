#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string rotate (string input){
    char first = input[0];
    return (input.substr(1, input.size() - 1) + first);

}

int main(){
    string input, output; cin >> input;
    input = input + '$';
    int n = input.size();
    vector <string> shift;
    for(int i = 0; i < n; i++){
        shift.push_back(input);
        input = rotate(input);
    }
    sort(shift.begin(), shift.end());

    for(string e: shift){
        output += e[n - 1];
    }

    std::cout << output;

}
