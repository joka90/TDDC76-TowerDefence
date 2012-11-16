#
# Makefile f�r kalkylatorn, niv� G, GNU GCC (g++)
#
# Variabeln GCC4_V (se LDFLAGS) s�tts i prog/gcc/4 och anger den aktuella 
# versionen av GCC 4 (normalt den senaste som �r installerad p� IDA).
#
# gccfilter �r ett hj�lpmedel f�r att f�renkla och f�rgl�gga diagnostiska
# meddelanden fr�n g++ (gcc).
#

# Filkataloger d�r andra delar av programet finns.
#EXPRESSION = ../Expression

# Kompilator
#CCC = g++
CXX = g++-4.4

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
CPPFLAGS += -I../SFML/include/
#CPPFLAGS += -I../sfml-2.0/include/

# L�nkflaggor - Fix f�r att l�sa lokala problem med C++ l�nkbibliotek.
LDFLAGS += -L../SFML/lib/
#LDFLAGS += -L../SFML/lib/
# Objektkodsmoduler som ing�r i den kompletta kalkylatorn.
OBJECTS = test.o

# Huvudm�l - skapas med kommandot 'make' eller 'make kalkylator'.
test: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o test $(OBJECTS)

# Delm�l (flaggan -c avbryter innan l�nkning, objektkodsfil erh�lls)
test.o: test.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c test.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core

# 'make zap' tar �ven bort det k�rbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf kalkylator *~

# Se upp vid eventuell �ndring, '*' f�r absolut inte finnas f�r sig!!!
#
# '@' medf�r att kommandot inte skrivs ut p� sk�rmen d� det utf�rs av make.
# 'rm' �r ett alias f�r 'rm -i' p� IDA:s system, '\rm' inneb�r att "original-
# versionen", utan flaggan '-i', anv�nds. 
