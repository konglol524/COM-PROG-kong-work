#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int findmax(int array[], int num){
    int temp = array[0];
    for (int i = 0; i < num; i++){
        if(array[i] > temp){
            temp = array[i];
        }
    }
    return temp;

}

// create a 2d array and draw side ways

int main(){
    int num;
    int blocks[60];
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> blocks[i];
    }

    int x = num;
    int y = findmax(blocks, num);

    int graph[60][60];
    for(int i = 0; i < 60; i++) {
        for(int j = 0; j < 60; j++){
                graph[i][j] = 0;
        }
    }

    int temp;

    for(int i = 0; i < x; i++){
        temp = blocks[i];
        for(int j = 0; j < y; j++){
            if( temp > 0) {
                graph[i][j] = 1;
                temp = temp - 1;
            }
        }
    }

    int rain_count = 0;
    temp = 0;
    bool encounter_start = false;
    bool encounter_space = false;

    //when when encountering even number staring 1 blocks

    for(int j = y - 1; j > -1; j--){
        for(int i = 0; i < x; i++){
            if(graph[i][j] == 1){
                
                if(!encounter_start){
                    encounter_start = true;
                } else if(encounter_space) {
                    rain_count += temp;
                    encounter_space = false;
                    encounter_start = true;
                    temp = 0;
                    //reset
                }
            }else if (encounter_start) {
                encounter_space = true;
                temp++;
                graph[i][j] = 2;
            }
                
        }

        encounter_start = false;
        encounter_space = false;
        temp = 0;
    }

    cout << rain_count << endl;

}
