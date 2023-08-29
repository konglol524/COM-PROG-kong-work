#include <iostream>
#include <string>

using namespace std;

int find_vowel(string str){
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; j < 5; j++){
            if(vowels[j] == str[i]){
                return i;
            }
        }
    }
    return 0;
}

int main(){
    string input; getline(cin, input);
    string words[50];
    string temp ="";
    int word_count = 0;
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ' ' ){
            words[word_count] = temp;
            word_count++;
            temp = "";
        } else {
            temp += input[i];
        }
    }
    words[word_count] = temp;

    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    int location1 = find_vowel(words[0]);
    int location2 = find_vowel(words[word_count]);

    int size1 = words[0].size();
    int size2 = words[word_count].size();

    string consonant_1 = words[0].substr(0, location1);
    string vowels_1 = words[0].substr(location1, size1 - location1 );
    string consonant_2 = words[word_count].substr(0, location2);
    string vowels_2 = words[word_count].substr(location2,  size2 - location2);

    cout << consonant_1 << vowels_2 << " ";

    for(int i = 1; i < word_count; i++){
        cout << words[i] << " ";
    }

    cout << consonant_2 << vowels_1;

}
