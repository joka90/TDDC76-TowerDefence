#
# Makefile för kalkylatorn, nivå G, GNU GCC (g++)
#
# Variabeln GCC4_V (se LDFLAGS) sätts i prog/gcc/4 och anger den aktuella 
# versionen av GCC 4 (normalt den senaste som är installerad på IDA).
#
# gccfilter är ett hjälpmedel för att förenkla och färglägga diagnostiska
# meddelanden från g++ (gcc).
#

# Filkataloger där andra delar av programet finns.
#EXPRESSION = ../Expression

# Kompilator
#CCC = g++
CXX = g++-4.4

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I../SFML/include/
#CPPFLAGS += -I../sfml-2.0/include/

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L../SFML/lib/
#LDFLAGS += -L../SFML/lib/
# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = test.o

# Huvudmål - skapas med kommandot 'make' eller 'make kalkylator'.
test: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o test $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
test.o: test.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c test.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~

# Se upp vid eventuell ändring, '*' får absolut inte finnas för sig!!!
#
# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan flaggan '-i', används. 
