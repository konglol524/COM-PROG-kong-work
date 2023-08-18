#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); //to prevent cin taking \n

    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        string balls = "";
        string odd_balls = "";
        //prep input for process from "R B R" to "RBR"
        for (int j = 0; j < s.size(); j++) {
            if (s[j] != ' '){
                balls.push_back(s[j]);
            }
        }

        //creating a group for odd balls
        for (int j = 0; j < balls.size(); j++) {
            if (j % 2 != 0){
                odd_balls.push_back(balls[j]);
            }
        }

        //std::cout << balls << std::endl;
        //std::cout << even_balls << std::endl;
        //std::cout << odd_balls << std::endl;
        
        //check for Wrong_input

        bool ok = true;
        //1. first ball must be R
        if (balls[0] != 'R'){
            ok = false;
        }
        //2. all 'R' must be at even position
        for (int j = 0; j < odd_balls.size(); j++){
            if (odd_balls[j] == 'R'){
                ok = false;
                break;
            }
        }
        ////can simply use find
        //odd_balls.find('R') != string::npos{
        //    ok = false;    
        //}

       
        
        //find start position of color sequence
        int start_color_pos = 0;
        for (int j = 0; j < balls.size(); j++){
            if (balls[j] != 'R' && j != 0){
                if (balls[j - 1] != 'R'){
                    start_color_pos = j;
                    break;
                }
            }
        }

         //3. check for R C? ... ? R... r can't come up after color sequence starts

        if (start_color_pos != 0){
            for(int j = start_color_pos + 1; j < balls.size(); j++){
                if (balls[j] == 'R'){
                    ok = false;
                }
            }

        //could use even_balls to check instead by checking position of last R to the lenght of even_balls
        //position of last R should be R - 1

            //std::cout << start_color << endl;
            //4. when R is not last ball && color sequence started, check the color sequence
            
            string sequence = "YGNBPK";

            if (balls[balls.size() - 1] != 'R'){
                for (int j = start_color_pos; j < balls.size(); j++)
                if (balls[j] != sequence[j - start_color_pos]){
                    ok = false;
                    break;
                }
            }
        }
        

        if (ok){
            int score = 0;
            for(int j = 0; j < balls.size(); j++){
                switch (balls[j]) {
                case 'R':
                    score = score + 1;
                    break;
                case 'Y':
                    score = score + 2;
                    break;
                case 'G':
                    score = score + 3;
                    break;
                case 'N':
                    score = score + 4;
                    break;
                case 'B':
                    score = score + 5;
                    break;
                case 'P':
                    score = score + 6;
                    break;
                case 'K':
                    score = score + 7;
                    break;
                default:
                    break;

                }
            }
            cout << score << endl;
        } else {
            cout << "WRONG_INPUT" << endl;
        }

    }

}
