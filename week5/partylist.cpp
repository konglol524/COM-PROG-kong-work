#include <bits/stdc++.h>
//g++ partylist.cpp -o par
//Get-Content in.txt | ./par | Out-File out.txt
using namespace std;

bool arranger (tuple<string, long double, int> a, tuple<string, long double, int> b) {
    if(get<2>(a) != get<2>(b)){
        return get<2>(a) >  get<2>(b);
    } else {
        return get<1>(a) >  get<1>(b);
    }
}

int main(){
    vector<tuple<string, long double, int>> parties; //name, score, member num
    long double total_score = 0;
    string input; int in_score;
    while(true){
        cin >> input;
        if(input == "END"){
            break;
        }
        cin >> in_score;
        total_score += in_score;
        parties.push_back(make_tuple(input, in_score, 0));
    }
    int total_mem = 0;
    long double avg_score = total_score / 100.0;
    long double temp;
    vector<pair<long double, int>> remain; //remainder, index

    for(int i = 0; i < parties.size(); i++){
        temp = get<1>(parties[i]) / avg_score;
        get<2>(parties[i]) = (int) temp;
        total_mem += get<2>(parties[i]);
        remain.push_back(make_pair(temp - (int)temp, i));
    }

    //sort the remain vector by descending order
    sort(remain.begin(), remain.end(), greater<pair<long double, int>>());

    int bonus_mem = 0;
    while(total_mem < 100){
        get<2>(parties[remain[bonus_mem].second])++;
        total_mem++;
        bonus_mem++;
    }

    sort(parties.begin(), parties.end(), arranger);

    for(auto c : parties){
        if(get<2>(c) > 0){
            cout << get<0>(c) << " " << get<2>(c) << " " << get<1>(c) << endl;
        }
    }
   
}
