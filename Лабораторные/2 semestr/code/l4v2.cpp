#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <time.h>
#include <chrono>

class MyText{
    std::string _str = "Test";
    int ShowTime = 500; //мсек
public:
    MyText(){}
    MyText(std::string str){ _str = str;}
    MyText(int time){ ShowTime = time;}
    MyText(std::string str,int time){ _str=str; ShowTime = time;}
    ~MyText(){}

    void verbAnimationText(){
        srand(time(NULL));
        std::string str_show = "";
        std::string znaki(".,:?-();!\"' ");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("123.ogg");
        sound.setBuffer(buffer);
        sound.setVolume(50);

        sf::Text text;
        sf::Font font;
        font.loadFromFile("E:/Steam/steamapps/common/SpaceEngineers/Tools/Fonts/space_engineers.ttf");
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
                j++;
            }
            
            //std::cout<<j<<" "<<i<<std::endl;
            text.setString(str_show);
            window.clear(sf::Color::Color(a,b,c,d));
            window.draw(text);
            window.display();
        }
    }
    
    void verbAnimationText(float time1){
        srand(time(NULL));
        std::string str_show = "";
        std::string znaki(".,:?-();!\"' ");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("123.ogg");
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
                j++;
            }
            
            //std::cout<<j<<" "<<i<<std::endl;
            text.setString(str_show);
            window.clear(sf::Color::Color(a,b,c,d));
            window.draw(text);
            window.display();
        }
    }

    void verbAnimationText(float time1, std::string text_f){
        srand(time(NULL));
        auto start = std::chrono::system_clock::now();

        std::string str_show = "";
        _str=text_f;
        std::string znaki(".,:?-();!\"' ");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("звук.ogg");
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
            
            //std::cout<<j<<" "<<i<<std::endl;
            text.setString(str_show);
            window.clear(sf::Color::Color(a,b,c,d));
            window.draw(text);
            window.display();
        }
    }
    void verbAnimationText(std::string text_f){
        srand(time(NULL));
        std::string str_show = "";
        _str=text_f;
        std::string znaki(".,:?-();!\"' ");

        sf::SoundBuffer buffer;
        sf::Sound sound;
        buffer.loadFromFile("123.ogg");
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
                j++;
            }
            
            //std::cout<<j<<" "<<i<<std::endl;
            text.setString(str_show);
            window.clear(sf::Color::Color(a,b,c,d));
            window.draw(text);
            window.display();
        }
    }
};


int main(int, char**){
    
    std::string path_to_font = "путь до шрифта";
    std::string str = "asdfghjkl";
    float ShowTime = 6; //75 = 1сек

    ShowTime = ShowTime * 53;
    sf::Font font;
    font.loadFromFile(path_to_font);

    MyText text;


    text.verbAnimationText(ShowTime, "test! ,23456");
}
