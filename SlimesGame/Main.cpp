#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{

    sf::Vector2f playerPos(0.f, 0.f);
    float pxv = 0.f;
    float pyv = 0.f;

    sf::RenderWindow window(sf::VideoMode(800, 600), "That Time I Got Reincarnated as a Slime", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture slimeTexture;
    if (!slimeTexture.loadFromFile("./assets/slime.png")) {
        printf("There was an error loading slime texture!");
    }

    sf::Sprite slimeSprite;
    slimeSprite.setTexture(slimeTexture);

    // window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Key Press Detection
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            if (abs(pyv) < 6) pyv -= 0.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if (abs(pyv) < 6) pyv += 0.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            if (abs(pxv) < 6) pxv -= 0.1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if (abs(pxv) < 6) pxv += 0.1;

        pxv *= 0.75;
        pyv *= 0.75;

        printf("PXV: %f \n", pxv);

        //playerPos.x += pxv;
        //playerPos.y += pyv;

        window.clear(sf::Color::Black);

        slimeSprite.move(pxv, pyv);
        window.draw(slimeSprite);
        window.display();
    }

    return 0;
}