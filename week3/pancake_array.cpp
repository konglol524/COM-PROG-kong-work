#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int find_max (int num, int array[]){
    int max = array[0];
    int max_index = 0;
    for(int i = 0; i < num; i++){
        if (array[i] > max){
            max = array[i];
            max_index = i;
        }
    }
    return max_index;
}
  
void flip (int end, int array[]){
    int t;
    for (int i = 0; i < (end + 1) / 2; i++){
        t = array[i];
        array[i] = array[end - i];
        array[end - i] = t;
    }
}

void print_cake (int num, int array[]){
    for (int i = 0; i < num; i++){
            cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int num;
    int pancake[100];
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> pancake[i];
    }

    print_cake(num, pancake);

    int max_index;
    for (int i = 0; i < num - 1; i++){
        max_index = find_max(num - i, pancake);
        if (max_index != 0 && max_index != (num - 1 - i)){
            flip(max_index, pancake);
            max_index = find_max(num - i, pancake);
            print_cake(num, pancake);
        }
        if (max_index != (num - 1 - i)){
            flip(num - 1 - i, pancake);
            print_cake(num, pancake);
        }

    }
}
