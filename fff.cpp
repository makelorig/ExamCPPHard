#include <iostream>
#define random(min,max) min+rand()%(max-min+1)
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

//void StickMove(RectangleShape Stick,int GoPosY) {
//    GoPosY += 30;
//    Stick.setPosition(10, GoPosY);
//}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    RenderWindow window(VideoMode(1000, 800), "ThePongVideoGame");
    window.setFramerateLimit(30);
    RectangleShape leftStick(Vector2f(20, 180));
    RectangleShape rightStick(Vector2f(20, 180));
    RectangleShape ball(Vector2f(25, 25));


    int ballGoPosY = 400;
    int ballGoPosX = 600;
    const int BALLSPEED = 20;
    int DirectX = 1;
    int DirectY = 1;


    const int DOWNBORDER = 600;
    const int UPBORDER = 30;
    int leftGoPosY = 150;
    int rightGoPosY = 150;
    const int LPX = 50;
    const int RPX = 925;
    const int RAPIDSPEED = 45;



    window.clear();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (ballGoPosY < 0)DirectY = 0;
        if (ballGoPosY > (800 - 25))DirectY = 1;
        if (ballGoPosX < (LPX+50) && ballGoPosY>leftGoPosY && ballGoPosY < (leftGoPosY+150))DirectX = 1;
        if (ballGoPosX > (RPX-50) && ballGoPosY > rightGoPosY && ballGoPosY < (rightGoPosY + 150))DirectX = 0;

        ((DirectX == 1) ? ballGoPosX += BALLSPEED : ballGoPosX -= BALLSPEED);
        ((DirectY == 1) ? ballGoPosY -= BALLSPEED : ballGoPosY += BALLSPEED);

        

        
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            if (leftGoPosY > UPBORDER) leftGoPosY -= RAPIDSPEED;
        }
        if (Keyboard::isKeyPressed(Keyboard::S) ){
            if (leftGoPosY < DOWNBORDER) leftGoPosY += RAPIDSPEED;
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            if (rightGoPosY > UPBORDER) rightGoPosY -= RAPIDSPEED;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            if (rightGoPosY < DOWNBORDER) rightGoPosY += RAPIDSPEED;
        }

        
        

        leftStick.setPosition(LPX, leftGoPosY);
        rightStick.setPosition(RPX, rightGoPosY);
        ball.setPosition(ballGoPosX, ballGoPosY);
        window.clear();
        window.draw(ball);
        window.draw(leftStick);
        window.draw(rightStick);
        window.display();
    }
    

    return 0;
}
 
