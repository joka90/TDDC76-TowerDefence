# Kompilator
CXX = g++-4.4

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I../SFML/include/

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L../SFML/lib/

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = main.o AnimatedSprite.o

# Huvudmål - skapas med kommandot 'make' eller 'make kalkylator'.
main: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o main $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
main.o: main.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c main.cc


# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
AnimatedSprite.o: src/AnimatedSprite.h src/AnimatedSprite.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/AnimatedSprite.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core
