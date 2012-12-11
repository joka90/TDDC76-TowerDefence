TDDC76-TowerDefence
=============
*Build SFML2.0*

To compile on ubuntu download SFML2.0 to ../SFML relative to this folder

	git clone git://github.com/LaurentGomila/SFML.git
	sudo apt-get install cmake gcc-4.4 g++-4.4 libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew1.5-dev libjpeg8-dev libsndfile1-dev libopenal-dev
	cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release -D BUILD_SHARED_LIBS=TRUE .
	make

If you want to intall the built libs.

	sudo make install 

If you haven't installed the libs. You need to execute everytime you open a new terminalwindow to lauch a SFML application.

	export LD_LIBRARY_PATH=../SFML/lib

*To build TDDC76-TowerDefence on Linux*

Run make file, you need gcc-4.4 and some dev files.
You may also need to export the sfml lib path for the libraries to load properly 

	export LD_LIBRARY_PATH=../SFML/lib

---------------------------------------

*To build on windows*

Download SFML2.0 for windows to ../SFML  relative to this folder and run the project in codeblocks, you may need to copy ../SFML/bin/*.dll to bin/Release if you get the missing dll error.

CodeBlocks and mingW: http://prdownload.berlios.de/codeblocks/codeblocks-10.05mingw-setup.exe
SFML2.0 for windows:  http://www.sfml-dev.org/download/2.0-rc/SFML-2.0-rc-windows-32-gcc4-sjlj.zip

Source:
https://github.com/joka90/TDDC76-TowerDefence

Currently private.
