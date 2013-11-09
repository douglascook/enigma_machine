#include "encryptor.h"
#include "rotor.h"

using namespace std;

Rotor::Rotor(vector<int> input, int position)
    : offset(position)
{
    transformation.resize(26);
    transformation_reverse.resize(26);
    notches.resize(input.size()-26);

    // create mappings
    for (int i = 0; i < 26; i++){
        transformation[i] = input[i];
        transformation_reverse[input[i]] = i;
    }

    // now create array for notches 
    for (int i = 26; i < input.size(); i++){
        notches[i-26] = input[i];
    }
}

bool Rotor::rotate()
{
    offset = (++offset) % 26;

    for (int i = 0; i < notches.size(); i++){
        // if the current top letter matches a notch then want to rotate next
        if (offset == notches[i]){
            return true;
        }
    }
    return false;
}

int Rotor::encrypt(int letter, bool return_trip)
{
    if (return_trip){
        // use reverse mappings for return trip
        return (transformation_reverse[(letter + offset) % 26] - offset + 26) % 26;
    }else{
        // this will return encrypted version of current letter 
        return (transformation[(letter + offset) % 26] - offset + 26) % 26;
    }
}
