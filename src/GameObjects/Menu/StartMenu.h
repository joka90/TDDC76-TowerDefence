#ifndef STARTMENU_H
#define STARTMENU_H


class StartMenu : public Menu
{
    public:
        StartMenu(class TextureLoader* textures);
        virtual ~StartMenu();
        bool update();
    protected:
    private:
};

#endif // STARTMENU_H
