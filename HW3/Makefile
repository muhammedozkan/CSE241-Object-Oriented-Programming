151044084_HW2 : Circle.o Rectangle.o Triangle.o ComposedShape.o UserInputValue.o 151044084_main.o
	g++ -o 151044084_HW3 Circle.o Rectangle.o Triangle.o ComposedShape.o UserInputValue.o 151044084_main.o

Circle.o : Circle.cpp
	g++ -c -std=c++11 -Wall Circle.cpp	
	
Rectangle.o : Rectangle.cpp
	g++ -c -std=c++11 -Wall Rectangle.cpp	
	
Triangle.o : Triangle.cpp
	g++ -c -std=c++11 -Wall Triangle.cpp	
	
ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 -Wall ComposedShape.cpp

UserInputValue.o : UserInputValue.cpp
	g++ -c -std=c++11 -Wall UserInputValue.cpp

151044084_main.o : 151044084_main.cpp
	g++ -c -std=c++11 -Wall 151044084_main.cpp

clean:
	rm *.o *.svg 151044084_HW3
