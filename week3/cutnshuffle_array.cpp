#include <iostream>
#include <string>

using namespace std;

void cut(int num, string array[]){
    string t;
    for(int i = 0; i < num / 2; i++){
        t = array[i];
        array[i] = array[num / 2 + i];
        array[num / 2 + i] = t;
    }
}

void shuffle(int num, string array[]){
    string t[1000];
    for(int i = 0; i < num / 2; i++){
       t[i * 2] = array[i]  ;
       t[i*2 + 1] = array[i + num /2]  ;
    }

    for(int i = 0; i < num; i++){
        array[i] = t[i];
    }
}


int main(){
    int num;
    int count = 0;
    string deck;
    string order;
    string deck_array[1000];
    string temp;

    cin >> num;
    cin.ignore();
    getline(cin, deck);
    getline(cin, order);
    deck += ' ';

    //cout << num << ' ' << deck << order;

    for(int i = 0; i < deck.size(); i++){
        if(deck[i] == ' '){
            deck_array[count] = temp;
            count++;
            temp = "";
        } else {
            temp += deck[i];
        }
    }

    for(int i = 0; i < order.size(); i++){
        if (order[i] == 'c' || order[i] == 'C'){
            //cout << "heyc";
            cut(num, deck_array);
        } else if (order[i] == 's' || order[i] == 'S'){
            shuffle(num, deck_array);
            //cout << "heys";
        }
    }

    for(int i = 0; i < num; i++){
        cout << deck_array[i] << " ";
    }

}
