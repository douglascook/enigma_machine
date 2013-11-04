#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#include "encryptor.h"
#include "rotor.h"

using namespace std;

/* vector examples, change everything to use this!!
    vector<int> e;
    e.resize(26);
    for(int i=0;i<e.size();i++)
{
    int* f = &e[0];
    e[7] = 8;
}    
*/

// may want to change this to use proper strings
Rotor::Rotor(const char *filepath, int& error){
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
        // now deal with the notches
        }else if (transformation.size() == 26){
            // make sure notch has not already been used 
            if (rotate_notch.size() > 0){
                for (int i = 0; i < rotate_notch.size(); i++){
                    if (rotate_notch[i] == next){
                        cout << "notch rotate element " << i << " number already used" << endl;
                        error = 7;
                        break;
                    }
                }
            }
            if (error == 0){
                rotate_notch.push_back(next);
            }

        }else {
            // loop through to check if number has already been used
            // make sure not to check notch values
            for (int i = 0; i < transformation.size(); i++){
                if (transformation[i] == next){
                    cout << "transformation element " << i << " number already used" << endl;
                    error = 7;
                    break;
                }
            }

            // if we have got an error then terminate
            if (error == 0){
                transformation.push_back(next);
            }
        }
        // strip out remaining whitespace so we get to end of file properly
        config_file >> ws;
    }

    // check for correct number of mappings and notches 
    if (error == 0 && (transformation.size() != 26 || rotate_notch.size() > 26)){
        cout << "incorrect rotor mapping" << endl;
        error = 7;
    }
    config_file.close();
}

void Rotor::rotate()
{
    current_position = (current_position + 1) % 26;
}

/*
int main()
{
    int error = 0;

    Rotor rotor("rotors/error_test.rot", error);
    //Rotor rotor("rotors/I.rot", error);
    if (error != 0){
        cout << "error " << error << endl;
    }else {
        cout << "success!" << endl;
    }
    
    for (int i = 0; i < rotor.transformation.size(); i++){
        cout << rotor.transformation[i] << " ";
    }
    cout << endl;
    
    cout << endl << "there should be " << rotor.rotate_notch.size() << " notches" << endl;
    for (int i = 0; i < rotor.rotate_notch.size(); i++){
        cout << rotor.rotate_notch[i] << endl;
    }

    return 0;
}
*/
