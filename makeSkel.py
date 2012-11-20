klasser = [ ["src/GameObjects/Towers/","Tower"],
                ["src/GameObjects/Projectiles/","Projectile"],
                ["src/GameObjects/Enemies/","Enemy"],
                ["src/GameObjects/VisualEffects/","VisualEffect"]]

#ccfile = "#include "{className}.h"\n{className}::{className}()\n{\n\n}\n"
#hfile = "#ifndef  {classNameCAP}_H\n#define {classNameCAP}_H\n\nclass className\n{\npublic:\n}"

for klass in klasser:
    folder=klass[0]
    filename=klass[1]
    f = open(folder+filename+".cc", 'w')# ========== cc file
    f.write("""#include "%(className)s.h"
%(className)s::%(className)s(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader, class FontLoader* inFontLoader)
:GameObject(newX, newY, inTextureLoader, "ENFINBILD")//skall denna vara har, pure virtual senare?
{

}

bool %(className)s::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
""" % {"className" : filename})
    f.close()
    f = open(folder+filename+".h", 'w')# ========== header file
    f.write("""#ifndef  %(classNameCAP)s_H
#define %(classNameCAP)s_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class %(className)s : public GameObject
{
public:
    %(className)s(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader, class FontLoader* inFontLoader);
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

};
#endif //end %(classNameCAP)s_H
"""% {"className" : filename, "classNameCAP" : filename.upper()})
    f.close()
