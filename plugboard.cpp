#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include "encryptor.h"
#include "plugboard.h"

using namespace std;

// may want to change this to use proper strings
Plugboard::Plugboard(const char *filepath, int& error)
{
    int next;
    ifstream config_file(filepath);
    assert(config_file);
    
    // need to check for empty file since the plugboard doesn't necessarily do anything 
    if (config_file.peek() == '\0'){
        return;
    }

    // loop through config file checking each number is valid
    while (!config_file.eof()){
        // firstly check its numeric
        if (!(config_file >> next)){
            cout << "ERROR NON-INT!" << endl;
            error = 4;
            break;
        // check for correct index ie between A and Z
        }else if (next < 0 || next > 25){
            cout << "ERROR INVALID index" << endl;
            error = 3;
            break;
        }else {
            // loop through to check if number has already been used
            for (int i = 0; i < transformation.size(); i++){
                if (transformation[i] == next){
                    cout << "transformation element number " << i << " number already used = " << next << endl;
                    error = 5;
                    break;
                }
            }
            if (error == 0){
                transformation.push_back(next);
                // strip out remaining whitespace so we get to end of file properly
                config_file >> ws;
            }else {
                break;
            }
        }
    }
    // check we have pairs of numbers for the plugboard
    if (error == 0 && transformation.size() % 2 != 0){
        cout << "incorrect number of pairs " << transformation.size() << endl;
        error = 6;
    }
    config_file.close();
}

/*
int main()
{
    int error = 0;
    Plugboard plugboard("plugboards/error_test.pb", error);
    //Plugboard plugboard("plugboards/I.pb", error);
    if (error != 0){
        cout << "error " << error << endl;
    }else {
        cout << "success!" << endl;
    }
    return 0;
}
*/
