output: Hwk4.o Functions.o Crew.o Crews.o Plane.o Planes.o Flight.o Flights.o
	g++ -o output Hwk4.o Functions.o Crew.o Crews.o Plane.o Planes.o Flight.o Flights.o
Hwk4.o: Hwk4.cpp Functions.h Planes.h Plane.h Crews.h Crew.h Flights.h Flight.h
	g++ -c Hwk4.cpp
Functions.o: Functions.cpp Functions.h Planes.h Plane.h Crews.h Crew.h Flights.h Flight.h
	g++ -c Functions.cpp
Crew.o: Crew.cpp Crew.h
	g++ -c Crew.cpp
Crews.o: Crews.cpp Crews.h Crew.h
	g++ -c Crews.cpp
Plane.o: Plane.cpp Plane.h
	g++ -c Plane.cpp
Planes.o: Planes.cpp Planes.h Plane.h
	g++ -c Planes.cpp
Flight.o: Flight.cpp Flight.h
	g++ -c Flight.cpp
Flights.o: Flights.cpp Flights.h Flight.h
	g++ -c Flights.cpp
clean:
	rm *.o output
