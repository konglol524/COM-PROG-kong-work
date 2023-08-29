#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string decToBinary(int n)
{
    string t = "";
    //we want four bits
    for (int i = 3; i >= 0; i--) {
        int k = n >> i; // right shift
        if (k & 1) //know the state of first bit
              t += "1";
        else t += "0";
    }
    return t;
}

int main(){
    string trick; getline(cin, trick);
    string input;
    string temp_string = "";
    string fours;
    char temp_char;
    while(getline(cin, input)){

        temp_string = "";

        if(input[0] == 'D'){
            //keep only alphabet character
            for(int i = 2; i < input.size(); i++){
                if(isalpha(input[i])){
                    temp_string += input[i];
                }
            }

            //look at uppercase and lowercase
            for(int i = 0; i < temp_string.size(); i++){
                if(isupper(temp_string[i])){
                    temp_string[i] = '0';
                } else {
                    temp_string[i] = '1';
                }
            }
            //split the strings into group of fours and decode them    
            for(int i = 0; i < temp_string.size(); i = i + 4){
                fours = temp_string.substr(i, 4);
                temp_char = '0'  + stoi(fours, 0, 2);        
                if(temp_char == ':'){
                    temp_char = '-';
                } else if (temp_char == ';'){
                    temp_char = ',';
                }
                cout << temp_char;
            }

            cout << endl;

        } else if(input[0] == 'E'){
            //convert number into upper and lowercase code
            string code = "";
            for(int i = 2; i < input.size(); i++){
                fours = decToBinary(input[i] - '0');
                if(fours == "1101"){
                    fours = "1010";
                } else if(fours == "1100"){
                    fours = "1011";
                }
                code += fours;
            }

            //assemble the trick message
            int trick_count = 0;
            int code_count = 0;
            while(code_count < code.size()){
                temp_char = trick[trick_count % trick.size()];
                if(isalpha(temp_char)){
                    if(code[code_count] == '0'){
                        temp_char = toupper(temp_char);
                    } else{
                        temp_char = tolower(temp_char);
                    }
                    code_count++;
                }
                trick_count++;
                cout << temp_char;
            }
            cout << endl;
        }
    }

}
