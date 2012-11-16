# Kompilator
CXX = g++-4.4

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
CPPFLAGS += -I../SFML/include/

# L�nkflaggor - Fix f�r att l�sa lokala problem med C++ l�nkbibliotek.
LDFLAGS += -L../SFML/lib/

# Objektkodsmoduler som ing�r i den kompletta kalkylatorn.
OBJECTS = main.o AnimatedSprite.o

# Huvudm�l - skapas med kommandot 'make' eller 'make kalkylator'.
main: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o main $(OBJECTS)

# Delm�l (flaggan -c avbryter innan l�nkning, objektkodsfil erh�lls)
main.o: main.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c main.cc


# Delm�l (flaggan -c avbryter innan l�nkning, objektkodsfil erh�lls)
AnimatedSprite.o: src/AnimatedSprite.h src/AnimatedSprite.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/AnimatedSprite.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core
