#include <iostream>
#include <string>


int main(){
    std::string word, sentence;

    std::getline(std::cin, word);
    std::getline(std::cin, sentence);

    char front, back;
    char symbol[] = {'\'','\"', '.', '(', ')', ',', ' ' };
    int symbol_size = sizeof(symbol)/ sizeof(symbol[0]);

    bool back_okay, front_okay;


    int start = 0;
    int occurence = 0;
    long found = std::string::npos;

    do {
        found = sentence.find(word, start);
        if (found != std::string::npos){

                if(found == 0){
                    front_okay = true;
                } else {

                    for (int i = 0; i < 7; i++){
                        if (sentence[found - 1] == symbol[i] ){
                        front_okay = true;
                        break;
                        } else {
                        front_okay = false;
                        }
                    }
                    }
            
                if (found + word.size() == sentence.size() ){
                    back_okay = true;
                } else {

                    for (int i = 0; i < 7; i++){
                    if (sentence[found + word.size()] == symbol[i] ){
                        back_okay = true;
                        break;
                        } else {
                        back_okay = false;
                    }
                }
                }
            
            if (front_okay && back_okay){
                occurence++;
            }
            
            start = found + word.size();
        }
    } while(found != std::string::npos);

    std::cout << occurence;

}
