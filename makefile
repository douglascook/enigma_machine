enigma : main.o enigmaMachine.o
	g++ -Wall -g main.o enigmaMachine.o -o enigma
main.o : main.cpp enigmaMachine.h
	g++ -Wall -g -c main.cpp
enigmaMachine.o : enigmaMachine.cpp enigmaMachine.h encryptor.h plugboard.h rotor.h reflector.h
	g++ -Wall -g -c enigmaMachine.cpp
rotor.o : rotor.cpp rotor.h encryptor.h 
	g++ -Wall -g -c rotor.cpp
reflector.o : reflector.cpp reflector.h encryptor.h 
	g++ -Wall -g -c reflector.cpp
plugboard.o : plugboard.cpp plugboard.h encryptor.h 
	g++ -Wall -g -c plugboard.cpp
encryptor.o : encryptor.h 
	g++ -Wall -g -c encryptor.cpp
clean :
	rm -f *.o enigma
