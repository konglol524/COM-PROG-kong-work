#include <bits/stdc++.h>
//g++ firstfit.cpp -o fit
//Get-Content in.txt | ./fit | Out-File out.txt

using namespace std;

int main(){
    string command; cin >> command;
    int inp = 0;
    vector< tuple<int, int, vector<int>> > list;
    tuple<int, int, vector<int>> t = {0, 0, {}}; // total, member_num, member_list
    list.push_back(t);
    while(cin >> inp){
        if(command == "first"){
            //cout << "first fit" << endl;
            bool placed = false;
            for(int i = 0; i < list.size(); i++){
                if((get<0>(list[i]) + inp <= 100)){
                    placed = true;
                    get<0>(list[i]) = get<0>(list[i]) + inp;
                    //cout << " total " << get<0>(list[i]);
                    get<1>(list[i])++;
                    //cout << " num " << get<1>(list[i]);
                    get<2>(list[i]).push_back(inp);
                    sort(get<2>(list[i]).begin(), get<2>(list[i]).end());
                    break;
                } 
            }

            if(!placed){
                //std::cout << " Creating new for " << inp << endl;
                vector<int> v = {inp};
                tuple<int, int, vector<int>> t1 = make_tuple(inp, 1, v);
                list.push_back(t1);
            }
                
        } else if(command == "best"){
            //cout << "best fit" << endl;
            bool placed = false;
            pair<int, int> max_ind = make_pair(0, 0); //sum, index
            for(int i = 0; i < list.size(); i++){
                if((get<0>(list[i]) + inp <= 100)){
                   placed = true;
                    if(max_ind.first < get<0>(list[i]) + inp){
                        max_ind.first = get<0>(list[i]) + inp;
                        max_ind.second = i;
                    }
                } 
            }

            if(!placed){
                //std::cout << " Creating new for " << inp << endl;
                vector<int> v = {inp};
                tuple<int, int, vector<int>> t1 = make_tuple(inp, 1, v);
                list.push_back(t1);
            } else {
                int ind = max_ind.second;
                 get<0>(list[ind]) = get<0>(list[ind]) + inp;
                 get<1>(list[ind])++;
                 get<2>(list[ind]).push_back(inp);
                sort(get<2>(list[ind]).begin(), get<2>(list[ind]).end());
            }


        }


        //cout << "reading" << inp  << endl;

    }

    //print out groupings display in this order
    //1. groupings with larger sum comes first
    sort(list.begin(), list.end(), greater< tuple<int, int, vector<int>>>());

    //2. if sum is equal, the group with less members comes first
    //3. if equal number of members, compare the grouping vector so that the smaller one comes first
    
    for(int j = 0; j < list.size(); j++){
        for(int i = 1; i < list.size(); i++){
            if(get<0>(list[i-1]) == get<0>(list[i])){
                if(get<1>(list[i-1]) > get<1>(list[i])){
                    //swap
                    swap(list[i-1], (list[i]));
                } else if(get<1>(list[i-1]) == get<1>(list[i])){
                    if(get<2>(list[i-1]) > get<2>(list[i])){
                    //swap
                    swap((list[i-1]), (list[i]));
                    }
                }
            }
        }
    }
   
    for(auto c: list){
        for(auto p: get<2>(c)){
            cout << p << " ";
        }
        cout << endl;
    }

}
