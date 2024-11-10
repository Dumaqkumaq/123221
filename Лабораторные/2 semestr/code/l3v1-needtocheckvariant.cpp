#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <cstdlib>

// Функция для генерации случайного цвета
sf::Color getRandomColor() {
    return sf::Color(rand() % 256, rand() % 256, rand() % 256);
}

int main() {
    // Инициализация случайного генератора
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Shapes");

    // Создание фигур
    sf::CircleShape circle(50);
    circle.setFillColor(getRandomColor());
    circle.setPosition(100, 100);

    sf::RectangleShape rectangle(sf::Vector2f(120, 60));
    rectangle.setFillColor(getRandomColor());
    rectangle.setPosition(300, 200);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(100, 0));
    triangle.setPoint(2, sf::Vector2f(50, 100));
    triangle.setFillColor(getRandomColor());
    triangle.setPosition(500, 400);

    // Задание скоростей для каждой фигуры
    sf::Vector2f circleSpeed(0.5f, 0.5f);
    sf::Vector2f rectangleSpeed(0.7f, 0.7f);
    sf::Vector2f triangleSpeed(0.9f, 0.9f);

    // Начальная задержка
    sf::sleep(sf::seconds(2));

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Обновление позиции фигур
        sf::Vector2f circlePos = circle.getPosition();
        sf::Vector2f rectanglePos = rectangle.getPosition();
        sf::Vector2f trianglePos = triangle.getPosition();

        // Перемещение круг
        circle.move(circleSpeed);
        if (circlePos.x <= 0 || circlePos.x + circle.getRadius() * 2 >= window.getSize().x) {
            circleSpeed.x = -circleSpeed.x;
            circle.setFillColor(getRandomColor());
        }
        if (circlePos.y <= 0 || circlePos.y + circle.getRadius() * 2 >= window.getSize().y) {
            circleSpeed.y = -circleSpeed.y;
            circle.setFillColor(getRandomColor());
        }

        // Перемещение прямоугольник
        rectangle.move(rectangleSpeed);
        if (rectanglePos.x <= 0 || rectanglePos.x + rectangle.getSize().x >= window.getSize().x) {
            rectangleSpeed.x = -rectangleSpeed.x;
            rectangle.setFillColor(getRandomColor());
        }
        if (rectanglePos.y <= 0 || rectanglePos.y + rectangle.getSize().y >= window.getSize().y) {
            rectangleSpeed.y = -rectangleSpeed.y;
            rectangle.setFillColor(getRandomColor());
        }

        // Перемещение треугольник
        triangle.move(triangleSpeed);
        if (trianglePos.x <= 0 || trianglePos.x + 100 >= window.getSize().x) {
            triangleSpeed.x = -triangleSpeed.x;
            triangle.setFillColor(getRandomColor());
        }
        if (trianglePos.y <= 0 || trianglePos.y + 100 >= window.getSize().y) {
            triangleSpeed.y = -triangleSpeed.y;
            triangle.setFillColor(getRandomColor());
        }

        window.clear(getRandomColor());
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        window.display();

        // Добавление мигания цвета фигур
        if (clock.getElapsedTime().asSeconds() > 1) {
            circle.setFillColor(getRandomColor());
            rectangle.setFillColor(getRandomColor());
            triangle.setFillColor(getRandomColor());
            clock.restart();
        }
    }

    return 0;
}
