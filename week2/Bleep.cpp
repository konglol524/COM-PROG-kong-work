#include <iostream>
#include <string>

void bleep(std::string const &word, std::string &text){
  long found = std::string::npos;
  int start = 0;

   do {
        found = text.find(word, start);
        if (found != std::string::npos){
            for(int i = found; i < found + word.size(); i++){
              text[i] = '*';
            }
            start = found + word.size();
        }
    } while(found != std::string::npos);


}

int main(){

  std::string word = "broccoli";
  std::string text = "broccoli broccoli k abroccoli";

  bleep(word, text);

  std::cout << text << std::endl;


}
