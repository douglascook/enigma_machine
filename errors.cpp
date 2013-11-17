#include <iostream>
#include <fstream>

#include "errors.h"
// need to include encryptor for alphabet size
#include "encryptor.h"

using namespace std;

int check_files(int file_count, const char **filepaths, vector<vector<int> > &input_vectors)
{
    int next;
    ifstream config_file;
    vector<int> transformation;

    // check for sufficient number of config files 
    if (file_count < 2){
        cout << "Too few configuration files provided." << endl;
        return INSUFFICIENT_NUMBER_OF_PARAMETERS;
    }

    // skip first argument as it is the program itself
    for (int i = 1; i <= file_count; i++){

        config_file.open(filepaths[i]);

        // check that file can be opened
        if (config_file.fail()){
            cout << "Error opening configuration file." << endl;
            return ERROR_OPENING_CONFIGURATION_FILE;
        }

        // this sets EOF flag if file is empty, needed so we dont check inputs of null plugboard
        // if any other files are empty error will be caught below
        config_file.peek();

        // loop through config file checking each number is valid
        while (!config_file.eof()){

            // check the character is numeric 
            if (!(config_file >> next)){
                cout << "Non-numeric character in configuration file." << endl;
                return NON_NUMERIC_CHARACTER;
            }

            // check for correct index ie between A and Z
            if (next < 0 || next > static_cast<int>(ALPHABET_SIZE - 1)){
                cout << "Invalid index in configuration file." << endl;
                return INVALID_INDEX;
            }

            // loop through to check if number has already been used
            // only need to do this for the initial 26 numbers
            // dont do it for the position file 
            // if there is only a plugboard and reflector still need to check reflector
            if (transformation.size() < ALPHABET_SIZE && (file_count == 2 || i != file_count)){
                for (unsigned j = 0; j < transformation.size(); j++){
                    // check if value is going to be repeated
                    if (transformation[j] == static_cast<int>(next)){
                        switch (i){
                            case 1:
                                cout << "Impossible plugboard configuration." << endl;
                                return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
                            case 2:
                                cout << "Invalid reflector mapping." << endl;
                                return INVALID_REFLECTOR_MAPPING;
                            default:
                                cout << "Invalid rotor mapping." << endl;
                                return INVALID_ROTOR_MAPPING;
                        }
                    }
                }
            }
            transformation.push_back(next);
            config_file >> ws;
        }

        // check plugboard has even number of inputs 
        if (i == 1 && transformation.size() % 2 != 0){
            cout << "Incorrect number of plugboard parameters." << endl;
            return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
        }

        // check reflector has correct number of inputs 
        if (i == 2 && transformation.size() != ALPHABET_SIZE){
            cout << "Incorrect number of reflector parameters." << endl;
            return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
        }

        // check rotor has mappings for all letters 
        if (i > 2 && i < file_count && transformation.size() < ALPHABET_SIZE){
            cout << "Invalid rotor mapping." << endl;
            return INVALID_ROTOR_MAPPING;
        }

        // check position file specifies starting positions for all rotors 
        if ((i == file_count) && static_cast<int>(transformation.size()) < file_count-3){
            cout << "Too few starting positions provided for rotors." << endl;
            return NO_ROTOR_STARTING_POSITION;
        }

        config_file.close();
        // add to input vectors
        input_vectors.push_back(transformation);
        // wipe vector to be ready for next
        transformation.clear();
    }
    return NO_ERROR;
}

bool invalid_character(char ch)
{
    // if the character is not a capital letter (based on ascii codes)
    if (ch < 65 || ch > 90){
        cout << "Invalid input character." << endl;
        return true;
    }
    return false;
}
