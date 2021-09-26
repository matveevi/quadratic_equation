SRCDIR = src
BINDIR = bin
INTDIR = $(BINDIR)/intermediates
EXE = $(BINDIR)/quadratic_equation.exe

$(EXE): $(SRCDIR)/quadratic_equation.h $(INTDIR)/quadratic_equation.o $(INTDIR)/main.o
	$(CXX) $(INTDIR)/quadratic_equation.o $(INTDIR)/main.o -o $(EXE)
$(INTDIR)/quadratic_equation.o : $(SRCDIR)/quadratic_equation.cpp $(SRCDIR)/quadratic_equation.h
	$(CXX) -c $(SRCDIR)/quadratic_equation.cpp -o $(INTDIR)/quadratic_equation.o
$(INTDIR)/main.o : $(SRCDIR)/main.cpp $(SRCDIR)/quadratic_equation.h
	$(CXX) -c $(SRCDIR)/main.cpp -o $(INTDIR)/main.o

init:
	mkdir -p $(INTDIR)

clean:
	rm -f $(EXE) $(INTDIR)/quadratic_equation.o $(INTDIR)/main.o
