
EXEC=main
ALLSRC=*.cpp
CXXFLAGS=-std=c++14 -Wall  -g  --pedantic
# mozna dodac powyzej  --pednatic

$(EXEC): $(ALLSRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXEC) *.o
