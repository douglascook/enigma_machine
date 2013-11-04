#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include "encryptor.h"
#include "reflector.h"

using namespace std;

// may want to change this to use proper strings
Reflector::Reflector(const char *filepath, int& error)
{
    int next;
    ifstream config_file(filepath);
    assert(config_file);

    // loop through config file checking each number is valid
    while (!config_file.eof()){
        // firstly check its numeric
        if (!(config_file >> next)){
            cout << "non-integer character" << endl;
            error = 4;
            break;
        // check for correct index ie between A and Z
        }else if (next < 0 || next > 25){
            cout << "invalid index" << endl;
            error = 3;
            break;
        }else {
            // loop through to check if number has already been used
            for (int i = 0; i < transformation.size(); i++){
                if (transformation[i] == next){
                    cout << "number already used" << endl;
                    error = 9;
                }
            }
            
            // if we've got an error then terminate
            if (error == 0){
                transformation.push_back(next);
                // strip out remaining whitespace so we get to end of file properly
                config_file >> ws;
            }else {
                break;
            }
        }
    }
    // check for 13 pairs in reflector
    if (error == 0 && transformation.size() != 26){
        cout << "incorrect number of pairs" << endl;
        error = 10;
    }
    config_file.close();
}

/*
int main()
{
    int error = 0;
    Reflector reflector("reflectors/error_test.rf", error);
    if (error != 0){
        cout << "error " << error << endl;
    }else {
        cout << "success!" << endl;
    }
    return 0;
}
*/
