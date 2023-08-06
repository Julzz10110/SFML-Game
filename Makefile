TARGET = start
CPP = g++

PREF_SRC = ./src/
PREF_OBJ = ./obj/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET) : $(OBJ)
	$(CPP) $(OBJ) -o $(TARGET) -lsfml-system -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	$(CPP) -c $< -o $@

clean : 
	rm $(TARGET) $(PREF_OBJ)*.o