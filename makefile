enigma : main.o errors.o enigmaMachine.o encryptor.o plugboard.o rotor.o reflector.o
	g++ -Wall -g main.o errors.o enigmaMachine.o encryptor.o plugboard.o rotor.o reflector.o -o enigma
main.o : main.cpp enigmaMachine.h
	g++ -Wall -g -c main.cpp
errors.o : errors.cpp errors.h
	g++ -Wall -g -c errors.cpp
enigmaMachine.o : enigmaMachine.cpp enigmaMachine.h encryptor.h plugboard.h rotor.h reflector.h
	g++ -Wall -g -c enigmaMachine.cpp
encryptor.o : encryptor.cpp encryptor.h 
	g++ -Wall -g -c encryptor.cpp
plugboard.o : plugboard.cpp plugboard.h encryptor.h 
	g++ -Wall -g -c plugboard.cpp
rotor.o : rotor.cpp rotor.h encryptor.h 
	g++ -Wall -g -c rotor.cpp
reflector.o : reflector.cpp reflector.h encryptor.h 
	g++ -Wall -g -c reflector.cpp
clean :
	rm -f *.o enigma
