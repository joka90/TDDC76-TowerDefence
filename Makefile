# Kompilator
CXX = g++-4.4

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I../SFML/include/

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L../SFML/lib/

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = main.o AnimatedSprite.o GameHandler.o EventHandler.o Level.o Wave.o WaveHandler.o ClickManager.o MapMatrix.o Player.o GameObject.o Menu.o Button.o StartMenu.o LoadMenu.o TrackMenu.o Loader.o SoundLoader.o MusicLoader.o MusicLoader.o TextureLoader.o

# Huvudmål - skapas med kommandot 'make' eller 'make kalkylator'.
TD: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o TD $(OBJECTS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
main.o: main.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c main.cc


# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
AnimatedSprite.o: src/AnimatedSprite.h src/AnimatedSprite.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/AnimatedSprite.cc

GameHandler.o: src/GameHandler.h src/GameHandler.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameHandler.cc

EventHandler.o: src/EventHandler.h src/EventHandler.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/EventHandler.cc

Level.o: src/Level.h src/Level.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Level.cc

Wave.o: src/Wave/Wave.h src/Wave/Wave.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Wave/Wave.cc

WaveHandler.o: src/Wave/WaveHandler.h src/Wave/WaveHandler.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Wave/WaveHandler.cc

ClickManager.o: src/ClickManager/ClickManager.h src/ClickManager/ClickManager.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClickManager/ClickManager.cc

MapMatrix.o: src/ClickManager/MapMatrix.h src/ClickManager/MapMatrix.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClickManager/MapMatrix.cc

Player.o: src/ClickManager/Player.h src/ClickManager/Player.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClickManager/Player.cc

GameObject.o: src/GameObject/GameObject.h src/GameObject/GameObject.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObject/GameObject.cc

Tower.o: src/GameObject/Tower/Tower.h src/GameObject/Tower/Tower.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObject/Tower/Tower.cc

Enemies.o: src/GameObject/Enemies/Enemies.h src/GameObject/Enemies/Enemies.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObject/Enemies/Enemies.cc

Projectiles.o: src/GameObject/Projectiles/Projectiles.h src/GameObject/Projectiles/Projectiles.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObject/Projectiles/Projectiles.cc

Menu.o: src/GameObject/Menu/Menu.h src/Menu/Menu.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/Menu.cc

Button.o: src/GameObject/Menu/Button.h src/Menu/Button.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/Button.cc

StartMenu.o: src/GameObject/Menu/StartMenu.h src/Menu/StartMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/StartMenu.cpp

LoadMenu.o: src/GameObject/Menu/LoadMenu.h src/Menu/LoadMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/LoadMenu.cpp

TrackMenu.o: src/GameObject/Menu/TrackMenu.h src/Menu/TrackMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Menu/TrackMenu.cpp

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
