#include <bits/stdc++.h>
using namespace std;

//g++ bingo2.cpp -o bing
//Get-Content in.txt | ./bing | Out-File out.txt

int main(){
    //1. Get board
    tuple<string, bool, string> temp;
    vector<tuple<string, bool, string>> tempv;
    vector<vector<tuple<string, bool, string>>> board;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 5; j++){
            cin >> get<0>(temp);
            get<1>(temp) = false;
            if (get<0>(temp) == "*"){
                get<1>(temp) = true;
                get<2>(temp) = "";
            }
            tempv.push_back(temp);
        }
        board.push_back(tempv);
        tempv.clear();
    }

    //2.read calls - while(!win)
    //update board
    //check for win
    vector<string> display;
    string input;
    int count = 0;
    bool win = false;
    bool match;

    //input is broken, won't loop

    while(cin >> input){
        
        //cout << "reading " << input << endl;
        //check board for match
        //get index for column to look at
        int index;
        for(int i = 0; i < 5; i++){
            if(input[0] == get<0>(board[0][i])[0]){
                index = i;
                //cout << "got index " << index << " for " << input << endl;
            }
        }

        match = false;
        string matcher = input.substr(1, input.size() - 1);
        //try to match if haven't won
        if(!win){
            count++;
            for(int i = 1; i < 6; i++){
                if(matcher == get<0>(board[i][index])){
                    //cout << "match " << input << endl;
                    match = true;
                    get<1>(board[i][index]) = true;
                    get<2>(board[i][index]) = input;
                }
            }
        }

        //if there's a match, check winning conditions
        if(match){
            //check row win
            for(int i = 1; i < 6; i++){
                if(get<1>(board[i][0]) && get<1>(board[i][1]) && get<1>(board[i][2]) && get<1>(board[i][3]) && get<1>(board[i][4])){
                    win = true;
                    //cout << "win row " << i << endl;
                    string message;
                    for(int j = 0; j < 5; j++){
                        if(get<2>(board[i][j]) != ""){
                            message += get<2>(board[i][j]);
                            if(j != 4){
                                message += ", ";
                            }
                        }
                    }
                    display.push_back(message);
                }
            }

            //check column win
            for(int i = 0; i < 5; i++){
                if(get<1>(board[1][i]) && get<1>(board[2][i]) && get<1>(board[3][i]) && get<1>(board[4][i]) && get<1>(board[5][i])){
                    win = true;
                    //cout << "win col " << i << endl;
                    string message;
                    for(int j = 1; j < 6; j++){
                        if(get<2>(board[j][i]) != ""){
                            message += get<2>(board[j][i]);
                            if(j != 5){
                                message += ", ";
                            }
                        }
                    }
                    display.push_back(message);
                }
            }

            //check diagonal wins
            if(get<1>(board[5][0]) && get<1>(board[4][1]) && get<1>(board[2][3]) && get<1>(board[1][4])){
                win = true;
                string message;
                for(int i = 0; i < 5; i++){
                    if(get<2>(board[5-i][i]) != ""){
                        message += get<2>(board[5-i][i]);
                        if(i != 4){
                            message += ", ";
                        }
                    }
                }
                display.push_back(message);
            }

            if(get<1>(board[1][0]) && get<1>(board[2][1]) && get<1>(board[4][3]) && get<1>(board[5][4])){
                win = true;
                string message;
                for(int i = 0; i < 5; i++){
                    if(get<2>(board[1 + i][i]) != ""){
                        message += get<2>(board[1+i][i]);
                        if(i != 4){
                            message += ", ";
                        }
                    }
                }
                display.push_back(message);
            }
        }

    }

    //3. print number of calls
    //print winning combinations
    cout << count << endl;
    for(auto c : display){
        cout << c << endl;
    }
    

}
