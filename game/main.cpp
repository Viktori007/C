#include <SFML/Graphics.hpp>//подключение заголовочного файла
//#include "gamegovna.h"
//#include "gamegovna2.h"
using namespace sf;

int g=0 /*счетчик*/, vx[100], vy[100], randvrag[100]/*рандом картинок*/, konec=2;
int timenewvr=0, ground=1, timerjump=0, speed=20,fx=0,fy=0,State1=0; //это таймер создания новых врагов
Clock clock2; //время нужно для счета расстояния пройденного котом
Image figimage, vragimage;
    Texture figtexture,vragtexture;
    Sprite figsprite,vragsprite[101];
 float  chetanim=1,PosTek = 5;//хранит текущий кадр

void kotanim(){
 if (int(chetanim)==5) figsprite.setTextureRect(IntRect(0,0,111,110)); //анимация кота
     if (int(chetanim)==4) figsprite.setTextureRect(IntRect(111,0,111,110));
     if (int(chetanim)==3) figsprite.setTextureRect(IntRect(222,0,111,110));
     if (int(chetanim)==2) figsprite.setTextureRect(IntRect(331,0,111,110));
     if (int(chetanim)==1) figsprite.setTextureRect(IntRect(444,0,111,110));
     if (int(chetanim)>=5) chetanim=1;
     chetanim+=0.8;
}

void kotstate(){
        if (State1==4 && fx>5 && fx<=720) { //влево
			figsprite.move(-speed, 0);//происходит само движение персонажа влево
			State1=0;
		}

		else if (State1==5 && fx>=5 && fx<720 ) { //вправо
			figsprite.move(speed, 0);
            State1=0;

		}

		else if (State1==1 && fx>=5 && fx<=720) { //прыжок
            if (ground) figsprite.move(0, - speed);//происходит само движение персонажа вверх
			else figsprite.move(0, speed);

			if (timerjump>3) ground=0;
            timerjump++;
            if (timerjump>9) { timerjump=0; ground=1;State1=0;}
		}

		else if (State1==2 && fx>5 && fx<=720) { //прыжок влево
           if (ground) figsprite.move(-speed, - speed);//происходит само движение персонажа вверх
			else figsprite.move(-speed, speed);

			if (timerjump>3) ground=0;
            timerjump++;
            if (timerjump>9) { timerjump=0; ground=1;State1=0;}
		}

		else if (State1==3 && fx>=5 && fx<720) {  //прыжок враво
            if (ground) figsprite.move(speed, - speed);//происходит само движение персонажа вверх
			else figsprite.move(speed, speed);

			if (timerjump>3) ground=0;
            timerjump++;
            if (timerjump>9) { timerjump=0; ground=1;State1=0;}

		}
		else {
                State1=0;
                fx = figsprite.getPosition().x;
                fy = figsprite.getPosition().y;
                if (!fy==248) figsprite.move(0,15);
                if (fy>248 && fy<223) figsprite.setPosition(fx,248);

		}

		fx = figsprite.getPosition().x;
        fy = figsprite.getPosition().y;

        if (fy>248 && State1==0) figsprite.setPosition(fx,248);

		 if (fx<5) figsprite.setPosition(5,248);
         if (fx>720) figsprite.setPosition(720,248);

    }


void nol(){
    clock2.restart();
    if(Keyboard::isKeyPressed(Keyboard::Space)) konec=0;
    g=0;
    timenewvr=0;
    timerjump=0;
    ground=1;
    State1=0;
    figsprite.setPosition(50, 248);

    fx=figsprite.getPosition().x;
    fy=figsprite.getPosition().y;
    for (int i=0;i<100;i++) {
            vragsprite[i].setPosition(1000,310);
            randvrag[i]=0;
            vx[i]=vragsprite[i].getPosition().x;
            vragsprite[i].setTextureRect(IntRect(0,0,0,0));
            }
}

void proverkaanala(){
    for (int i=0; i<100;i++){
        vx[i]=vragsprite[i].getPosition().x;//получаем позицию каждого врага
        for (int j=0;j<60;j++){//создаем область размеро 60 пикселей в коте для проверки сталкновения
          if(randvrag[i]==1 && (fx+20+j==vx[i]+20) && fy>200) konec=1;
          if(randvrag[i]==2 && (fx+20+j==vx[i]+30) && fy>200) konec=1;
          if(randvrag[i]==3 && ( fx+20+j==vx[i]+17) && fy>200) konec=1;
        }//прописываем состояние игры проигрыш=1
}
}

int statekot(int State1){ //возвращает состояние кота по нажатию кнопок
    if (State1==0){
       if (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A))) State1=4;//влево
        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) State1=5;//вправо

        if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space)) State1=1; //прыжок                                                                                   //просто прыжок
            if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space))
                &&(Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) State1=2; //прыжок влево
            if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space)) &&
                ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D))))) State1=3; //прыжок враво
        }
        return State1;
}

void voidgovno(int State1){
        if (State1==4 || State1==2) { //влево анимация
			PosTek -= 0.005*160;
			if (PosTek < 0) PosTek += 5;//читаем в обратном порядке
			if (int(PosTek)==3) figsprite.setTextureRect(IntRect(111 * int(PosTek)-2+111, 0, -111, 110));//обрезает коту ногу
			else figsprite.setTextureRect(IntRect(111 * int(PosTek)+111, 0, -111, 110));//читаем картинку справа налево
        }
        else{ //вправо анимация
            PosTek -= 0.005*160;
			if (PosTek < 0) PosTek += 5;
			if (int(PosTek)==3) figsprite.setTextureRect(IntRect(111 * int(PosTek)-2, 0, 111, 110));
			else figsprite.setTextureRect(IntRect(111 * int(PosTek), 0, 111, 110));
        }
    }

void  vragcos(int ti){ //функция создает элементы массива спрайтов из 3  фигурок
    if (timenewvr==0 && ti<2600){
    vragimage.loadFromFile("image/kak.png");
    vragtexture.loadFromImage(vragimage);
    vragsprite[g].setTexture(vragtexture);
    //делаем спрайт чтобы поперенно их выпускать
    randvrag[g]=rand()%3 +1;

        if (randvrag[g]==1) vragsprite[g].setTextureRect(IntRect(0,0,39,50));//рандомно выпускаем врагов для первого
        else if (randvrag[g]==2) vragsprite[g].setTextureRect(IntRect(39,0,58,50));
        else vragsprite[g].setTextureRect(IntRect(97,0,33,50));

        vragsprite[g].setPosition(900,310);
        g++;
        if (g>103) g=0;
    }
        timenewvr--;
        if (timenewvr<0) timenewvr=rand()%18 +10; //перезапускаем таймер появления врагов размером от 10 до 18 циклов


        for (int i=0; i<=g;i++){//передвигаем массив врагов до создавшегося
    vragsprite[i].move(-speed-6.5,0);//двигаем справа налево
    }
}



int main()
{
    RenderWindow win(VideoMode(840, 580), "<->Bolt<->");//пространство имен создает окно
//сначала импортируем картинку из файла, затем в текстуру и в спрайт
     figimage.loadFromFile("image/kot2_negate.png");
    vragimage.loadFromFile("image/kak.png");
    vragtexture.loadFromImage(vragimage);
    figtexture.loadFromImage(figimage);
    figsprite.setTexture(figtexture);
    figsprite.setTextureRect(IntRect(0,0,111,110));//первый кадр
    figsprite.setPosition(50, 248);//начальная позиция

    Sprite tortsprite;
    tortsprite.setTexture(vragtexture);
    tortsprite.setTextureRect(IntRect(130,0,50,50));
    tortsprite.setPosition(920,310);

    Font font;//шрифт
	font.loadFromFile("image/CyrillicOld.ttf");
    Text text("", font, 20);
	text.setColor(Color::White);
	text.setStyle(Text::Bold);//стиль текста

    RectangleShape line(Vector2f(840, 1));//граница
    line.setPosition(0,360);//полоса

    vx[0]=1000; vy[0]=310; //объявляем положение первого врага


    while (win.isOpen() && Keyboard::isKeyPressed(Keyboard::Escape)<=0 )//пока открыто окно
    {
        int ti= clock2.getElapsedTime().asSeconds();
        ti*=25;

        Event event; //событие
        while (win.pollEvent(event))
        {
            if (event.type == Event::Closed)//закрыть если закрыли
                win.close();

        }
               kotanim();
            State1=statekot(State1);
            voidgovno(State1);
            kotstate();
         vragcos(ti); //создаем врага
        proverkaanala();

        Time tim=milliseconds(120);
        if(ti>300) tim-= milliseconds(ti/30); //уменьшаем таймер следовательно ускоряем игру
        sleep(tim);//делаем залипание с помощью этого таймера
        if (ti>2700) konec=3;//прописываем выигрыш

        win.clear();//очищает и затем рисует и показывает
        if (!konec){//если ничего нового не произошло то просто рисуем объекты и продолжаем играть

        win.draw(figsprite);
        win.draw(line);

        text.setPosition(0,10);//задаем позицию текста
        text.setCharacterSize(20);//размер текста
        text.setString("Kot Vasiliy");
        text.setPosition(0,10);//задаем позицию текста
        win.draw(text);//рисую этот текст

        //увелициваем размер и показываем другой текст
        text.setCharacterSize(24);
        text.setString(std::to_string(ti) + " sm");//расстояние пройденное котом в см
         text.setPosition(5,40);//задаем позицию текста
        win.draw(text);//рисую этот текст

        for (int i=0;i<100;i++)
         win.draw(vragsprite[i]);//рисуем весь массив врагов
        }

        else if (konec==3){// состояние игры победа=3
            text.setString("\t\t\t  You Win!");
            text.setCharacterSize(30);
            text.setPosition(200,100);

            if (tortsprite.getPosition().x > figsprite.getPosition().x+130) tortsprite.move(-20,0);//передвигаем торт до кота
            win.draw(text);
            win.draw(figsprite);
            win.draw(line);
            win.draw(tortsprite);
        }
        else { //состояние игры проигрыш=1 или первый запуск=2
        //основная задача все обнулить и ничего не выводить кроме текста
            if (konec==1){
            text.setString("\t\t\t  Game over\n To start first click space");
            }
            else text.setString("\t\t\tHi!\n To start first click space");
            text.setCharacterSize(40);
            text.setPosition(200,180);
            win.draw(text);
            nol();
            }

        win.display();
    }
    return 0;
}
