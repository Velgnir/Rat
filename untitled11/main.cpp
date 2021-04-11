#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <unistd.h>

int randomnomber(int n){
    int z;
    z=rand() % 5;

    switch(z){
        case 1:
            if ((n==1) || (n==13)){
                return randomnomber(n);
            }
            break;
        case 3:
            if (n-6<0){
                return randomnomber(n);
            }
            break;
        case 4:
            if (n+6>18){
                return randomnomber(n);
            }
            break;
    }
    return z;
}
int poshuk(std::vector<int> pole, sf::Vector2f rat, int n, int cool){
    if((pole[n-1]>pole[n+1]) && (pole[n-1]>pole[n+6]) && (pole[n-1]>pole[n-6]) && (cool!=n-1) && (n>1)){
        n-=1;
    }
    else if((pole[n+1]>pole[n-1]) && (pole[n+1]>pole[n+6]) && (pole[n+1]>pole[n-6]) && (cool!=n+1)){
        n+=1;
    }
    else if((pole[n+6]>pole[n-1]) && (pole[n+6]>pole[n+1]) && (pole[n+6]>pole[n-6]) && (cool!=n+6) && (n<13)){
        n+=6;
    }
    else if((pole[n-6]>pole[n-1]) && (pole[n-6]>pole[n+6]) && (pole[n-6]>pole[n+1]) && (cool!=n-6) && (n>6)){
        n-=6;
    }
    if (n == cool){
        return poshuk(pole,  rat, n, cool);
    }
    return n;
}


int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 600), "Q Learning test");

    sf::Texture texture;
    texture.loadFromFile("Map.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 1200, 800));
    sprite.setColor(sf::Color(255, 255, 255, 200));
    sprite.setPosition(0, 0);

    sf::Vector2f rat;
    rat.x =0;
    rat.y = 0;
    sf::Texture texture2;
    texture2.loadFromFile("texture.png");
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite2.setColor(sf::Color(255, 255, 255, 200));
    sprite2.setPosition(rat);

    sf::Texture texture3;
    texture3.loadFromFile("trap.png");
    sf::Sprite sprite3;
    sprite3.setTexture(texture3);
    sprite3.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite3.setColor(sf::Color(255, 255, 255, 200));
    sprite3.setPosition(0, 200);

    sf::Texture texture4;
    texture4.loadFromFile("trap.png");
    sf::Sprite sprite4;
    sprite4.setTexture(texture4);
    sprite4.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite4.setColor(sf::Color(255, 255, 255, 200));
    sprite4.setPosition(1000, 0);

    sf::Texture texture5;

    texture5.loadFromFile("trap.png");
    sf::Sprite sprite5;
    sprite5.setTexture(texture5);
    sprite5.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite5.setColor(sf::Color(255, 255, 255, 200));
    sprite5.setPosition(1000, 200);

    sf::Texture texture6;

    texture6.loadFromFile("trap.png");
    sf::Sprite sprite6;
    sprite6.setTexture(texture6);
    sprite6.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite6.setColor(sf::Color(255, 255, 255, 200));
    sprite6.setPosition(200, 200);

    sf::Texture texture7;

    texture7.loadFromFile("trap.png");
    sf::Sprite sprite7;
    sprite7.setTexture(texture7);
    sprite7.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite7.setColor(sf::Color(255, 255, 255, 200));
    sprite7.setPosition(600, 400);

    sf::Texture texture8;

    texture8.loadFromFile("cheese.png");
    sf::Sprite sprite8;
    sprite8.setTexture(texture8);
    sprite8.setTextureRect(sf::IntRect(0, 0, 200, 200));
    sprite8.setColor(sf::Color(255, 255, 255, 200));
    sprite8.setPosition(1000, 400);




    int m;
    std::vector<int> pole = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::vector<int> npolja;
    int n=1;
    int cool=1;
    bool tr =true;
    for (int i =1; i<7000; ++i){
        npolja.clear();
        rat.x= 0;
        rat.y=0;
        sprite2.setPosition(rat);
        window.draw(sprite2);
        n =1;
        npolja.push_back(n);
        tr = true;
        while(tr!=false) {
            m = randomnomber(n);
            switch(m){
                case 1:
                    rat.x-=200;
                    n-=1;
                    npolja.push_back(n);

                    break;
                case 2:
                    rat.x+=200;
                    n+=1;
                    npolja.push_back(n);

                    break;
                case 3:
                    rat.y-=200;
                    n-=6;
                    npolja.push_back(n);
                    break;
                case 4:
                    rat.y+=200;
                    n+=6;
                    npolja.push_back(n);
                    break;
            }


            if (((rat.x==200) && (rat.y==200)) || ((rat.x==0) && (rat.y==200)) || ((rat.x==1000) && (rat.y==200)) || ((rat.x==1000) && (rat.y==0)) || ((rat.x==600) && (rat.y==400))){
                for (auto nomber: npolja){
                    pole[nomber]-=1;
                }
                tr=false;
                break;
            }
            if((rat.x==1000)&&(rat.y==400)){
                for (auto nomber: npolja){
                    pole[nomber]+=1;
                }
                tr=false;
                break;
            }
            sprite2.setPosition(rat);
            window.draw(sprite);
            window.draw(sprite2);
            window.draw(sprite3);
            window.draw(sprite4);
            window.draw(sprite5);
            window.draw(sprite6);
            window.draw(sprite7);
            window.draw(sprite8);

            window.display();
        }
    }


    n=1;
    rat.x=0;
    rat.y=0;

   while (window.isOpen()) {
       sf::Event event;
       if (event.type == sf::Event::Closed){
           window.close();
   }


        n=poshuk(pole, rat, n, cool);
        std::cout<<n<<std::endl;
        std::cout<<"cool:  "<<cool<< std::endl;
        if (n-cool==-1){
            rat.x-=200;
        }
        else if (n-cool==-1){
            rat.x+=200;
        }
        else if (n-cool==-6){
           rat.y-=200;
        }
        else if (n-cool==6){
            rat.x+=200;
        }
        cool =n;
        std::cout<<rat.x<<"  "<<rat.y<<std::endl;
        sprite2.setPosition(rat);
        window.draw(sprite);
       //window.draw(text);
       window.draw(sprite2);
       window.draw(sprite3);
       window.draw(sprite4);
       window.draw(sprite5);
       window.draw(sprite6);
       window.draw(sprite7);
       window.draw(sprite8);

       window.display();
        window.display();
        sleep(1);
    }
        return 0;

}
