EXEC=main
ALLSRC=*.cpp
CXXFLAGS=-std=c++14 -Wall -g --pedantic
# mozna dodac powyzej  --pedantic

$(EXEC): $(ALLSRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

run:
	clear
	./$(EXEC)


clean:
	rm -f $(EXEC) *.o
