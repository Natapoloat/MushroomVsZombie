#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int aniFrame = 0;
float zomX = 600;
float zomY = 56;
float countZom = 0;


void zomwalk()
{

}

int main()
{
    float mushX = 139;
    float mushY = 56;
	//Window
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::Event ev;

    //Texture
    sf::Texture textureBg;
    textureBg.loadFromFile("background.png");
    sf::Texture textureMush;
    textureMush.loadFromFile("mushroomgay.png");
    sf::Texture textureZomwalk;
    textureZomwalk.loadFromFile("zombiewalk.png");

    //Sprite
    sf::Sprite spriteBg;
    spriteBg.setTexture(textureBg);
    spriteBg.setPosition(0, 0);
    sf::Sprite spriteMush;
    spriteMush.setTexture(textureMush);
    spriteMush.setPosition(mushX, mushY);
    int spriteSizeX = textureMush.getSize().x / 2;
    int spriteSizeY = textureMush.getSize().y / 3;
    spriteMush.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
    //Sprite Zombie
    sf::Sprite spriteZomwalk;
    spriteZomwalk.setTexture(textureZomwalk);
    spriteZomwalk.setPosition(zomX, zomY);
    int spriteZomSizeX = textureZomwalk.getSize().x / 4;
    int spriteZomSizeY = textureZomwalk.getSize().y / 2;
    spriteZomwalk.setTextureRect(sf::IntRect(0, 0, spriteZomSizeX, spriteZomSizeY));



    //Gameloop
    while (window.isOpen())
    {
        //Event Polling
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();
            if (ev.type == sf::Event::KeyPressed)
            {
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
                if (ev.key.code == sf::Keyboard::Up)
                {
                    if (mushY > 56)
                    {
                        spriteMush.move(0, -82);
                        //spriteMush.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
                        mushY -= 82;
                    }
                }
                if (ev.key.code == sf::Keyboard::Down)
                {
                    if (mushY < 384)
                    {
                        spriteMush.move(0, 82);
                        //spriteMush.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));
                        mushY += 82;
                    }
                }
            }

        }
        //zomwalk
        spriteZomwalk.move(-0.01, 0);
        zomX -= 0.01;
        countZom += 0.01;
        if (countZom >= 5)
        {
            //printf_s("%f", countZom);
            printf_s("%d", aniFrame);
            spriteZomwalk.setTextureRect(sf::IntRect(spriteZomSizeX * aniFrame, 0, spriteZomSizeX, spriteZomSizeY));
            countZom = 0;
            aniFrame++;
        }
        if (aniFrame >= 3) {
            aniFrame = 0;
        }
        if (zomX <= 200) {
            zomX = 600;
            spriteZomwalk.setPosition(zomX, zomY);
        }

        //Render
        window.clear();
        window.draw(spriteBg);
        window.draw(spriteMush);
        window.draw(spriteZomwalk);
        window.display();
    }

	//End application
	return 0;
}