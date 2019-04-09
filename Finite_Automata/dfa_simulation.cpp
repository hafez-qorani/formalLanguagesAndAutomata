
/*
    this program simulate a dfa
    
    it takes a string as input and
    checks that it ends with "abb"
    this automata has 4 states {0, 1, 2, 3}
    with this alphabet {a, b}
    the move function contains the transition function
    of this  automata
    the initial state is 0 

*/

#include <iostream>
#include <string>

#define print(i) std::cout << i << std::endl

int move(int, char);

int main(){


    std::string str;
    std::cin >> str;

    
    // beginning state
    int state = 0;


    // final state
    const int final_state = 3;

    // current character
    char ch;

    // loop over the string until the end of string
    // or until reach a invalid character which is
    // not in the alphabet
    for(int i = 0; i < str.size() && state != -1; i++){
        ch = str[i];
        state = move(state, ch);
    }
    if (state == final_state)
        print("yes it ends with abb");
    else if (state == -1)
        print("error invalid character: " << ch);
    else 
        print("no it does not end with abb");

    return 0;
}

// change the state of automata
int move(int state, char ch){
    // state is current state
    // ch is the input character
    
    switch(state) {
        
        // automata state 0
        case 0:
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 0;
            else state = -1;

            break;

        // automata state 1
        case 1:
            if (ch == 'a') state = 1;
            else if ( ch == 'b') state = 2;
            else state = -1;

            break;

        // automata state 2
        case 2:
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 3;
            else state = -1;

            break;
    
        // automata state 3
        case 3:
            if (ch == 'a') state = 1;
            else if (ch == 'b') state = 0;
            else state = -1;

            break;
    }

    return state;

}


