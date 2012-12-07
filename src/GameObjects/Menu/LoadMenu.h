#ifndef LOADMENU_H
#define LOADMENU_H
#include <string>
#include <vector>

#include "Menu.h"

class LoadMenu : public Menu
{
    public:
        LoadMenu();
        virtual ~LoadMenu();
        bool update();
		void loadSaveData();//Load or reload savedata for buttons
    protected:
    private:
        std::vector<LoadPair> loadVectorData;
        int scrollLenght;

        void updateLoadButtons();
};

#endif // LOADMENU_H
