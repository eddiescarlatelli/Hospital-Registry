TARGET = ExercicioArvore
CC = g++
LD = g++
WARN = -Wall -std=c++11
OBJS = main.cpp cadastro.h paciente.cpp arvore.h

all: $(OBJS)
	$(LD) $(WARN) -o $(TARGET) $(OBJS)