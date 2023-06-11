#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

void title()
{

}

int main()
{
    VideoMode resolution(600,600);
    std::string windowTitle("Cong++");
    
    RenderWindow window(resolution, windowTitle);

    //paddle values
    Vector2f initPos(40,250);
    RectangleShape paddle(Vector2f(10,100));
    paddle.setPosition(initPos);
    Vector2f paddlePos = paddle.getPosition();
    sf::FloatRect paddleBounds = paddle.getGlobalBounds();
    float paddleVel = 0.08;

    //ball values
    RectangleShape ball(Vector2f(10,10));
    ball.setPosition(300,300);
    Vector2f ballPos = ball.getPosition();
    Vector2f velocity(0.03,0.03);
    sf::FloatRect ballBounds = ball.getGlobalBounds();

    while(window.isOpen())
    {
        Event event;

        //window event handling
        while(window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }

        //control handling
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            paddlePos.y -= paddleVel;
            paddle.setPosition(paddlePos);
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            paddlePos.y += paddleVel;
            paddle.setPosition(paddlePos);
        }

        ballPos -= velocity;
        ball.setPosition(ballPos);
        if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
        {
            velocity.x *= -1;
            velocity.y *= -1;
            ball.setPosition(ballPos);
        }

        
        window.clear();
        window.draw(paddle);
        window.draw(ball);
        window.display();
    }
}