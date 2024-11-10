#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <time.h>
#include <chrono>

class MyText{
    std::string _str = "Test";
    int ShowTime = 500;
public:
//----конструкторы
    MyText(){}
    MyText(std::string str){ _str = str;}
    MyText(int time){ ShowTime = time;}
    MyText(std::string str,int time){ _str=str; ShowTime = time;}
    ~MyText(){}
//----функция(-и?)
    void verbAnimationText(){
        srand(time(NULL));
        auto start = std::chrono::system_clock::now();

        std::string str_show = "";
        std::string znaki("qwertyuiopasdfghjklzxcvbnm1234567890");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("путь до звука");
        sound.setBuffer(buffer);
        sound.setVolume(50);

        sf::Text text;
        sf::Font font;
        font.loadFromFile("путь до шрифта");
        text.setFont(font);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Red);
        text.setCharacterSize(30);

        sf::RenderWindow window(sf::VideoMode(800,800), "l4v2");
        window.setFramerateLimit(60);

        sf::Color color(sf::Color::Black);

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int j = 0;
        int i = 0;
        int count = ShowTime/_str.length();

       while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            if(j < _str.length())
            {    
                if(i == count){
                    str_show += _str[j];
                    if(znaki.find(_str[j]) == std::string::npos){
                        a = rand()%255;
                        b = rand()%255;
                        c = rand()%255;
                        d = rand()%255;
                    }
                    j++;
                    i = 0;
                }
                i++;
            } else if(j == _str.length()) {
                sound.play();
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                std::cout<<elapsed_seconds.count()<<std::endl;
                j++;
            }
            
            text.setString(str_show);
            text.setColor(sf::Color::Color(a,b,c,d));

            window.clear();
            window.draw(text);
            window.display();
        }
    }
//--если в аргументах время
    void verbAnimationText(float time1){
        srand(time(NULL));
        auto start = std::chrono::system_clock::now();

        std::string str_show = "";
        std::string znaki("qwertyuiopasdfghjklzxcvbnm1234567890");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("путь до звука");
        sound.setBuffer(buffer);
        sound.setVolume(50);

        sf::Text text;
        sf::Font font;
        font.loadFromFile("путь до шрифта");
        text.setFont(font);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Red);
        text.setCharacterSize(30);

        sf::RenderWindow window(sf::VideoMode(800,800), "uwu");
        window.setFramerateLimit(60);

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int j = 0;
        int i = 0;
        int count = time1/_str.length();

       while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            if(j < _str.length())
            {    
                if(i == count){
                    str_show += _str[j];
                    if(znaki.find(_str[j]) == std::string::npos){
                        a = rand()%255;
                        b = rand()%255;
                        c = rand()%255;
                        d = rand()%255;
                    }
                    j++;
                    i = 0;
                }
                i++;
            } else if(j == _str.length()) {
                sound.play();
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                std::cout<<elapsed_seconds.count()<<std::endl;
                j++;
            }
            
            text.setString(str_show);
            text.setColor(sf::Color::Color(a,b,c,d));

            window.clear();
            window.draw(text);
            window.display();
        }
    }
//--если в аргументах время и строка
    void verbAnimationText(float time1, std::string text_f){
        srand(time(NULL));
        auto start = std::chrono::system_clock::now();

        std::string str_show = "";
        _str=text_f;
        std::string znaki("qwertyuiopasdfghjklzxcvbnm1234567890");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("путь до звука");
        sound.setBuffer(buffer);
        sound.setVolume(50);

        sf::Text text;
        sf::Font font;
        font.loadFromFile("путь до шрифта");
        text.setFont(font);
        text.setFillColor(sf::Color::White);
        text.setCharacterSize(30);

        sf::RenderWindow window(sf::VideoMode(800,800), "uwu");
        window.setFramerateLimit(60);

        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int j = 0;
        int i = 0;
        int count = time1/_str.length();

        sf::Color color(sf::Color::Red);

       while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            if(j < _str.length())
            {    
                if(i == count){
                    str_show += _str[j];
                    if(znaki.find(_str[j]) != std::string::npos){
                        a = rand()%255;
                        b = rand()%255;
                        c = rand()%255;
                        d = rand()%255;
                    }
                    j++;
                    i = 0;
                }
                i++;
            } else if(j == _str.length()) {
                sound.play();
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                std::cout<<elapsed_seconds.count()<<std::endl;
                j++;
            }
            
            text.setString(str_show);
            text.setColor(sf::Color::Color(a,b,c,d));

            window.clear();
            window.draw(text);
            window.display();
        }
    }
//--если в аргументах только строка
    void verbAnimationText(std::string text_f){
        srand(time(NULL));

        auto start = std::chrono::system_clock::now(); //начало отсчета вермени работы
        //строки
        std::string str_show = ""; //строка символов, что находятся на экране
        _str=text_f; //передаем полученный текст в класс
        std::string znaki("qwertyuiopasdfghjklzxcvbnm1234567890"); //строка изменяющих цвет символов
//-----подключение звука
        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("123.ogg");
        sound.setBuffer(buffer);
        sound.setVolume(50);
//-----подключение текста
        sf::Text text;
        sf::Font font;
        //подключаем шрифт
        font.loadFromFile("путь до шрифта");
        text.setFont(font);
        text.setColor(sf::Color::White);
        text.setCharacterSize(30);
//-----подключение окна
        sf::RenderWindow window(sf::VideoMode(800,800), "uwu");
        window.setFramerateLimit(60);

//------значения случайного цвета
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
//------
        int j = 0; //номер символа в строке
        int i = 0; //номер тика
//------ПОДСЧЕТ ТИКОВ
        //тик - единица времени, которое находим нижней формулой
        //тиками часто пользуются в играх, в майне и в ксго точно
        int count = ShowTime/_str.length(); 

       while(window.isOpen()){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed)
                    window.close();
            }
            //если не дошли до конца строки
            if(j < _str.length())
            {   
                //если дошли до последнего тика в секунде
                if(i == count){
                    //к строке показа добавляем символ
                    str_show += _str[j];
                    //проверяем наличие символа в строке меняющих цвет
                    if(znaki.find(_str[j]) != std::string::npos){
                        //-получаем знач цвета-
                        a = rand()%255;
                        b = rand()%255;
                        c = rand()%255;
                        d = rand()%255;
                        //---------------------
                    }

                    j++; //переходим на след символ
                    i = 0; //обнуляем тики
                }
                i++; //увеличиваем тик
            // если дошли до конца строки
            } else if(j == _str.length()) {
                //конец подсчета времени
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> elapsed_seconds = end-start;
                //вывод времени работы
                std::cout<<elapsed_seconds.count()<<std::endl;
                //увеличиваем номер символа для прекращения работы условия
                j++;
            }
            
            text.setString(str_show); //вывод строки вывода
            text.setColor(sf::Color::Color(a,b,c,d)); //меняем цвет

            window.clear(sf::Color::White);
            window.draw(text);
            window.display();
        }
    }
};


int main(int, char**){
    float ShowTime = 4; //75 = 1сек

    ShowTime = ShowTime * 53;
    sf::Font font;

    MyText text;


    text.verbAnimationText("33asFF-  !FFd123");
}
