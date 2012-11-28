# Kompilator
CXX = g++-4.4

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++0x -pedantic -Wall -Wextra -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
CPPFLAGS += -I../SFML/include/

# Länkflaggor - Fix för att lösa lokala problem med C++ länkbibliotek.
LDFLAGS += -L../SFML/lib/

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = main.o AnimatedSprite.o GameHandler.o EventHandler.o Level.o Wave.o WaveHandler.o ClickManager.o MapMatrix.o Player.o GameObject.o Enemy.o Tower.o Projectile.o Menu.o Button.o StartMenu.o LoadMenu.o TrackMenu.o Loader.o SoundLoader.o MusicLoader.o TextureLoader.o FontLoader.o ClassManager.o BuyMenu.o

# Huvudmål
TD: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o TD $(OBJECTS)


Release: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o TD $(OBJECTS)  -g -00

Debug: $(OBJECTS) Makefile
	$(CXX) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o TD $(OBJECTS) -g -00

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

Wave.o: src/Wave/Wave.h src/Wave/Wave.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Wave/Wave.cpp

WaveHandler.o: src/Wave/WaveHandler.h src/Wave/WaveHandler.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Wave/WaveHandler.cpp

ClickManager.o: src/ClickManager/ClickManager.h src/ClickManager/ClickManager.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClickManager/ClickManager.cpp

MapMatrix.o: src/ClickManager/MapMatrix.h src/ClickManager/MapMatrix.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClickManager/MapMatrix.cpp

Player.o: src/ClickManager/Player.h src/ClickManager/Player.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClickManager/Player.cpp

GameObject.o: src/GameObjects/GameObject.h src/GameObjects/GameObject.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/GameObject.cpp

Tower.o: src/GameObjects/Towers/Tower.h src/GameObjects/Towers/Tower.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Towers/Tower.cc

Enemy.o: src/GameObjects/Enemies/Enemy.h src/GameObjects/Enemies/Enemy.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Enemies/Enemy.cc

Projectile.o: src/GameObjects/Projectiles/Projectile.h src/GameObjects/Projectiles/Projectile.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Projectiles/Projectile.cc

Menu.o: src/GameObjects/Menu/Menu.h src/GameObjects/Menu/Menu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Menu/Menu.cpp

Button.o: src/GameObjects/Menu/Button.h src/GameObjects/Menu/Button.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Menu/Button.cpp

StartMenu.o: src/GameObjects/Menu/StartMenu.h src/GameObjects/Menu/StartMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Menu/StartMenu.cpp

LoadMenu.o: src/GameObjects/Menu/LoadMenu.h src/GameObjects/Menu/LoadMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Menu/LoadMenu.cpp

TrackMenu.o: src/GameObjects/Menu/TrackMenu.h src/GameObjects/Menu/TrackMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Menu/TrackMenu.cpp

Loader.o: src/Loader/Loader.h src/Loader/Loader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/Loader.cc

SoundLoader.o: src/Loader/SoundLoader.h src/Loader/SoundLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/SoundLoader.cc

MusicLoader.o: src/Loader/MusicLoader.h src/Loader/MusicLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/MusicLoader.cc

TextureLoader.o: src/Loader/TextureLoader.h src/Loader/TextureLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/TextureLoader.cc

FontLoader.o: src/Loader/FontLoader.h src/Loader/FontLoader.cc
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/Loader/FontLoader.cc

ClassManager.o: src/ClassManager.h src/ClassManager.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/ClassManager.cpp

BuyMenu.o: src/GameObjects/Menu/BuyMenu.h src/GameObjects/Menu/BuyMenu.cpp
	$(CXX) $(CPPFLAGS) $(CCFLAGS) -c src/GameObjects/Menu/BuyMenu.cpp



# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o core
