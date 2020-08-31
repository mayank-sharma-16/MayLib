#include <iostream>
#include <string>
#include <cmath>

int get_guess(){
    int guess;
    std::cin >> guess;
    return guess;
}

int validate_guess(int guess, int true_number){
    if(guess < true_number){
        return 0;
    }
    else if(guess > true_number){
        return 1;
    }
    else{
        return 2;
    }
}

int temperature_guess(int guess, int last_guess, int true_number){
    if(abs(true_number-guess) > abs(true_number-last_guess)){
        return 0;
    }
    else if(abs(true_number-guess) < abs(true_number-last_guess)){
        return 1;
    }
    else{
        return 2;
    }
}

int generate_true_number(){
    return 100;
}

int main(){

    //initialize
    int attempts = 0;
    int answer = generate_true_number();
    std::string intro = "hello! give me a number!";
    std::string too_low = "yikes, too low; not as low as my respect for you but feel free to try again";
    std::string colder = "oof you're getting wronger, i'm impressed";
    std::string warmer = "you're getting closer but don't pat yourself on the back";
    std::string too_high = "wow, too high; not as high as you on your horse but go ahead and give it another shot";
    std::string neutral = "what, you got stupid stuck in your brains? you guessed the same thing, asshole";
    int last_guess;
    std::string just_right;

    // introduction
    std::cout << intro << std::endl;

    while(true){
        // get guess
        int guess = get_guess();
        attempts = attempts + 1;

        // validate guess
        int validation = validate_guess(guess, answer);
        if(validation == 0 && attempts == 1){
                std::cout << too_low << std::endl;
        }
        else if(validation == 1 && attempts == 1){
                std::cout << too_high << std::endl;
        }
        else if(validation == 2){
            just_right = "hey, you got it right and it only took you ";
            just_right.append(std::to_string(attempts));
            if(attempts == 1){
                just_right.append(" try");
            }
            else {
                just_right.append(" tries");
            }
            std::cout << just_right << std::endl;
            return 0;
        }

        if(attempts > 1){
            int distance_type = temperature_guess(guess, last_guess, answer);
            if(distance_type == 0){
                std::cout << colder << std::endl;
            }
            else if (distance_type == 1){
                std::cout << warmer << std::endl;
            }
            else{
                std::cout << neutral << std::endl;
            }
        }

        last_guess = guess;
    }

    return 0;
}

