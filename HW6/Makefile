151044084_HW6 : Collection.o Set.o List.o Queue.o  HashSet.o ArrayList.o LinkedList.o Iterator.o 151044084_main.o
	g++ -o 151044084_HW6 Collection.o Set.o List.o Queue.o HashSet.o ArrayList.o LinkedList.o Iterator.o  151044084_main.o

Collection.o : Collection.cpp
	g++ -c -std=c++11 -Wall Collection.cpp	
	
Set.o : Set.cpp
	g++ -c -std=c++11 -Wall Set.cpp	
	
List.o : List.cpp
	g++ -c -std=c++11 -Wall List.cpp	
	
Queue.o : Queue.cpp
	g++ -c -std=c++11 -Wall Queue.cpp	
	
HashSet.o : HashSet.cpp
	g++ -c -std=c++11 -Wall HashSet.cpp	

ArrayList.o : ArrayList.cpp
	g++ -c -std=c++11 -Wall ArrayList.cpp		
	
LinkedList.o : LinkedList.cpp
	g++ -c -std=c++11 -Wall LinkedList.cpp	
	
Iterator.o : Iterator.cpp
	g++ -c -std=c++11 -Wall Iterator.cpp
	
151044084_main.o : 151044084_main.cpp
	g++ -c -std=c++11 -Wall 151044084_main.cpp

clean:
	rm *.o *.svg 151044084_HW6

run: 151044084_HW6
	./151044084_HW6