#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(static_cast<unsigned>(time(0))); // для случайного цвета

    float speed = 10000.0f; // общая скорость объектов
    sf::Color bgColor = sf::Color(rand() % 256, rand() % 256, rand() % 256);

    // создание круга
    float radius_circle = 50.0f; // радиус окружности
    sf::CircleShape circle(radius_circle);
    circle.setFillColor(sf::Color::Red);
    float circle_x = 250.0f; // начальный х
    float circle_y = 100.0f; // начальный у
    float speed_circle_x = speed; // скорость по x
    float speed_circle_y = speed; // скорость по y
    circle.setOrigin(radius_circle, radius_circle);
    circle.setPosition(circle_x, circle_y);

    // создание квадрата
    float side = 30.0f; // длина сторон квадрата
    sf::RectangleShape rectangle({side, side});
    rectangle.setFillColor(sf::Color::Magenta);
    float rectangle_x = 100.0f; // начальный х
    float rectangle_y = 250.0f; // начальный у
    float speed_rectangle_x = speed;
    float speed_rectangle_y = speed;
    rectangle.setOrigin(side / 2.0f, side / 2.0f);
    rectangle.setPosition(rectangle_x, rectangle_y);

    // создание треугольника
    float radius_triangle = 25.0f; // радиус треугольника
    sf::CircleShape triangle(radius_triangle, 3);
    triangle.setFillColor(sf::Color::Green);
    float triangle_x = 100.0f; // начальный х
    float triangle_y = 250.0f; // начальный у
    float speed_triangle_x = speed;
    float speed_triangle_y = speed;
    triangle.setOrigin(radius_triangle, radius_triangle);
    triangle.setPosition(triangle_x, triangle_y);

    sf::RenderWindow window(sf::VideoMode(600, 600), "перемещение на высокой скорости");

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        float remainingTime = deltaTime;

        while (remainingTime > 0)
        {
            float timeStep = 0.001f; // временной шаг для перемещения
            if (remainingTime < timeStep)
                timeStep = remainingTime;
            remainingTime -= timeStep;

            // обновление позиции круга
            circle_x += speed_circle_x * timeStep;
            circle_y += speed_circle_y * timeStep;
            if (circle_x - radius_circle < 0)
            {
                circle_x = radius_circle;
                speed_circle_x = -speed_circle_x;
                circle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (circle_x + radius_circle > 600)
            {
                circle_x = 600 - radius_circle;
                speed_circle_x = -speed_circle_x;
                circle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (circle_y - radius_circle < 0)
            {
                circle_y = radius_circle;
                speed_circle_y = -speed_circle_y;
                circle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (circle_y + radius_circle > 600)
            {
                circle_y = 600 - radius_circle;
                speed_circle_y = -speed_circle_y;
                circle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            circle.setPosition(circle_x, circle_y);

            // обновление позиции квадрата
            rectangle_x += speed_rectangle_x * timeStep;
            rectangle_y += speed_rectangle_y * timeStep;
            if (rectangle_x - side / 2 < 0)
            {
                rectangle_x = side / 2;
                speed_rectangle_x = -speed_rectangle_x;
                rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (rectangle_x + side / 2 > 600)
            {
                rectangle_x = 600 - side / 2;
                speed_rectangle_x = -speed_rectangle_x;
                rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (rectangle_y - side / 2 < 0)
            {
                rectangle_y = side / 2;
                speed_rectangle_y = -speed_rectangle_y;
                rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (rectangle_y + side / 2 > 600)
            {
                rectangle_y = 600 - side / 2;
                speed_rectangle_y = -speed_rectangle_y;
                rectangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            rectangle.setPosition(rectangle_x, rectangle_y);

            // обновление позиции треугольника
            triangle_x += speed_triangle_x * timeStep;
            triangle_y += speed_triangle_y * timeStep;
            if (triangle_x - radius_triangle < 0)
            {
                triangle_x = radius_triangle;
                speed_triangle_x = -speed_triangle_x;
                triangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (triangle_x + radius_triangle > 600)
            {
                triangle_x = 600 - radius_triangle;
                speed_triangle_x = -speed_triangle_x;
                triangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (triangle_y - radius_triangle < 0)
            {
                triangle_y = radius_triangle;
                speed_triangle_y = -speed_triangle_y;
                triangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            if (triangle_y + radius_triangle > 600)
            {
                triangle_y = 600 - radius_triangle;
                speed_triangle_y = -speed_triangle_y;
                triangle.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            }
            triangle.setPosition(triangle_x, triangle_y);
        }

        window.clear(bgColor);

        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        window.display();
    }

    return 0;
}
