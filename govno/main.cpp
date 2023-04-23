#include <SFML/Graphics.hpp>//подключение заголовочного файла

using namespace sf;


int main()
{
    RenderWindow win(VideoMode(840, 580), "<->Bolt<->",Style::Close);//пространство имен создает окно
    Image heroimage, obimage;
    heroimage.loadFromFile("kot2_negate.png");
    obimage.loadFromFile("oblak.png");

    Texture herotexture;
    herotexture.loadFromImage(heroimage);

    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setTextureRect(IntRect(0,0,112,120));
    herosprite.setPosition(50, 250);


    RectangleShape line(Vector2f(840, 1));
    line.setPosition(0,370);

    Clock clock1;
    Time t=milliseconds(180), t2=milliseconds(90);
    float heroteleport = 0;
    int r=1, r1=0, pr=150, tr=0;


    while (win.isOpen())//пока открыто окно
    {
        float time= clock1.getElapsedTime().asMicroseconds();

        clock1.restart();
        time/=800;
        Event event; //событие
        while (win.pollEvent(event))
        {
            if (event.type == Event::Closed)//закрыть если закрыли
                win.close();

        }

             if (r==5) herosprite.setTextureRect(IntRect(0,0,112,120));
             if (r==4) herosprite.setTextureRect(IntRect(112,0,112,120));
             if (r==3) herosprite.setTextureRect(IntRect(226,0,112,120));
             if (r==2) herosprite.setTextureRect(IntRect(332,0,112,120));
             if (r==1) herosprite.setTextureRect(IntRect(442,0,112,120));
             if (r>=5) r=1;
             r++;

        if (Keyboard::isKeyPressed(Keyboard::Left)) {herosprite.move(-0.1*time,0); herosprite.setTextureRect(IntRect(332,0,112,120));}
        if (Keyboard::isKeyPressed(Keyboard::Right)) {herosprite.move(0.1*time,0); herosprite.setTextureRect(IntRect(112,0,112,120));}
        if (Keyboard::isKeyPressed(Keyboard::Down)) {herosprite.move(0,0.1*time); herosprite.setTextureRect(IntRect(442,0,112,120));}
        if (Keyboard::isKeyPressed(Keyboard::Up)) {herosprite.move(0,-0.1*time); herosprite.setTextureRect(IntRect(226,0,112,120));}

        sleep(t);

        win.clear();//очищает и затем рисует и показывает
        win.draw(herosprite);
        win.draw(line);
       // win.draw(toch);
        win.display();
    }



    return 0;
}
