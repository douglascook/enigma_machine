#include <iostream>
#include <string>
#include <vector>
#include "enigmaMachine.h"

using namespace std;

// first parameter contains number of arguments, second contains the values
int main(int argc, char **argv)
{
    vector<string> config_files;
    //config_files.size(argc - 1);
    for (int i = 1; i < argc; i++){
        // convert to string to put in vector
        string arg_string = argv[i];
        config_files.push_back(arg_string);
    }
    
    //EnigmaMachine::EnigmaMachine enigma((argc - 1), &config_files);
    

   /* 
	cout << "You have passed " << argc << " arguments." << endl
	     << "In order they are:" << endl;

    for (int i = 1; i < argc; i++){

        cout << argv[i] << endl;
        ifstream in(argv[i]);

        int numbers[100];
        int j = 0;
        // this loops through each file and creates an array for the relevant encryptor
        // add this to each encryptor, will need to use different method for the rotors as format is different
        while (!in.eof()){
            in >> numbers[j];
            j++;
        }
        cout << *numbers << endl;
    }
    */
 
    return 1;
}

// main file to loop until std input is closed and encrypt the characters one by one
