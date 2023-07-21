CC = g++
SRCS = main.cpp solution/Solution.cpp star/Star.cpp integrator/Integrator.cpp dataStructures/coords/CartesianCoords.cpp dataStructures/coords/EquatorialCoords.cpp dataStructures/velocity/Velocity.cpp dataStructures/StateVector.cpp dataStructures/Matrix.cpp dataStructures/date/Date.cpp dataStructures/ModelVector.cpp GaussNewton//GaussNewton.cpp

TARGET = main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) -o $@ $^


clean:
	rm -f $(TARGET)