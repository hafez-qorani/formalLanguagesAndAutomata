
/*
    below code is simple simulation of a NFA (non determinstic finite automata)
    the automta language is {a, b}
    automata states are {0, 1, 2, 3, 4}

    this program takes a string
    and checks that whether string
    ends with "aa" or "bb"
    this automata regular expression is (a + b)*(aa + bb)

*/



#include <iostream>
#include <vector>
#include <string>

// macroes
#define print(word) std::cout << word << std::endl;

bool backtrack_nfa(int, std::string, int);
std::vector<int> move(int, char);

std::vector<int> final_states = {2, 4};

int main(){


    std::string str;

    // read a line from input
    std::getline(std::cin, str);

    // final states

    if (backtrack_nfa(0, str, 0)) {
        print("string is valid"); 
    }
    else {
        print("string is not valid"); 
    }

    return 0;
}

// this validates the string base on the backtracking method
bool backtrack_nfa(int state, std::string str, int c){

    // if there is a next character
    if (str[c]){
        // where to go with this input from this state
        std::vector<int> states = move(state, str[c]);

        for(int i = 0; i < states.size(); i++){
            if (backtrack_nfa(states[i], str, c+1)){
                return true;    
            } 
        }
        return false;

    } 
    else {
        
        // check whether current state is among the final states
        for(int i = 0; i < final_states.size(); i++){
            if (state == final_states[i]) {
                return true;
            }
        }

        return false; 
    }

}


std::vector<int> move(int state, char ch){
    
    std::vector<int> states;

    switch(state){
        
        // automata state 0
        case 0:
            if (ch == 'a'){
                states.push_back(0);
                states.push_back(1);
            }
            else if (ch == 'b'){
                states.push_back(0);
                states.push_back(3);
            }

        break;

        // automata state 1
        case 1:
            if (ch == 'a')
                states.push_back(2);
    
        break;

        // automata state 3
        case 3: 
            if (ch == 'b')
                states.push_back(4);

        break;
        // we dont need other states
        // because its NFA
    }

    return states;

}

