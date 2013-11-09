#include <iostream>
#include <fstream>

#include "errors.h"
#include "enigmaMachine.h"

using namespace std;

// function to check files (should move this to its own header maybe?)
int check_files(int argc, char **argv, vector<vector<int> > &input_vectors);

// describe errors
void report_errors(int error_num);

// first parameter contains number of arguments, second contains the values
int main(int argc, char **argv)
{
    int error_num = 0;
    vector<vector<int> > input_vectors;

    // first want to check that the files are valid
    error_num = check_files(argc - 1, argv, input_vectors);
    if (error_num > 0){
        report_errors(error_num);
        // correct way to exit from error
        return error_num;
    }

    // now initialise the machine
    EnigmaMachine enigma(argc, input_vectors);

    enigma.construct_encryptors();

    char ch;
    while (cin >> ch){
        // strip whitespace
        cin >> ws;
        cout << enigma.encrypt(ch);
    }
    cout << endl;

    return 1;
}

// main file to loop until std input is closed and encrypt the characters one by one

int check_files(int file_count, char **filepaths, vector<vector<int> > &input_vectors)
{
    int next;
    ifstream config_file;
    // use vector of vectors for this
    vector<int> transformation;

    // check there are sufficient number of parameters
    // 3 files means there is a rotor but no position file
    if (file_count < 2 || file_count == 3){
        return 1;
    }

    // loop through config files 
    // skip first argument as it is the file itself
    for (int i = 1; i <= file_count; i++){

        config_file.open(filepaths[i]);

        if (config_file.fail()){
            // error opening config file
            return 11;
        }

        if (config_file.peek() == '\0'){
            // this happens if the plugboard does nothing, so just skip to next config file
            break;
        }

        // loop through config file checking each number is valid
        while (!config_file.eof()){

            // firstly check its numeric
            if (!(config_file >> next)){
                return 4;
            }

            // check for correct index ie between A and Z
            if (next < 0 || next > 25){
                return 3;
            }

            // loop through to check if number has already been used
            // need to do this for all 3 but only up to 26 elements for the rotor

            if (transformation.size() >= 26){
                // need something to deal with the notches (depends on how the errors need to be dealt with)
                
            // dont want to do this for the position file 
            }else if (i != file_count){
                for (int j = 0; j < transformation.size(); j++){
                    if (transformation[j] == next){
                        // return error dependent on encryptor type
                        // no need for breaks as the returns are there
                        switch (i){
                            case 1:
                                return 5;
                            case 2:
                                return 9;
                            default:
                                // default case for rotors
                                return 7;
                        }
                    }
                }
            }

            // once we are here we know the element can be added for this input
            transformation.push_back(next);
            // strip out remaining whitespace so we get to end of file properly
            config_file >> ws;
        }

        // now need to do the separate checks

        // if plugboard has an odd number of inputs
        if (i == 1 && transformation.size() % 2 != 0){
            return 6;
        }

        // if reflector doesn't have 26 inputs 
        if (i == 2 && transformation.size() != 26){
            return 10;
        }

        // if rotor doesn't supply enough mappings
        if (i > 2 && i < file_count - 1 && transformation.size() < 26){
            return 7;
        }

        // if position file does not specify enough starting positions
        // need to cast size as int (signed) so it can be compared to -ve number
        if ((i == file_count-1) && static_cast<int>(transformation.size()) < file_count-3){
            return 8;
        }

        config_file.close();

        // add to input vectors
        input_vectors.push_back(transformation);
        // wipe vector to be ready for next
        transformation.clear();
    }
    // success!
    return 0;
}

void report_errors(int error_no)
{
    switch (error_no){
        case INSUFFICIENT_NUMBER_OF_PARAMETERS:
            cout << "Not enough configuration files provided." << endl;
            break;
        case INVALID_INPUT_CHARACTER:
            cout << "Invalid input character." << endl;
            break;
        case INVALID_INDEX:
            cout << "Invalid index, does not correspond to a letter." << endl;
            break;
        case NON_NUMERIC_CHARACTER:
            cout << "Non-numeric character in config file." << endl;
            break;
        case IMPOSSIBLE_PLUGBOARD_CONFIGURATION	:
            cout << "Impossible plugboard configuration." << endl;
            break;
        case INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS:
            cout << "Incorrect number of plugboard parameters." << endl;
            break;
        case INVALID_ROTOR_MAPPING:
            cout << "Invalid rotor mapping." << endl;
            break;
        case NO_ROTOR_STARTING_POSITION:
            cout << "No starting position provided for rotor." << endl;
            break;
        case INVALID_REFLECTOR_MAPPING:
            cout << "Invalid reflector mapping." << endl;
            break;
        case INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS:
            cout << "Incorrect number of reflector parameters." << endl;
            break;
        case ERROR_OPENING_CONFIGURATION_FILE:
            cout << "Error opening configuration file." << endl;
            break;
        case NO_ERROR:
            return;
    }
}
