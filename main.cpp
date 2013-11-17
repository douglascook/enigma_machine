#include <iostream>
#include <fstream>

#include "enigmaMachine.h"
#include "errors.h"

using namespace std;

int main(int argc, const char **argv)
{
    int error_num = 0;
    vector<vector<int> > input_vectors;

    // first check that the files are valid and create input vectors
    error_num = check_files(argc - 1, argv, input_vectors);
    if (error_num > 0){
        return error_num;
    }

    // now initialise the machine and its parts
    EnigmaMachine enigma(argc, input_vectors);
    enigma.construct_encryptors();

    char ch;
    // continue taking input until interrupt is sent
    while (cin >> ws >> ch){
        if (invalid_character(ch)){
            return INVALID_INPUT_CHARACTER;
        }
        cout << enigma.encrypt(ch);
    }
    cout << endl;

    return 0;
}
