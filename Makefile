# Kompilator
CXX = g++-4.4

# Kompilatorflaggor, l�gg till '-g' om kompilering f�r avlusning ska g�ras.
CCFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I l�gger till en filkatalog i inkluderingss�kv�gen.
CPPFLAGS += -I../SFML/include/

# L�nkflaggor - Fix f�r att l�sa lokala problem med C++ l�nkbibliotek.
LDFLAGS += -L../SFML/lib/

# Objektkodsmoduler som ing�r i den kompletta kalkylatorn.
OBJECTS = main.o AnimatedSprite.o GameHandler.o EventHandler.o Level.o Wave.o WaveHandler.o ClockManager.o MapMatrix.o Player.o GameObject.o Menu.o Button.o StartMenu.o LoadMenu.o TrackMenu.o Loader.o SoundLoader.o MusicLoader.o MusicLoader.o TextureLoader.o

# Huvudm�l - skapas med kommandot 'make' eller 'make kalkylator'.
TD: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o TD $(OBJECTS)

# Delm�l (flaggan -c avbryter innan l�nkning, objektkodsfil erh�lls)
main.o: main.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c main.cc


# Delm�l (flaggan -c avbryter innan l�nkning, objektkodsfil erh�lls)
AnimatedSprite.o: src/AnimatedSprite.h src/AnimatedSprite.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/AnimatedSprite.cc

GameHandler.o: src/GameHandler.h src/GameHandler.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameHandler.cc

EventHandler.o: src/EventHandler.h src/EventHandler.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/EventHandler.cc

Level.o: src/Level.h src/Level.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Level.cc

Wave.o: src/Wave.h src/Wave.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Wave.cc

WaveHandler.o: src/WaveHandler.h src/WaveHandler.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/WaveHandler.cc

ClockManager.o: src/ClockManager/ClockManager.h src/ClockManager/ClockManager.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClockManager/ClockManager.cc

MapMatrix.o: src/ClockManager/MapMatrix.h src/ClockManager/MapMatrix.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClockManager/MapMatrix.cc

Player.o: src/ClockManager/Player.h src/ClockManager/Player.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClockManager/Player.cc

GameObject.o: src/GameObject/GameObject.h src/GameObject/GameObject.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObject/GameObject.cc

Menu.o: src/GameObject/Menu/Menu.h src/Menu/Menu.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/Menu.cc

Button.o: src/GameObject/Menu/Button.h src/Menu/Button.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/Button.cc

StartMenu.o: src/GameObject/Menu/StartMenu.h src/Menu/StartMenu.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/StartMenu.cc

LoadMenu.o: src/GameObject/Menu/LoadMenu.h src/Menu/LoadMenu.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/LoadMenu.cc

TrackMenu.o: src/GameObject/Menu/TrackMenu.h src/Menu/TrackMenu.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/TrackMenu.cc

Loader.o: src/Loader/Loader.h src/Loader/Loader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/Loader.cc

SoundLoader.o: src/Loader/SoundLoader.h src/Loader/SoundLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/SoundLoader.cc

MusicLoader.o: src/Loader/MusicLoader.h src/Loader/MusicLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/MusicLoader.cc

TextureLoader.o: src/Loader/TextureLoader.h src/Loader/TextureLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/TextureLoader.cc



# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core
