#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

int main()
{

    sf::Vector2f playerPos(0.f, 0.f);
    float pxv = 0.f;
    float pyv = 0.f;

    float acceleration = 100.f;

    sf::RenderWindow window(sf::VideoMode(800, 600), "That Time I Got Reincarnated as a Slime", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture slimeTexture;
    if (!slimeTexture.loadFromFile("./assets/slime.png")) {
        printf("There was an error loading slime texture!");
    }

    sf::Sprite slimeSprite;
    slimeSprite.setTexture(slimeTexture);

    // Delta Time
    sf::Clock clock;
    float deltaTime;

    

    while (window.isOpen())
    {
        sf::Time time = clock.restart();
        deltaTime = time.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Key Press Detection
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            if (abs(pyv) < 6) pyv -= acceleration * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            if (abs(pyv) < 6) pyv += acceleration * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            if (abs(pxv) < 6) pxv -= acceleration * deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if (abs(pxv) < 6) pxv += acceleration * deltaTime;

        pxv *= 0.75;
        pyv *= 0.75;

        window.clear(sf::Color::Black);

        slimeSprite.move(pxv, pyv);
        window.draw(slimeSprite);
        window.display();
    }

    return 0;
}