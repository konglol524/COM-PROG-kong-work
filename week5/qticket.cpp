#include <bits/stdc++.h>
using namespace std;

//g++ qticket.cpp -o q
//Get-Content in.txt | ./q | Out-File out.txt
int main(){
    int n; cin >> n;
    int ticket = 0; int order = -1;
    string command_list[] = {"reset", "new", "order", "next", "avg_qtime" }; string command;
    vector<pair<int, int>> customers; //ticket number, time
    vector<int> time;
    int buffer, index;
    for(int i = 0; i < n; i++){
        cin >> command;
        for(int j = 0; j < 5; j++){
            if(command == command_list[j]){
                index = j;
                break;
            }
        }
        if(index < 3){
            cin >> buffer;
        }

        if(index == 0){ //reset command
            ticket = buffer - 1;
            
        } else if(index == 1){ //new command
            ticket++;
            std::cout << ">> ticket " << ticket << endl;
            customers.push_back(make_pair(ticket, buffer));

        } else if(index == 3){// next command
            order++;
            std::cout << ">> call " << customers[order].first << endl;

        } else if(index == 2){// order command
            int el_time = buffer - customers[order].second;
            std::cout << ">> qtime " << customers[order].first << " " << el_time <<  endl;
            time.push_back(el_time);

        } else if (index == 4){ // avg_qtime command
            double avg_time = 0;
            for(int c: time){
                avg_time += c;}
            avg_time = avg_time / double(time.size());
            std::cout << ">> avg_qtime " << round(avg_time * 100.0)/100.0 <<  endl;
        }


    }

}
