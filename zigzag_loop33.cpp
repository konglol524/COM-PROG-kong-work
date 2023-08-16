#include <iostream>
#include <algorithm>

int main(){
    int max_L, min_L, max_R, min_R, comp;
    std::cin >> max_L >> max_R;
    min_L = max_L;
    min_R = max_R;
    comp = 0;
    int count = 0;
    while(comp != -999 && comp != - 998){
        std::cin >> comp;
        if (comp == -999 || comp == -998){
            break;
        }
        count++;

        if(count % 2 == 1){

            if (count % 4 == 1){
                max_R = std::max(max_R, comp);
                min_R = std::min(min_R, comp);
            } else {
                max_L = std::max(max_L, comp);
                min_L = std::min(min_L, comp);
            }

            //std::cout << "LEFT! ";
        } else {
            if (count % 4 == 0){
                max_R = std::max(max_R, comp);
                min_R = std::min(min_R, comp);
            } else {
                max_L = std::max(max_L, comp);
                min_L = std::min(min_L, comp);
            }
            //std::cout << "RIGHT!\n";
        }
    }

    if (comp == -998){
        std::cout << min_L << " " << max_R;
    } else {
        std::cout << min_R << " " << max_L;
    }

}
