#include <iostream>
#include <string>
#include <cctype>

int main(){
    std::string password;

    while(std::cin >> password){

        int p_size = password.size();
        bool have_upper = false;
        bool have_lower = false;
        bool have_number = false;
        bool have_special = false;

        for (int i = 0; i < p_size; i++ ){
            if (isupper(password[i]))
            {
                have_upper = true;
            }

            if (islower(password[i]))
            {
                have_lower = true;
            }

            if(isdigit(password[i]))
            {
                have_number = true;
            }

            if(!isdigit(password[i]) && !isalpha(password[i])){
                have_special = true;
            }
        }

        if(p_size >= 12 && have_lower && have_upper && have_number && have_special){
            std::cout << ">> strong" << std::endl;
        } else if (p_size >= 8 && have_lower && have_upper && have_number){
            std::cout << ">> weak" << std::endl;
        } else {
            std::cout << ">> invalid" << std::endl;
        }

    }

}
