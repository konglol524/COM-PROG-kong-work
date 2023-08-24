#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    int array_in[1000];
    double temp = 1;
    int num; cin >> num; cin.ignore();

    for(int i = 0; i < num; i++){
        cin >> array_in[i];
    }

    for(int i = 0; i < num; i++){
        for(int j = i; j > -1 ; j--){

            if(j == i){
                temp = (double) array_in[j];
            } else {
                temp = (double) array_in[j] + (1.0 / temp);
            }
        }
        cout << setprecision(10) << temp << endl;
    }

}
