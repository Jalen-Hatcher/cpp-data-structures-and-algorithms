++ = g++
OBJ = obj
SRC = src
HDR = $(SRC)/includes
BINDIR = bin
DEPS = $(HDR)/queue.h
CFLAGS = -I $(HDR)

$(BINDIR)/out: $(OBJ)/main.o $(OBJ)/queue.o
	$(++) -o $@ $^ $(CFLAGS) && ./$(BINDIR)/out

$(OBJ)/main.o: $(SRC)/main.cpp $(DEPS)
	$(++) -c -o $@ $< $(CFLAGS)

$(OBJ)/queue.o: $(HDR)/queue.cpp $(DEPS)
	$(++) -c $< -o $@ $(CFLAGS)

run:
	./$(BINDIR)/out

clean: 
	rm $(BINDIR)/* $(OBJ)/*