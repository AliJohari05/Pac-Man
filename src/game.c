#include "../include/game.h"
#include "raylib.h"
#include "stdlib.h"
#include "../include/gameOver.h"
#include "stdio.h"
#include <time.h>
#include <math.h>
Texture2D packManNarrowTexture;
Texture2D packManClosedTexture;
Texture2D packManUpTexture;
Texture2D pacKManDownTexture;
Texture2D packManLeftTexture;
Texture2D cherryTexture;
Texture2D appleTexture;
Texture2D pepperTexture;
Texture2D mushroomTexture;

Texture2D starTexture;
Texture2D star2Texture;
Texture2D blinkyL2Texture;
Texture2D blinkyD2Texture;
Texture2D blinkyU2Texture;
Texture2D blinkyR2Texture;
Texture2D hearTexture;
Texture2D clydeU2Texture;
Texture2D clydeL2Texture;
Texture2D clydeR2Texture;
Texture2D clydeD2Texture;
Texture2D inkyD2Texture;
Texture2D inkyR2Texture;
Texture2D inkyU2Texture;
Texture2D inkyL2Texture;
Texture2D pinkyD2Texture;
Texture2D pinkyR2Texture;
Texture2D pinkyU2Texture;
Texture2D pinkyL2Texture;
Texture2D ginkyD2Texture;
Texture2D ginkyR2Texture;
Texture2D ginkyU2Texture;
Texture2D ginkyL2Texture;
Texture2D blue1Texture;
Texture2D whiteTexchure;
Texture2D fireTexture;
Vector2 blinkyPosition = {1200 , 970};
Vector2 blinkyPosition2 = {400,1300};
Vector2 clydePosition = {1200,870};
Vector2 clydePosition2 = {1200,1500};
Vector2 inkyPosition = {200 , 600};
Vector2 inkyPosition2 = {1990,700};
Vector2 pinkyPosition = {485,200};
Vector2 ginkyPosition = {1400 , 600};
Vector2 pinkyPosition2 = {1400,100};
Vector2 ginkyPosition2 = {500,900};
Vector2 packManPosition = { 100, 100 };
int timeEat = 0 ;
int timeEatPepper = 0 ;
int counter = 0;
int score = 0 ;
int flagForScore = 0 ;
int life = 3 ;
extern int degree;

int map[20][35] = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 2, 2, 2, 0, 1, 1, 1, 0, 0, 1},
        {0, 0, 1, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 99, 99, 99, 2, 0, 1, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 2, 99, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 2, 2, 0, 1, 2, 0, 2, 2, 2, 2, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 0, 0, 2, 99, 99, 99, 2, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 2, 0, 2, 2, 0, 0, 0, 1, 0, 1, 0, 0, 1},
        {0, 0, 0, 2, 0, 2, 99, 2, 0, 2, 0, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 1, 2, 0, 2, 0, 2, 0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0},
        {0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 2, 0, 1, 1, 1, 0, 2, 0, 1, 2, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 1, 0, 0, 0, 2, 99, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 2, 0, 1, 1, 1, 2, 0, 0, 1, 0, 0, 0, 2, 99, 99, 99, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 2, 0, 1, 1, 2, 0, 0, 1, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 1, 0, 1, 1, 0, 0},
        {0, 2, 0, 1, 2, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 99, 99, 2, 0, 1, 0, 0, 0, 0, 0},
        {0, 2, 2, 2, 2, 0, 0, 1, 0, 0, 2, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 0, 2, 0, 2, 2, 2, 2, 0, 1, 1, 1, 1, 1, 0},
        {0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 99, 99, 2, 0, 0, 0, 0, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 2, 0, 0, 1, 1, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 1, 0, 1, 0, 1},
        {0, 2, 0, 1, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 2, 99, 99, 2, 0, 0, 0, 1, 2, 0, 2, 0, 0, 2, 0, 0, 1, 0, 1, 0, 1},
        {0, 2, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 2, 99, 99, 2, 0, 0, 0, 1, 2, 0, 2, 0, 0, 0, 2, 0, 1, 0, 0, 0, 1},
        {0, 2, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 2, 2, 2, 0, 0, 0, 0, 1, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
};

float speed = 0 ;

void InitGame(){
    Image packManNarrow = LoadImage("C:\\Users\\alite\\pack man project\\images\\pacNarrow2.png");
    packManNarrowTexture = LoadTextureFromImage(packManNarrow);
    Image packManClosed = LoadImage("C:\\Users\\alite\\pack man project\\images\\pacClosed.png");
    packManClosedTexture = LoadTextureFromImage(packManClosed);
    Image packManUp = LoadImage("C:\\Users\\alite\\pack man project\\images\\pacNarrow2Up.png");
    packManUpTexture = LoadTextureFromImage(packManUp);
    Image packManDown = LoadImage("C:\\Users\\alite\\pack man project\\images\\pacNarrow2Down.png");
    pacKManDownTexture = LoadTextureFromImage(packManDown);
    Image packManLeft = LoadImage("C:\\Users\\alite\\pack man project\\images\\pacNarrow2Left.png");
    packManLeftTexture = LoadTextureFromImage(packManLeft);
    Image star = LoadImage("C:\\Users\\alite\\pack man project\\images\\star.png");
    starTexture = LoadTextureFromImage(star);
    Image starO = LoadImage("C:\\Users\\alite\\pack man project\\images\\starOrange.png");
    star2Texture = LoadTextureFromImage(starO);
    Image blinkyL2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\blinkyL2.png");
    blinkyL2Texture = LoadTextureFromImage(blinkyL2);
    Image blinkyD2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\blinkyD2.png");
    blinkyD2Texture = LoadTextureFromImage(blinkyD2);
    Image blinkyU2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\blinkyU2.png");
    blinkyU2Texture = LoadTextureFromImage(blinkyU2);
    Image blinkyR2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\blinkyR2.png");
    blinkyR2Texture = LoadTextureFromImage(blinkyR2);
    Image heart = LoadImage("C:\\Users\\alite\\pack man project\\images\\heart.png");
    hearTexture = LoadTextureFromImage(heart);
    Image clydeL2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\clydeL2.png");
    clydeL2Texture = LoadTextureFromImage(clydeL2);
    Image clydeD2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\clydeD2.png");
    clydeD2Texture = LoadTextureFromImage(clydeD2);
    Image clydeU2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\clydeU2.png");
    clydeU2Texture = LoadTextureFromImage(clydeU2);
    Image clydeR2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\clydeR2.png");
    clydeR2Texture = LoadTextureFromImage(clydeR2);
    Image inkyL2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\inkyL2_11zon.png");
    inkyL2Texture = LoadTextureFromImage(inkyL2);
    Image inkyD2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\inkyD2_11zon.png");
    inkyD2Texture = LoadTextureFromImage(inkyD2);
    Image inkyU2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\inkyU2_11zon.png");
    inkyU2Texture = LoadTextureFromImage(inkyU2);
    Image inkyR2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\inkyR2_11zon.png");
    inkyR2Texture = LoadTextureFromImage(inkyR2);
    Image pinkyL2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\pinkyL2_11zon.png");
    pinkyL2Texture = LoadTextureFromImage(pinkyL2);
    Image pinkyD2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\pinkyD2_11zon.png");
    pinkyD2Texture = LoadTextureFromImage(pinkyD2);
    Image pinkyU2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\pinkyU2_11zon.png");
    pinkyU2Texture = LoadTextureFromImage(pinkyU2);
    Image pinkyR2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\pinkyR2_11zon.png");
    pinkyR2Texture = LoadTextureFromImage(pinkyR2);
    Image ginkyL2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\ginkyL2.png");
    ginkyL2Texture = LoadTextureFromImage(ginkyL2);
    Image ginkyD2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\ginkyD2.png");
    ginkyD2Texture = LoadTextureFromImage(ginkyD2);
    Image ginkyU2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\ginkyU2.png");
    ginkyU2Texture = LoadTextureFromImage(ginkyU2);
    Image ginkyR2 = LoadImage("C:\\Users\\alite\\pack man project\\images\\ginkyR2.png");
    ginkyR2Texture = LoadTextureFromImage(ginkyR2);
    Image cherry = LoadImage("C:\\Users\\alite\\pack man project\\images\\cherry.png");
    cherryTexture = LoadTextureFromImage(cherry);
    Image apple = LoadImage("C:\\Users\\alite\\pack man project\\images\\apple.png");
    appleTexture = LoadTextureFromImage(apple);
    Image pepper = LoadImage("C:\\Users\\alite\\pack man project\\images\\pepper.png");
    pepperTexture = LoadTextureFromImage(pepper);
    Image mushroom = LoadImage("C:\\Users\\alite\\pack man project\\images\\mushroom.png");
    mushroomTexture = LoadTextureFromImage(mushroom);
    Image blue1 = LoadImage("C:\\Users\\alite\\pack man project\\images\\blue1.png");
    blue1Texture = LoadTextureFromImage(blue1);
    Image white = LoadImage("C:\\Users\\alite\\pack man project\\images\\white2_11zon.png");
    whiteTexchure = LoadTextureFromImage(white);
    Image fire = LoadImage("C:\\Users\\alite\\pack man project\\images\\fire.png");
    fireTexture = LoadTextureFromImage(fire);


}

void CloseGame(){
    UnloadTexture(packManNarrowTexture);
    UnloadTexture(packManClosedTexture);
    UnloadTexture(packManLeftTexture);
    UnloadTexture(pacKManDownTexture);
    UnloadTexture(packManUpTexture);
    UnloadTexture(starTexture);
    UnloadTexture(star2Texture);
    UnloadTexture(blinkyL2Texture);
    UnloadTexture(blinkyD2Texture);
    UnloadTexture(blinkyR2Texture);
    UnloadTexture(blinkyU2Texture);
    UnloadTexture(clydeD2Texture);
    UnloadTexture(clydeL2Texture);
    UnloadTexture(clydeR2Texture);
    UnloadTexture(clydeU2Texture);
    UnloadTexture(inkyD2Texture);
    UnloadTexture(inkyL2Texture);
    UnloadTexture(inkyR2Texture);
    UnloadTexture(inkyU2Texture);
    UnloadTexture(pinkyD2Texture);
    UnloadTexture(pinkyL2Texture);
    UnloadTexture(pinkyR2Texture);
    UnloadTexture(pinkyU2Texture);
    UnloadTexture(ginkyD2Texture);
    UnloadTexture(ginkyL2Texture);
    UnloadTexture(ginkyR2Texture);
    UnloadTexture(ginkyU2Texture);
    UnloadTexture(appleTexture);
    UnloadTexture(cherryTexture);
    UnloadTexture(pepperTexture);
    UnloadTexture(mushroomTexture);
    UnloadTexture(blue1Texture);
    UnloadTexture(whiteTexchure);
    UnloadTexture(fireTexture);
}

void DrawStar(){
    int count = 0 ;


    srand(time(NULL));

    for(; count < 10 ;) {
        int x = rand()%20;
        int y = rand()%35;
        if (map[x][y] == 0) {
            map[x][y] = 3;
            count+=1;
        }
    }

}
void DrawCherry(){
    while (true){
        srand(time(NULL));
        int x = rand()%20;
        int y = rand()%35;
        if (map[x][y] == 0) {
            map[x][y] = 5;
            break;
        }
    }


}
void DrawApple(){
    while (true){
        srand(time(NULL));
        int x = rand()%20;
        int y = rand()%35;
        if (map[x][y] == 0) {
            map[x][y] = 6;
            break;
        }
    }


}
void DrawPepper(){
    while (true){
        srand(time(NULL));
        int x = rand()%20;
        int y = rand()%35;
        if (map[x][y] == 0) {
            map[x][y] = 7;
            break;
        }

    }


}
void DrawMushroom(){
    while (true){
        srand(time(NULL));
        int x = rand()%20;
        int y = rand()%35;
        if (map[x][y] == 0) {
            map[x][y] = 8;
            break;
        }
    }


}
int flagForEatGhost = 0 ;
int flagForEatPepper = 0 ;
int flagForUp = 0;
int flagForDown = 0;
int flagForLeft = 0 ;
void randomToAppear(float * x , float * y){

    while(true){
        srand(time(0));

        int row = rand() % 20 ;
        int column = rand() % 35 ;
        if(map[column][row]== 0 && column*80 < 1601){
            *x = row*80;
            *y = column*80;
            break;
        }
    }
}
extern Sound scoreSound;
extern Sound bithing;

void MovePackMan() {
    int packManWidth = 40;
    int packManHeight = 40;

    if (IsKeyDown(KEY_RIGHT) && packManPosition.x < 2759) {
        Rectangle newPackManRect = { packManPosition.x + 2, packManPosition.y, packManWidth, packManHeight };
        int flag = 0 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newPackManRect, wallRect)) {
                        flag = 1;
                        break;
                    }
                }
                else if(map[y][x]==3){
                    Rectangle wallStar = {x * 80 , y * 80,26,26};
                    if(CheckCollisionRecs(newPackManRect,wallStar)){
                        score+=1;
                        PlaySound(scoreSound);
                        flagForScore = 0 ;
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 5){
                    Rectangle wallCherry = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallCherry)){
                        flagForEatGhost = 1;
                        PlaySound(bithing);
                        timeEat = 800;
                        map[y][x]=0;
                        break;
                    }
                }

                else if(map[y][x] == 7){
                    Rectangle wallPepper = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallPepper)){
                        map[y][x]=0;
                        flagForEatPepper = 1;
                        timeEatPepper = 700;
                        PlaySound(bithing);
                        speed+=1;
                        break;
                    }
                }
                else if(map[y][x] == 6){
                    Rectangle wallApple = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallApple)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        if(life != 3){
                            life += 1;
                        }
                        break;
                    }
                }
                else if(map[y][x] == 8){
                    Rectangle wallMushroom = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallMushroom)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        life-=1;
                        break;
                    }
                }

            }
            if (flag == 1) break;
        }
        if (flag == 0){
            packManPosition.x += 2 + speed;
        }
    } else if (IsKeyDown(KEY_LEFT) && packManPosition.x > 0) {
        flagForLeft = 1;
        Rectangle newPackManRect = { packManPosition.x - 20, packManPosition.y, packManWidth, packManHeight };
        int flag = 0;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newPackManRect, wallRect)) {
                        flag = 1;
                        break;
                    }
                }
                else if(map[y][x]==3){
                    Rectangle wallStar = {x * 80 , y * 80,26,26};
                    if(CheckCollisionRecs(newPackManRect,wallStar)){
                        score+=1;
                        PlaySound(scoreSound);
                        flagForScore = 0 ;
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 5){
                    Rectangle wallCherry = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallCherry)){
                        flagForEatGhost = 1;
                        timeEat = 800;
                        PlaySound(bithing);
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 7){
                    Rectangle wallPepper = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallPepper)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        speed+=1;
                        flagForEatPepper = 1;
                        timeEatPepper = 700;
                        break;
                    }
                }
                else if(map[y][x] == 6){
                    Rectangle wallApple = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallApple)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        if(life != 3){
                            life += 1;
                        }
                        break;
                    }
                }
                else if(map[y][x] == 8){
                    Rectangle wallMushroom = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallMushroom)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        life-=1;
                        break;
                    }
                }

            }
            if (flag == 1) break;
        }
        if (flag == 0) packManPosition.x -= 2 + speed;
    } else if (IsKeyDown(KEY_UP) && packManPosition.y > 0) {
        flagForUp = 1;
        Rectangle newPackManRect = { packManPosition.x, packManPosition.y - 20, packManWidth, packManHeight };
        int flag = 0;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newPackManRect, wallRect)) {
                        flag = 1;
                        break;
                    }
                }
                else if(map[y][x]==3){
                    Rectangle wallStar = {x * 80 , y * 80,26,26};
                    if(CheckCollisionRecs(newPackManRect,wallStar)){
                        score+=1;
                        flagForScore = 0 ;
                        PlaySound(scoreSound);
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 5){
                    Rectangle wallCherry = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallCherry)){
                        flagForEatGhost = 1;
                        timeEat = 800;
                        PlaySound(bithing);
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 7){
                    Rectangle wallPepper = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallPepper)){
                        map[y][x]=0;
                        speed+=1;
                        flagForEatPepper = 1;
                        timeEatPepper = 700;
                        PlaySound(bithing);
                        break;
                    }
                }
                else if(map[y][x] == 6){
                    Rectangle wallApple = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallApple)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        if(life != 3){
                            life += 1;
                        }
                        break;
                    }
                }
                else if(map[y][x] == 8){
                    Rectangle wallMushroom = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallMushroom)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        life-=1;
                        break;
                    }
                }

            }
            if (flag == 1) break;
        }
        if (flag == 0) packManPosition.y -= 2+speed;
    } else if (IsKeyDown(KEY_DOWN) && packManPosition.y < 1559) {
        flagForDown = 1;
        Rectangle newPackManRect = { packManPosition.x, packManPosition.y + 2, packManWidth, packManHeight };
        int flag = 0;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newPackManRect, wallRect)) {
                        flag = 1;
                        break;
                    }
                }
                else if(map[y][x]==3){
                    Rectangle wallStar = {x * 80 , y * 80,26,26};
                    if(CheckCollisionRecs(newPackManRect,wallStar)){
                        score+=1;
                        PlaySound(scoreSound);
                        flagForScore = 0 ;
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 5){
                    Rectangle wallCherry = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallCherry)){
                        flagForEatGhost = 1;
                        PlaySound(bithing);
                        timeEat = 800;
                        map[y][x]=0;
                        break;
                    }
                }
                else if(map[y][x] == 7){
                    Rectangle wallPepper = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallPepper)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        speed+=1;
                        flagForEatPepper = 1;
                        timeEatPepper = 700;
                        break;
                    }
                }
                else if(map[y][x] == 6){
                    Rectangle wallApple = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallApple)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        if(life != 3){
                            life += 1;
                        }
                        break;
                    }
                }
                else if(map[y][x] == 8){
                    Rectangle wallMushroom = {x*80,y*80,75,75};
                    if(CheckCollisionRecs(newPackManRect,wallMushroom)){
                        map[y][x]=0;
                        PlaySound(bithing);
                        life-=1;
                        break;
                    }
                }

            }
            if (flag == 1) break;
        }
        if (flag == 0) packManPosition.y += 2 + speed;
    }

    counter += 1;
    if(score % 10 == 0 && flagForScore == 0 && score != 0){
        DrawStar();
        DrawCherry();
        DrawPepper();
        DrawMushroom();
        flagForScore = 1 ;
        if(score % 20 == 0){
            DrawApple();
        }
    }

}
int flagBlinkyUp = 0 ;
int flagBlinkyDown = 0 ;
int flagBlinkyRight = 0 ;
int flagBlinkyLeft = 0 ;
int flagCheckUpBlinky = 0 ;
int flagCheckRightBlinky = 0 ;
int flagCheckLeftBlinky = 0 ;
int flagCheckDownBlinky = 0 ;
extern Sound bumpToGhost;
void MoveGhost1(){
    flagBlinkyUp = 0 ;
    flagBlinkyDown = 0 ;
    flagBlinkyRight = 0 ;
    flagBlinkyLeft = 0 ;
    Rectangle newginkyRect = {ginkyPosition.x,ginkyPosition.y,41,41};
    Rectangle newpinkyRect = {pinkyPosition.x,pinkyPosition.y,41,41};
    Rectangle newclydeRect = { clydePosition.x, clydePosition.y, 41, 41 };
    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if (flagCheckRightBlinky == 0  && blinkyPosition.x < 2800) {
        Rectangle newblinkyRect = { blinkyPosition.x + 2, blinkyPosition.y, 41, 41 };
        int flag = 0 ;
        flagBlinkyRight = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckRightBlinky = 1;
                        break;
                    }
                    if(blinkyPosition.x >= 2759){
                        flag = 1;
                        flagCheckRightBlinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition.x += 2;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition.x,&blinkyPosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newblinkyRect,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
    }
    else if (flagCheckDownBlinky == 0 && blinkyPosition.y <1600) {
        Rectangle newblinkyRect = { blinkyPosition.x , blinkyPosition.y+2, 41, 41 };
        int flag = 0 ;
        flagBlinkyDown = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckDownBlinky = 1;
                        break;
                    }
                    if(blinkyPosition.y>=1559){
                        flag = 1;
                        flagCheckDownBlinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition.y += 2;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition.x,&blinkyPosition.y);
            PlaySound(bithing);

        }
        if(CheckCollisionRecs(newblinkyRect,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
    }
    else if (flagCheckLeftBlinky == 0  && blinkyPosition.x >= 0) {
        Rectangle newblinkyRect = { blinkyPosition.x - 2, blinkyPosition.y, 28, 28 };
        int flag = 0 ;
        flagBlinkyLeft = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckLeftBlinky = 1  ;
                        break;
                    }
                    if(blinkyPosition.x == 0){
                        flag = 1;
                        flagCheckLeftBlinky = 1  ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition.x -= 2;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect ) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition.x,&blinkyPosition.y);
            PlaySound(bithing);


        }
        if(CheckCollisionRecs(newblinkyRect,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
    }
    else if (flagCheckUpBlinky == 0 && blinkyPosition.y >= 0) {
        Rectangle newblinkyRect = { blinkyPosition.x , blinkyPosition.y-2, 41, 41 };
        int flag = 0 ;
        flagBlinkyUp = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckUpBlinky = 1;
                        break;
                    }
                    if(blinkyPosition.y == 0){
                        flag = 1;
                        flagCheckUpBlinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition.y -= 2;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition.x,&blinkyPosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newblinkyRect,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky = rand()%2 ;
            flagCheckRightBlinky = rand()%2 ;
            flagCheckLeftBlinky =rand()%2 ;
            flagCheckDownBlinky = rand()%2 ;
        }
    }

    if(flagCheckUpBlinky == 1 && flagCheckDownBlinky == 1 && flagCheckLeftBlinky == 1 && flagCheckUpBlinky == 1){
        srand(time(0));

        flagCheckUpBlinky = rand()%2 ;
        flagCheckRightBlinky = rand()%2 ;
        flagCheckLeftBlinky =rand()%2 ;
        flagCheckDownBlinky = rand()%2 ;
    }

}
int flagBlinkyUp2 = 0 ;
int flagBlinkyDown2 = 0 ;
int flagBlinkyRight2 = 0 ;
int flagBlinkyLeft2 = 0 ;
int flagCheckUpBlinky2 = 0 ;
int flagCheckRightBlinky2 = 0 ;
int flagCheckLeftBlinky2 = 0 ;
int flagCheckDownBlinky2 = 0 ;
void MoveGhost10(){
    flagBlinkyUp2 = 0 ;
    flagBlinkyDown2 = 0 ;
    flagBlinkyRight2 = 0 ;
    flagBlinkyLeft2 = 0 ;
    Rectangle newginkyRect = {ginkyPosition.x,ginkyPosition.y,41,41};
    Rectangle newpinkyRect = {pinkyPosition.x,pinkyPosition.y,41,41};
    Rectangle newclydeRect = { clydePosition.x, clydePosition.y, 41, 41 };
    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if (flagCheckRightBlinky2 == 0  && blinkyPosition2.x < 2800) {
        Rectangle newblinkyRect2 = { blinkyPosition2.x + 3.8, blinkyPosition2.y, 41, 41 };
        int flag = 0 ;
        flagBlinkyRight2 = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckRightBlinky2 = 1;
                        break;
                    }
                    if(blinkyPosition2.x >= 2755){
                        flag = 1;
                        flagCheckRightBlinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition2.x += 3.8;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition2.x,&blinkyPosition2.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newblinkyRect2,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
    }
    else if (flagCheckDownBlinky2 == 0 && blinkyPosition2.y <1600) {
        Rectangle newblinkyRect2 = { blinkyPosition2.x , blinkyPosition2.y + 3.8, 41, 41 };
        int flag = 0 ;
        flagBlinkyDown2 = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckDownBlinky2 = 1;
                        break;
                    }
                    if(blinkyPosition2.y>=1555){
                        flag = 1;
                        flagCheckDownBlinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition2.y += 3.8;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition2.x,&blinkyPosition2.y);
            PlaySound(bithing);

        }
        if(CheckCollisionRecs(newblinkyRect2,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
    }
    else if (flagCheckLeftBlinky2 == 0  && blinkyPosition2.x >= 0) {
        Rectangle newblinkyRect2 = { blinkyPosition2.x - 3.8, blinkyPosition2.y, 28, 28 };
        int flag = 0 ;
        flagBlinkyLeft2 = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckLeftBlinky2 = 1  ;
                        break;
                    }
                    if(blinkyPosition2.x <= 4){
                        flag = 1;
                        flagCheckLeftBlinky2 = 1  ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition2.x -= 3.8;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect2 ) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition2.x,&blinkyPosition2.y);
            PlaySound(bithing);


        }
        if(CheckCollisionRecs(newblinkyRect2,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
    }
    else if (flagCheckUpBlinky2 == 0 && blinkyPosition2.y >= 0) {
        Rectangle newblinkyRect2 = { blinkyPosition2.x , blinkyPosition2.y-3.8, 41, 41 };
        int flag = 0 ;
        flagBlinkyUp2 = 1 ;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = { x * 80, y * 80, 80, 80 };
                    if (CheckCollisionRecs(newblinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckUpBlinky2 = 1;
                        break;
                    }
                    if(blinkyPosition2.y <= 4){
                        flag = 1;
                        flagCheckUpBlinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0){
            blinkyPosition2.y -= 3.8;
        }
        if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 0){
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -=1;
        }
        else if(CheckCollisionRecs(newPackManRect,newblinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&blinkyPosition2.x,&blinkyPosition2.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newblinkyRect2,newclydeRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newblinkyRect2,newginkyRect)){
            srand(time(0));

            flagCheckUpBlinky2 = rand()%2 ;
            flagCheckRightBlinky2 = rand()%2 ;
            flagCheckLeftBlinky2 =rand()%2 ;
            flagCheckDownBlinky2 = rand()%2 ;
        }
    }

    if(flagCheckUpBlinky2 == 1 && flagCheckDownBlinky2 == 1 && flagCheckLeftBlinky2 == 1 && flagCheckUpBlinky2 == 1){
        srand(time(0));

        flagCheckUpBlinky2 = rand()%2 ;
        flagCheckRightBlinky2 = rand()%2 ;
        flagCheckLeftBlinky2 =rand()%2 ;
        flagCheckDownBlinky2 = rand()%2 ;
    }
}
int flagClydeUp = 0 ;
int flagClydeDown = 0 ;
int flagClydeRight = 0 ;
int flagClydeLeft = 0 ;
int flagCheckUp = 0 ;
int flagCheckRight = 0 ;
int flagCheckLeft = 0 ;
int flagCheckDown = 0 ;
void MoveGhost2(){
    flagClydeUp = 0 ;
    flagClydeDown = 0 ;
    flagClydeRight = 0 ;
    flagClydeLeft = 0 ;
    Rectangle newginkyRect = {ginkyPosition.x,ginkyPosition.y,41,41};
    Rectangle newpinkyRect = {pinkyPosition.x,pinkyPosition.y,41,41};
    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( clydePosition.x < 2800 && flagCheckRight == 0) {

            Rectangle newclydeRect = {clydePosition.x + 2, clydePosition.y, 41, 41};
            int flag = 0;
            flagClydeRight = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 80, 80};
                        if (CheckCollisionRecs(newclydeRect, wallRect)) {
                            flag = 1;
                            flagCheckRight = 1;
                            break;
                        }
                        if(clydePosition.x >= 2759){
                            flag = 1 ;
                            flagCheckRight = 1;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                clydePosition.x += 2;
            }
            if (CheckCollisionRecs(newPackManRect, newclydeRect) && flagForEatGhost == 0) {
                PlaySound(bumpToGhost);
                packManPosition.x=2000;
                packManPosition.y = 100 ;

                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newclydeRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&clydePosition.x,&clydePosition.y);
                PlaySound(bithing);
            }
        if(CheckCollisionRecs(newclydeRect,newpinkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect,newginkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }
    }

    else if ( clydePosition.y >= 0 && flagCheckUp == 0) {
            Rectangle newclydeRect = {clydePosition.x, clydePosition.y - 2, 41, 41};
            int flag = 0;
            flagClydeUp = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 80, 80};
                        if (CheckCollisionRecs(newclydeRect, wallRect)) {
                            flag = 1;
                            flagCheckUp = 1;
                            break;
                        }
                        if(clydePosition.y <=1){
                            flag = 1;
                            flagCheckUp = 1 ;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                clydePosition.y -= 2;
            }
            if (CheckCollisionRecs(newPackManRect, newclydeRect) && flagForEatGhost == 0) {
                PlaySound(bumpToGhost);
                packManPosition.x=2000;
                packManPosition.y = 100 ;

                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newclydeRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&clydePosition.x,&clydePosition.y);
                PlaySound(bithing);
            }
        if(CheckCollisionRecs(newclydeRect,newpinkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect,newginkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }

    }
    else if (  clydePosition.y <1600 && flagCheckDown == 0 ) {
            Rectangle newclydeRect = {clydePosition.x, clydePosition.y + 2, 41, 41};
            int flag = 0;
            flagClydeDown = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 41, 41};
                        if (CheckCollisionRecs(newclydeRect, wallRect)) {
                            flag = 1;
                            flagCheckDown = 1;
                            break;
                        }
                        if(clydePosition.y >= 1559){
                            flag = 1 ;
                            flagCheckDown = 1;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                clydePosition.y += 2;
            }
            if (CheckCollisionRecs(newPackManRect, newclydeRect) && flagForEatGhost == 0) {
                PlaySound(bumpToGhost);
                packManPosition.x=2000;
                packManPosition.y = 100 ;

                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newclydeRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&clydePosition.x,&clydePosition.y);
                PlaySound(bithing);
            }
        if(CheckCollisionRecs(newclydeRect,newpinkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect,newginkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }

    }
    else if ( clydePosition.x >= 0 && flagCheckLeft == 0) {
        Rectangle newclydeRect = {clydePosition.x - 2, clydePosition.y, 41, 41};
        int flag = 0;
        flagClydeLeft = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newclydeRect, wallRect)) {
                        flag = 1;
                        flagCheckLeft = 1;
                        break;
                    }
                    if(clydePosition.x <= 1){
                        flag = 1 ;
                        flagCheckLeft = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            clydePosition.x -= 2;
        }
        if (CheckCollisionRecs(newPackManRect, newclydeRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newclydeRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&clydePosition.x,&clydePosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newclydeRect,newpinkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect,newginkyRect)){
            srand(time(0));

            flagCheckUp = rand()%2 ;
            flagCheckRight = rand()%2 ;
            flagCheckLeft =rand()%2 ;
            flagCheckDown = rand()%2 ;
        }

    }
    if(flagCheckUp == 1 && flagCheckDown == 1 && flagCheckLeft == 1 && flagCheckUp == 1){
        srand(time(0));

        flagCheckUp = rand()%2 ;
        flagCheckRight = rand()%2 ;
        flagCheckLeft =rand()%2 ;
        flagCheckDown = rand()%2 ;
    }

}
int flagClydeUp2 = 0 ;
int flagClydeDown2 = 0 ;
int flagClydeRight2 = 0 ;
int flagClydeLeft2 = 0 ;
int flagCheckUp2 = 0 ;
int flagCheckRight2 = 0 ;
int flagCheckLeft2 = 0 ;
int flagCheckDown2 = 0 ;
void MoveGhost9(){
    flagClydeUp2 = 0 ;
    flagClydeDown2 = 0 ;
    flagClydeRight2 = 0 ;
    flagClydeLeft2 = 0 ;
    Rectangle newginkyRect = {ginkyPosition.x,ginkyPosition.y,41,41};
    Rectangle newpinkyRect = {pinkyPosition.x,pinkyPosition.y,41,41};
    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( clydePosition2.x < 2800 && flagCheckRight2 == 0) {

        Rectangle newclydeRect2 = {clydePosition2.x + 3.5, clydePosition2.y, 41, 41};
        int flag = 0;
        flagClydeRight2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newclydeRect2, wallRect)) {
                        flag = 1;
                        flagCheckRight2 = 1;
                        break;
                    }
                    if(clydePosition2.x >= 2755){
                        flag = 1 ;
                        flagCheckRight2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            clydePosition2.x += 3.5;
        }
        if (CheckCollisionRecs(newPackManRect, newclydeRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newclydeRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&clydePosition2.x,&clydePosition2.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newclydeRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect2,newginkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }
    }

    else if ( clydePosition2.y >= 0 && flagCheckUp2 == 0) {
        Rectangle newclydeRect2 = {clydePosition2.x, clydePosition2.y - 3.5, 41, 41};
        int flag = 0;
        flagClydeUp2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newclydeRect2, wallRect)) {
                        flag = 1;
                        flagCheckUp2 = 1;
                        break;
                    }
                    if(clydePosition2.y <=4){
                        flag = 1;
                        flagCheckUp2 = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            clydePosition2.y -= 3.5;
        }
        if (CheckCollisionRecs(newPackManRect, newclydeRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newclydeRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&clydePosition2.x,&clydePosition2.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newclydeRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect2,newginkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }

    }
    else if (  clydePosition2.y <1600 && flagCheckDown2 == 0 ) {
        Rectangle newclydeRect2 = {clydePosition2.x, clydePosition2.y + 3.5, 41, 41};
        int flag = 0;
        flagClydeDown2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 41, 41};
                    if (CheckCollisionRecs(newclydeRect2, wallRect)) {
                        flag = 1;
                        flagCheckDown2 = 1;
                        break;
                    }
                    if(clydePosition2.y >= 1555){
                        flag = 1 ;
                        flagCheckDown2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            clydePosition2.y += 3.5;
        }
        if (CheckCollisionRecs(newPackManRect, newclydeRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newclydeRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&clydePosition2.x,&clydePosition2.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newclydeRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect2,newginkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }

    }
    else if ( clydePosition2.x >= 0 && flagCheckLeft2 == 0) {
        Rectangle newclydeRect2 = {clydePosition2.x - 3.5, clydePosition2.y, 41, 41};
        int flag = 0;
        flagClydeLeft2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newclydeRect2, wallRect)) {
                        flag = 1;
                        flagCheckLeft2 = 1;
                        break;
                    }
                    if(clydePosition2.x <= 4){
                        flag = 1 ;
                        flagCheckLeft2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            clydePosition2.x -= 3.5;
        }
        if (CheckCollisionRecs(newPackManRect, newclydeRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newclydeRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&clydePosition2.x,&clydePosition2.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newclydeRect2,newpinkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }
        if(CheckCollisionRecs(newclydeRect2,newginkyRect)){
            srand(time(0));

            flagCheckUp2 = rand()%2 ;
            flagCheckRight2 = rand()%2 ;
            flagCheckLeft2 =rand()%2 ;
            flagCheckDown2 = rand()%2 ;
        }

    }
    if(flagCheckUp2 == 1 && flagCheckDown2 == 1 && flagCheckLeft2 == 1 && flagCheckUp2 == 1){
        srand(time(0));

        flagCheckUp2 = rand()%2 ;
        flagCheckRight2 = rand()%2 ;
        flagCheckLeft2 =rand()%2 ;
        flagCheckDown2 = rand()%2 ;
    }
}
int flaginkyUp = 0 ;
int flaginkyDown = 0 ;
int flaginkyRight = 0 ;
int flaginkyLeft = 0 ;
int flagCheckUpinky = 0 ;
int flagCheckRightinky = 0 ;
int flagCheckLeftinky = 0 ;
int flagCheckDowninky = 0 ;
int counttt = 1 ;
int flagCott = 0 ;
int timeForInkyRandom = 0 ;
float r , c ;
float r1 , c1 ;

void MoveGhost3(){
    counttt +=1;
    flaginkyUp = 0 ;
    flaginkyDown = 0 ;
    flaginkyRight = 0 ;
    flaginkyLeft = 0 ;
    flagCheckLeftinky = 0 ;
    flagCheckUpinky = 0 ;
    flagCheckRightinky = 0 ;
    flagCheckDowninky = 0 ;
    printf("flag : %d\n",flagCott);
    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if(counttt % 100 == 2){
        r = inkyPosition.x;
        c = inkyPosition.y;



    }
    if(counttt % 100 == 99 ){
        r1 = inkyPosition.x;
        c1 = inkyPosition.y;


        if((fabs(r1 - r) <= 2 && fabs(c1 - c) <= 2)){
            flagCott = 1;
            timeForInkyRandom = 70;
        }

    }
    if(flagCott == 1 && timeForInkyRandom != 1){
        timeForInkyRandom -= 1;
        flaginkyUp = 0 ;
        flaginkyDown = 0 ;
        flaginkyRight = 0 ;
        flaginkyLeft = 0 ;
        srand(time(0));

        flagCheckUpinky = rand()%2 ;
        flagCheckRightinky = rand()%2 ;
        flagCheckLeftinky =rand()%2 ;
        flagCheckDowninky = rand()%2 ;

        if ( inkyPosition.x < 2800 && flagCheckRightinky == 0) {

            Rectangle newinkyRect = {inkyPosition.x + 2, inkyPosition.y, 40, 40};
            int flag = 0;
            flaginkyRight = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 80, 80};
                        if (CheckCollisionRecs(newinkyRect, wallRect)) {
                            flag = 1;
                            flagCheckRightinky = 1;
                            break;
                        }
                        if(inkyPosition.x >= 2760){
                            flag = 1 ;
                            flagCheckRightinky = 1;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                inkyPosition.x += 2;
            }
            if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
                PlaySound(bumpToGhost);
                packManPosition.x=2000;
                packManPosition.y = 100 ;
                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&inkyPosition.x,&inkyPosition.y);
                PlaySound(bithing);
            }

        }


        else if (  inkyPosition.y < 1600 && flagCheckDowninky == 0 ) {
            Rectangle newinkyRect = {inkyPosition.x, inkyPosition.y + 2, 40, 40};
            int flag = 0;
            flaginkyDown = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 80, 80};
                        if (CheckCollisionRecs(newinkyRect, wallRect)) {
                            flag = 1;
                            flagCheckDowninky = 1;
                            break;
                        }
                        if(inkyPosition.y >= 1560){
                            flag = 1 ;
                            flagCheckDowninky = 1;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                inkyPosition.y +=2;
            }
            if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0 ) {
                PlaySound(bumpToGhost);
                packManPosition.x=2000;
                packManPosition.y = 100 ;

                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&inkyPosition.x,&inkyPosition.y);
                PlaySound(bithing);
            }

        }
        else if ( inkyPosition.x >= 0 && flagCheckLeftinky == 0) {
            Rectangle newinkyRect = {inkyPosition.x - 2, inkyPosition.y, 40, 40};
            int flag = 0;
            flaginkyLeft = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 80, 80};
                        if (CheckCollisionRecs(newinkyRect, wallRect)) {
                            flag = 1;
                            flagCheckLeftinky = 1;
                            break;
                        }
                        if(inkyPosition.x <= 1){
                            flag = 1 ;
                            flagCheckLeftinky = 1;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                inkyPosition.x -= 2;
            }
            if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
                PlaySound(bumpToGhost);
                packManPosition.x=100;
                packManPosition.y = 100 ;

                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&inkyPosition.x,&inkyPosition.y);
                PlaySound(bithing);
            }

        }
        else if ( inkyPosition.y >= 0 && flagCheckUpinky == 0) {
            Rectangle newinkyRect = {inkyPosition.x, inkyPosition.y - 2, 40, 40};
            int flag = 0;
            flaginkyUp = 1;
            for (int y = 0; y < 20; y++) {
                for (int x = 0; x < 35; x++) {
                    if (map[y][x] == 1 || map[y][x] == 2) {
                        Rectangle wallRect = {x * 80, y * 80, 80, 80};
                        if (CheckCollisionRecs(newinkyRect, wallRect)) {
                            flag = 1;
                            flagCheckUpinky = 1;
                            break;
                        }
                        if(inkyPosition.y <= 1){
                            flag = 1;
                            flagCheckUpinky = 1 ;
                            break;
                        }
                    }


                }
                if (flag == 1) break;
            }
            if (flag == 0) {
                inkyPosition.y -= 3;
            }
            if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
                PlaySound(bumpToGhost);
                packManPosition.x=2000;
                packManPosition.y = 100 ;

                life -= 1;
            }
            else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
                randomToAppear(&inkyPosition.x,&inkyPosition.y);
                PlaySound(bithing);
            }

        }



    }
    if(timeForInkyRandom == 1){
        flagCott = 0 ;
    }

    if ( inkyPosition.x < 2800 && flagCheckRightinky == 0 && flagCott == 0) {

        Rectangle newinkyRect = {inkyPosition.x + 2, inkyPosition.y, 40, 40};
        int flag = 0;
        flaginkyRight = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckRightinky = 1;
                        break;
                    }
                    if(inkyPosition.x >= 2760){
                        flag = 1 ;
                        flagCheckRightinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) {
                flagCheckLeftinky = 1;

                break;
            }
        }
        if (flag == 0 && (packManPosition.x > inkyPosition.x)) {
            flagCheckLeftinky = 0;
            inkyPosition.x += 2;
        }
        else{
            flagCheckLeftinky = 1;
        }
        if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition.x,&inkyPosition.y);
            PlaySound(bithing);
        }

    }
    if ( inkyPosition.x >= 0 && flagCheckLeftinky == 1 && flagCott == 0) {
        Rectangle newinkyRect = {inkyPosition.x - 2, inkyPosition.y, 40, 40};
        int flag = 0;
        flaginkyLeft = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckLeftinky = 1;
                        break;
                    }
                    if(inkyPosition.x <= 1){
                        flag = 1 ;
                        flagCheckLeftinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) {
                flagCheckUpinky = 1 ;
                break;
            }
        }
        if (flag == 0 && packManPosition.x < inkyPosition.x) {
            inkyPosition.x -= 2;
        }
        else{
            flagCheckUpinky = 1;
        }
        if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition.x,&inkyPosition.y);
            PlaySound(bithing);
        }

    }
    if ( inkyPosition.y >= 0 && flagCheckUpinky == 1 && flagCott == 0)  {
        Rectangle newinkyRect = {inkyPosition.x, inkyPosition.y - 2, 40, 40};
        int flag = 0;
        flaginkyUp = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckUpinky = 1;
                        break;
                    }
                    if(inkyPosition.y <=1 ){
                        flag = 1;
                        flagCheckUpinky = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1){
                flagCheckDowninky = 1;

                break;
            }
        }
        if (flag == 0 && packManPosition.y < inkyPosition.y && flagCott == 0) {
            inkyPosition.y -= 2;
            flagCheckDowninky = 0;

        }
        else{
            flagCheckDowninky = 1;
        }
        if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition.x,&inkyPosition.y);
            PlaySound(bithing);
        }

    }
    if (  inkyPosition.y <1600 && flagCheckDowninky == 1 ) {
        Rectangle newinkyRect = {inkyPosition.x, inkyPosition.y + 2, 40, 40};
        int flag = 0;
        flaginkyDown = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckDowninky = 1;
                        break;
                    }
                    if(inkyPosition.y >= 1560){
                        flag = 1 ;
                        flagCheckDowninky = 1;
                        break;
                    }
                }


            }
            if (flag == 1){
                inkyPosition.y -= 2;

                break;
            }
        }
        if (flag == 0 && packManPosition.y> inkyPosition.y) {
            inkyPosition.y += 2;
        }
        else{
            inkyPosition.y += 2;
        }
        if (CheckCollisionRecs(newPackManRect, newinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition.x,&inkyPosition.y);
            PlaySound(bithing);
        }

    }

    /*if(flagCheckUpinky == 1 && flagCheckDowninky == 1 && flagCheckLeftinky == 1 && flagCheckUpinky == 1){
        srand(time(0));

        flagCheckUpinky = rand()%2 ;
        flagCheckRightinky = rand()%2 ;
        flagCheckLeftinky =rand()%2 ;
        flagCheckDowninky = rand()%2 ;
    }*/
}
int flagpinkyUp = 0 ;
int flagpinkyDown = 0 ;
int flagpinkyRight = 0 ;
int flagpinkyLeft = 0 ;
int flagCheckUppinky = 0 ;
int flagCheckRightpinky = 0 ;
int flagCheckLeftpinky = 0 ;
int flagCheckDownpinky = 0 ;
void MoveGhost4(){
    flagpinkyUp = 0 ;
    flagpinkyDown = 0 ;
    flagpinkyRight = 0 ;
    flagpinkyLeft = 0 ;
    Rectangle newginkyRect = {ginkyPosition.x,ginkyPosition.y,41,41};
    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( pinkyPosition.x < 2800 && flagCheckRightpinky == 0) {

        Rectangle newpinkyRect = {pinkyPosition.x + 2, pinkyPosition.y, 40, 40};
        int flag = 0;
        flagpinkyRight = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckRightpinky = 1;
                        break;
                    }
                    if(pinkyPosition.x >= 2760){
                        flag = 1 ;
                        flagCheckRightpinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition.x += 2;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;
            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition.x,&pinkyPosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newpinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUppinky = rand()%2 ;
            flagCheckRightpinky = rand()%2 ;
            flagCheckLeftpinky =rand()%2 ;
            flagCheckDownpinky = rand()%2 ;
        }

    }


    else if (  pinkyPosition.y <1600 && flagCheckDownpinky == 0 ) {
        Rectangle newpinkyRect = {pinkyPosition.x, pinkyPosition.y + 2, 40, 40};
        int flag = 0;
        flagpinkyDown = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckDownpinky = 1;
                        break;
                    }
                    if(pinkyPosition.y >= 1560){
                        flag = 1 ;
                        flagCheckDownpinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition.y += 2;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect) && flagForEatGhost == 0 ) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition.x,&pinkyPosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newpinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUppinky = rand()%2 ;
            flagCheckRightpinky = rand()%2 ;
            flagCheckLeftpinky =rand()%2 ;
            flagCheckDownpinky = rand()%2 ;
        }

    }
    else if ( pinkyPosition.x >= 0 && flagCheckLeftpinky == 0) {
        Rectangle newpinkyRect = {pinkyPosition.x - 2, pinkyPosition.y, 40, 40};
        int flag = 0;
        flagpinkyLeft = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckLeftpinky = 1;
                        break;
                    }
                    if(pinkyPosition.x <= 1){
                        flag = 1 ;
                        flagCheckLeftpinky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition.x -= 2;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition.x,&pinkyPosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newpinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUppinky = rand()%2 ;
            flagCheckRightpinky = rand()%2 ;
            flagCheckLeftpinky =rand()%2 ;
            flagCheckDownpinky = rand()%2 ;
        }

    }
    else if ( pinkyPosition.y >= 0 && flagCheckUppinky == 0) {
        Rectangle newpinkyRect = {pinkyPosition.x, pinkyPosition.y - 2, 40, 40};
        int flag = 0;
        flagpinkyUp = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect, wallRect)) {
                        flag = 1;
                        flagCheckUppinky = 1;
                        break;
                    }
                    if(pinkyPosition.y <= 1){
                        flag = 1;
                        flagCheckUppinky = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition.y -= 2;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition.x,&pinkyPosition.y);
            PlaySound(bithing);
        }
        if(CheckCollisionRecs(newpinkyRect,newginkyRect)){
            srand(time(0));

            flagCheckUppinky = rand()%2 ;
            flagCheckRightpinky = rand()%2 ;
            flagCheckLeftpinky =rand()%2 ;
            flagCheckDownpinky = rand()%2 ;
        }

    }
    if(flagCheckUppinky == 1 && flagCheckDownpinky == 1 && flagCheckLeftpinky == 1 && flagCheckUppinky == 1){
        srand(time(0));

        flagCheckUppinky = rand()%2 ;
        flagCheckRightpinky = rand()%2 ;
        flagCheckLeftpinky =rand()%2 ;
        flagCheckDownpinky = rand()%2 ;
    }
}
int flagpinkyUp2 = 0 ;
int flagpinkyDown2 = 0 ;
int flagpinkyRight2 = 0 ;
int flagpinkyLeft2 = 0 ;
int flagCheckUppinky2 = 0 ;
int flagCheckRightpinky2 = 0 ;
int flagCheckLeftpinky2 = 0 ;
int flagCheckDownpinky2 = 0 ;
void MoveGhost7(){
    flagpinkyUp2 = 0 ;
    flagpinkyDown2 = 0 ;
    flagpinkyRight2 = 0 ;
    flagpinkyLeft2 = 0 ;

    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( pinkyPosition2.x < 2800 && flagCheckRightpinky2 == 0) {

        Rectangle newpinkyRect2 = {pinkyPosition2.x + 3, pinkyPosition2.y, 40, 40};
        int flag = 0;
        flagpinkyRight2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckRightpinky2 = 1;
                        break;
                    }
                    if(pinkyPosition2.x >= 2757){
                        flag = 1 ;
                        flagCheckRightpinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition2.x += 3;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;
            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition2.x,&pinkyPosition2.y);
            PlaySound(bithing);
        }

    }


    else if (  pinkyPosition2.y <1600 && flagCheckDownpinky2 == 0 ) {
        Rectangle newpinkyRect2 = {pinkyPosition2.x, pinkyPosition2.y +3, 40, 40};
        int flag = 0;
        flagpinkyDown2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckDownpinky2 = 1;
                        break;
                    }
                    if(pinkyPosition2.y >= 1557){
                        flag = 1 ;
                        flagCheckDownpinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition2.y += 3;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect2) && flagForEatGhost == 0 ) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition2.x,&pinkyPosition2.y);
            PlaySound(bithing);
        }

    }
    else if ( pinkyPosition2.y >= 0 && flagCheckUppinky2 == 0) {
        Rectangle newpinkyRect2 = {pinkyPosition2.x, pinkyPosition2.y - 3, 40, 40};
        int flag = 0;
        flagpinkyUp2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckUppinky2 = 1;
                        break;
                    }
                    if(pinkyPosition2.y <= 4){
                        flag = 1;
                        flagCheckUppinky2 = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition2.y -= 3;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition2.x,&pinkyPosition2.y);
            PlaySound(bithing);
        }

    }
    else if ( pinkyPosition2.x >= 0 && flagCheckLeftpinky2 == 0) {
        Rectangle newpinkyRect2 = {pinkyPosition2.x - 3, pinkyPosition2.y, 40, 40};
        int flag = 0;
        flagpinkyLeft2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newpinkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckLeftpinky2 = 1;
                        break;
                    }
                    if(pinkyPosition2.x <= 4){
                        flag = 1 ;
                        flagCheckLeftpinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            pinkyPosition2.x -= 3;
        }
        if (CheckCollisionRecs(newPackManRect, newpinkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newpinkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&pinkyPosition2.x,&pinkyPosition2.y);
            PlaySound(bithing);
        }

    }

    if(flagCheckUppinky2 == 1 && flagCheckDownpinky2 == 1 && flagCheckLeftpinky2 == 1 && flagCheckUppinky2 == 1){
        srand(time(0));

        flagCheckUppinky2 = rand()%2 ;
        flagCheckRightpinky2 = rand()%2 ;
        flagCheckLeftpinky2 =rand()%2 ;
        flagCheckDownpinky2 = rand()%2 ;
    }
}
int flagginkyUp = 0 ;
int flagginkyDown = 0 ;
int flagginkyRight = 0 ;
int flagginkyLeft = 0 ;
int flagCheckUpginky = 0 ;
int flagCheckRightginky = 0 ;
int flagCheckLeftginky = 0 ;
int flagCheckDownginky = 0 ;
void MoveGhost5(){
    flagginkyUp = 0 ;
    flagginkyDown = 0 ;
    flagginkyRight = 0 ;
    flagginkyLeft = 0 ;

    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( ginkyPosition.x < 2800 && flagCheckRightginky == 0) {

        Rectangle newginkyRect = {ginkyPosition.x + 2, ginkyPosition.y, 40, 40};
        int flag = 0;
        flagginkyRight = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect, wallRect)) {
                        flag = 1;
                        flagCheckRightginky = 1;
                        break;
                    }
                    if(ginkyPosition.x >= 2760){
                        flag = 1 ;
                        flagCheckRightginky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition.x += 2;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition.x,&ginkyPosition.y);
            PlaySound(bithing);
        }

    }


    else if (  ginkyPosition.y <1600 && flagCheckDownginky == 0 ) {
        Rectangle newginkyRect = {ginkyPosition.x, ginkyPosition.y + 2, 40, 40};
        int flag = 0;
        flagginkyDown = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect, wallRect)) {
                        flag = 1;
                        flagCheckDownginky = 1;
                        break;
                    }
                    if(ginkyPosition.y >= 1560){
                        flag = 1 ;
                        flagCheckDownginky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition.y += 2;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition.x,&ginkyPosition.y);
            PlaySound(bithing);
        }

    }
    else if ( ginkyPosition.x >= 0 && flagCheckLeftginky == 0) {
        Rectangle newginkyRect = {ginkyPosition.x - 2, ginkyPosition.y, 40, 40};
        int flag = 0;
        flagginkyLeft = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect, wallRect)) {
                        flag = 1;
                        flagCheckLeftginky = 1;
                        break;
                    }
                    if(ginkyPosition.x == 0){
                        flag = 1 ;
                        flagCheckLeftginky = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition.x -= 2;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition.x,&ginkyPosition.y);
            PlaySound(bithing);
        }

    }
    else if ( ginkyPosition.y > 0 && flagCheckUpginky == 0) {
        Rectangle newginkyRect = {ginkyPosition.x, ginkyPosition.y - 2, 40, 40};
        int flag = 0;
        flagginkyUp = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect, wallRect)) {
                        flag = 1;
                        flagCheckUpginky = 1;
                        break;
                    }
                    if(ginkyPosition.y <= 40){
                        flag = 1;
                        flagCheckUpginky = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition.y -= 2;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;
            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition.x,&ginkyPosition.y);
            PlaySound(bithing);
        }

    }
    if(flagCheckUpginky == 1 && flagCheckDownginky == 1 && flagCheckLeftginky == 1 && flagCheckUpginky == 1){
        srand(time(0));

        flagCheckUpginky = rand()%2 ;
        flagCheckRightginky = rand()%2 ;
        flagCheckLeftginky =rand()%2 ;
        flagCheckDownginky = rand()%2 ;
    }
}
int flagginkyUp2 = 0 ;
int flagginkyDown2 = 0 ;
int flagginkyRight2 = 0 ;
int flagginkyLeft2 = 0 ;
int flagCheckUpginky2 = 0 ;
int flagCheckRightginky2 = 0 ;
int flagCheckLeftginky2 = 0 ;
int flagCheckDownginky2 = 0 ;
void MoveGhost8(){
    flagginkyUp2 = 0 ;
    flagginkyDown2 = 0 ;
    flagginkyRight2 = 0 ;
    flagginkyLeft2 = 0 ;

    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( ginkyPosition2.x < 2800 && flagCheckRightginky2 == 0) {

        Rectangle newginkyRect2 = {ginkyPosition2.x + 2.5, ginkyPosition2.y, 40, 40};
        int flag = 0;
        flagginkyRight2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckRightginky2 = 1;
                        break;
                    }
                    if(ginkyPosition2.x >= 2757){
                        flag = 1 ;
                        flagCheckRightginky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition2.x += 2.5;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition2.x,&ginkyPosition2.y);
            PlaySound(bithing);
        }

    }


    else if (  ginkyPosition2.y <1600 && flagCheckDownginky2 == 0 ) {
        Rectangle newginkyRect2 = {ginkyPosition2.x, ginkyPosition2.y + 2.5, 40, 40};
        int flag = 0;
        flagginkyDown2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckDownginky2 = 1;
                        break;
                    }
                    if(ginkyPosition2.y >= 1557){
                        flag = 1 ;
                        flagCheckDownginky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition2.y += 2.5;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition2.x,&ginkyPosition2.y);
            PlaySound(bithing);
        }

    }
    else if ( ginkyPosition2.x >= 0 && flagCheckLeftginky2 == 0) {
        Rectangle newginkyRect2 = {ginkyPosition2.x - 2.5, ginkyPosition2.y, 40, 40};
        int flag = 0;
        flagginkyLeft2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckLeftginky2 = 1;
                        break;
                    }
                    if(ginkyPosition2.x <= 3){
                        flag = 1 ;
                        flagCheckLeftginky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition2.x -= 2.5;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition2.x,&ginkyPosition2.y);
            PlaySound(bithing);
        }

    }
    else if ( ginkyPosition2.y > 0 && flagCheckUpginky2 == 0) {
        Rectangle newginkyRect2 = {ginkyPosition2.x, ginkyPosition2.y - 2.5, 40, 40};
        int flag = 0;
        flagginkyUp2 = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newginkyRect2, wallRect)) {
                        flag = 1;
                        flagCheckUpginky2 = 1;
                        break;
                    }
                    if(ginkyPosition2.y <= 3){
                        flag = 1;
                        flagCheckUpginky2 = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            ginkyPosition2.y -= 2.5;
        }
        if (CheckCollisionRecs(newPackManRect, newginkyRect2) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;
            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newginkyRect2) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&ginkyPosition2.x,&ginkyPosition2.y);
            PlaySound(bithing);
        }

    }
    if(flagCheckUpginky2 == 1 && flagCheckDownginky2 == 1 && flagCheckLeftginky2 == 1 && flagCheckUpginky2 == 1){
        srand(time(0));

        flagCheckUpginky2 = rand()%2 ;
        flagCheckRightginky2 = rand()%2 ;
        flagCheckLeftginky2 =rand()%2 ;
        flagCheckDownginky2 = rand()%2 ;
    }
}

int flaginky2Up = 0 ;
int flaginky2Down = 0 ;
int flaginky2Right = 0 ;
int flaginky2Left = 0 ;
int flagCheckUpinky2 = 0 ;
int flagCheckRightinky2 = 0 ;
int flagCheckLeftinky2 = 0 ;
int flagCheckDowninky2 = 0 ;
void MoveGhost6(){
    flaginky2Up = 0 ;
    flaginky2Down = 0 ;
    flaginky2Right = 0 ;
    flaginky2Left = 0 ;

    Rectangle newPackManRect = { packManPosition.x, packManPosition.y, 41, 41 };
    if ( inkyPosition2.x < 2800 && flagCheckRightinky2 == 0) {

        Rectangle newinky2Rect = {inkyPosition2.x + 3, inkyPosition2.y, 40, 40};
        int flag = 0;
        flaginky2Right = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinky2Rect, wallRect)) {
                        flag = 1;
                        flagCheckRightinky2 = 1;
                        break;
                    }
                    if(inkyPosition2.x >= 2760){
                        flag = 1 ;
                        flagCheckRightinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            inkyPosition2.x += 3;
        }
        if (CheckCollisionRecs(newPackManRect, newinky2Rect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;
            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinky2Rect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition2.x,&inkyPosition2.y);
            PlaySound(bithing);
        }

    }


    else if (  inkyPosition2.y < 1600 && flagCheckDowninky2 == 0 ) {
        Rectangle newinky2Rect = {inkyPosition2.x, inkyPosition2.y + 3, 40, 40};
        int flag = 0;
        flaginky2Down = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinky2Rect, wallRect)) {
                        flag = 1;
                        flagCheckDowninky2 = 1;
                        break;
                    }
                    if(inkyPosition2.y >= 1560){
                        flag = 1 ;
                        flagCheckDowninky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            inkyPosition2.y +=3;
        }
        if (CheckCollisionRecs(newPackManRect, newinky2Rect) && flagForEatGhost == 0 ) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinky2Rect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition2.x,&inkyPosition2.y);
            PlaySound(bithing);
        }

    }
    else if ( inkyPosition2.x >= 0 && flagCheckLeftinky2 == 0) {
        Rectangle newinky2Rect = {inkyPosition2.x - 3, inkyPosition2.y, 40, 40};
        int flag = 0;
        flaginky2Left = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinky2Rect, wallRect)) {
                        flag = 1;
                        flagCheckLeftinky2 = 1;
                        break;
                    }
                    if(inkyPosition2.x <= 1){
                        flag = 1 ;
                        flagCheckLeftinky2 = 1;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            inkyPosition2.x -= 3;
        }
        if (CheckCollisionRecs(newPackManRect, newinky2Rect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=100;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinky2Rect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition2.x,&inkyPosition2.y);
            PlaySound(bithing);
        }

    }
    else if ( inkyPosition2.y >= 0 && flagCheckUpinky2 == 0) {
        Rectangle newinky2Rect = {inkyPosition2.x, inkyPosition2.y - 3, 40, 40};
        int flag = 0;
        flaginky2Up = 1;
        for (int y = 0; y < 20; y++) {
            for (int x = 0; x < 35; x++) {
                if (map[y][x] == 1 || map[y][x] == 2) {
                    Rectangle wallRect = {x * 80, y * 80, 80, 80};
                    if (CheckCollisionRecs(newinky2Rect, wallRect)) {
                        flag = 1;
                        flagCheckUpinky2 = 1;
                        break;
                    }
                    if(inkyPosition2.y <= 1){
                        flag = 1;
                        flagCheckUpinky2 = 1 ;
                        break;
                    }
                }


            }
            if (flag == 1) break;
        }
        if (flag == 0) {
            inkyPosition2.y -= 3;
        }
        if (CheckCollisionRecs(newPackManRect, newinky2Rect) && flagForEatGhost == 0) {
            PlaySound(bumpToGhost);
            packManPosition.x=2000;
            packManPosition.y = 100 ;

            life -= 1;
        }
        else if(CheckCollisionRecs(newPackManRect,newinky2Rect) && flagForEatGhost == 1 && timeEat != 0){
            randomToAppear(&inkyPosition2.x,&inkyPosition2.y);
            PlaySound(bithing);
        }

    }
    if(flagCheckUpinky2 == 1 && flagCheckDowninky2 == 1 && flagCheckLeftinky2 == 1 && flagCheckUpinky2 == 1){
        srand(time(0));

        flagCheckUpinky2 = rand()%2 ;
        flagCheckRightinky2 = rand()%2 ;
        flagCheckLeftinky2 =rand()%2 ;
        flagCheckDowninky2 = rand()%2 ;
    }
}
extern Font myFont;
extern char name[11];

void DrawGame(){
    if(flagForEatPepper == 1){
        timeEatPepper-=1;
        DrawTexture(fireTexture,packManPosition.x,packManPosition.y,WHITE);
    }
    if(timeEatPepper==0){
        flagForEatPepper = 0 ;
        speed=0;
    }
    if(flagForEatGhost == 1){
        timeEat-=1;
    }

    if(timeEat == 0){
        flagForEatGhost = 0 ;
    }
    BeginDrawing();
    ClearBackground(BLACK);

    if(flagBlinkyLeft == 1 && flagForEatGhost == 0){
        DrawTexture(blinkyL2Texture,blinkyPosition.x,blinkyPosition.y,WHITE);
    }

    if(flagBlinkyRight == 1 && flagForEatGhost == 0){
        DrawTexture(blinkyR2Texture,blinkyPosition.x,blinkyPosition.y,WHITE);
    }
    if(flagBlinkyDown == 1 && flagForEatGhost == 0){
        DrawTexture(blinkyD2Texture,blinkyPosition.x,blinkyPosition.y,WHITE);
    }
    if(flagBlinkyUp == 1 && flagForEatGhost == 0){
        DrawTexture(blinkyU2Texture,blinkyPosition.x,blinkyPosition.y,WHITE);
    }

    if(flagClydeLeft == 1 && flagForEatGhost == 0){
        DrawTexture(clydeL2Texture,clydePosition.x,clydePosition.y,WHITE);
    }
    if(flagClydeRight == 1 && flagForEatGhost == 0){
        DrawTexture(clydeR2Texture,clydePosition.x,clydePosition.y,WHITE);
    }
    if(flagClydeDown == 1 && flagForEatGhost == 0){
        DrawTexture(clydeD2Texture,clydePosition.x,clydePosition.y,WHITE);
    }
    if(flagClydeUp == 1 && flagForEatGhost == 0){
        DrawTexture(clydeU2Texture,clydePosition.x,clydePosition.y,WHITE);
    }
    if(flaginkyLeft == 1 && flagForEatGhost == 0){
        DrawTexture(inkyL2Texture,inkyPosition.x,inkyPosition.y,WHITE);
    }
    if(flaginkyRight == 1 && flagForEatGhost == 0){
        DrawTexture(inkyR2Texture,inkyPosition.x,inkyPosition.y,WHITE);
    }
    if(flaginkyDown == 1 && flagForEatGhost == 0){
        DrawTexture(inkyD2Texture,inkyPosition.x,inkyPosition.y,WHITE);
    }
    if(flaginkyUp == 1 && flagForEatGhost == 0){
        DrawTexture(inkyU2Texture,inkyPosition.x,inkyPosition.y,WHITE);
    }
    if(flagpinkyLeft == 1 && flagForEatGhost == 0){
        DrawTexture(pinkyL2Texture,pinkyPosition.x,pinkyPosition.y,WHITE);
    }
    if(flagpinkyRight == 1 && flagForEatGhost == 0){
        DrawTexture(pinkyR2Texture,pinkyPosition.x,pinkyPosition.y,WHITE);
    }
    if(flagpinkyDown == 1 && flagForEatGhost == 0){
        DrawTexture(pinkyD2Texture,pinkyPosition.x,pinkyPosition.y,WHITE);
    }
    if(flagpinkyUp == 1 && flagForEatGhost == 0){
        DrawTexture(pinkyU2Texture,pinkyPosition.x,pinkyPosition.y,WHITE);
    }
    if(flagginkyLeft == 1 && flagForEatGhost == 0){
        DrawTexture(ginkyL2Texture,ginkyPosition.x,ginkyPosition.y,WHITE);
    }
    if(flagginkyRight == 1 && flagForEatGhost == 0){
        DrawTexture(ginkyR2Texture,ginkyPosition.x,ginkyPosition.y,WHITE);
    }
    if(flagginkyDown == 1 && flagForEatGhost == 0){
        DrawTexture(ginkyD2Texture,ginkyPosition.x,ginkyPosition.y,WHITE);
    }
    if(flagginkyUp == 1 && flagForEatGhost == 0){
        DrawTexture(ginkyU2Texture,ginkyPosition.x,ginkyPosition.y,WHITE);
    }
    if(degree == 12 || degree == 13) {


        if (flaginky2Left == 1 && flagForEatGhost == 0) {
            DrawTexture(inkyL2Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
        }
        if (flaginky2Right == 1 && flagForEatGhost == 0) {
            DrawTexture(inkyR2Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
        }
        if (flaginky2Down == 1 && flagForEatGhost == 0) {
            DrawTexture(inkyD2Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
        }
        if (flaginky2Up == 1 && flagForEatGhost == 0) {
            DrawTexture(inkyU2Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
        }
        if(flagpinkyLeft2 == 1 && flagForEatGhost == 0){
            DrawTexture(pinkyL2Texture,pinkyPosition2.x,pinkyPosition2.y,WHITE);
        }
        if(flagpinkyRight2 == 1 && flagForEatGhost == 0){
            DrawTexture(pinkyR2Texture,pinkyPosition2.x,pinkyPosition2.y,WHITE);
        }
        if(flagpinkyDown2 == 1 && flagForEatGhost == 0){
            DrawTexture(pinkyD2Texture,pinkyPosition2.x,pinkyPosition2.y,WHITE);
        }
        if(flagpinkyUp2 == 1 && flagForEatGhost == 0){
            DrawTexture(pinkyU2Texture,pinkyPosition2.x,pinkyPosition2.y,WHITE);
        }
    }
    if(degree==13){
        if(flagginkyLeft2 == 1 && flagForEatGhost == 0){
            DrawTexture(ginkyL2Texture,ginkyPosition2.x,ginkyPosition2.y,WHITE);
        }
        if(flagginkyRight2 == 1 && flagForEatGhost == 0){
            DrawTexture(ginkyR2Texture,ginkyPosition2.x,ginkyPosition2.y,WHITE);
        }
        if(flagginkyDown2 == 1 && flagForEatGhost == 0){
            DrawTexture(ginkyD2Texture,ginkyPosition2.x,ginkyPosition2.y,WHITE);
        }
        if(flagginkyUp2 == 1 && flagForEatGhost == 0){
            DrawTexture(ginkyU2Texture,ginkyPosition2.x,ginkyPosition2.y,WHITE);
        }
        if(flagClydeLeft2 == 1 && flagForEatGhost == 0){
            DrawTexture(clydeL2Texture,clydePosition2.x,clydePosition2.y,WHITE);
        }
        if(flagClydeRight2 == 1 && flagForEatGhost == 0){
            DrawTexture(clydeR2Texture,clydePosition2.x,clydePosition2.y,WHITE);
        }
        if(flagClydeDown2 == 1 && flagForEatGhost == 0){
            DrawTexture(clydeD2Texture,clydePosition2.x,clydePosition2.y,WHITE);
        }
        if(flagClydeUp2 == 1 && flagForEatGhost == 0){
            DrawTexture(clydeU2Texture,clydePosition2.x,clydePosition2.y,WHITE);
        }
        if(flagBlinkyLeft2 == 1 && flagForEatGhost == 0){
            DrawTexture(blinkyL2Texture,blinkyPosition2.x,blinkyPosition2.y,WHITE);
        }

        if(flagBlinkyRight2 == 1 && flagForEatGhost == 0){
            DrawTexture(blinkyR2Texture,blinkyPosition2.x,blinkyPosition2.y,WHITE);
        }
        if(flagBlinkyDown2 == 1 && flagForEatGhost == 0){
            DrawTexture(blinkyD2Texture,blinkyPosition2.x,blinkyPosition2.y,WHITE);
        }
        if(flagBlinkyUp2 == 1 && flagForEatGhost == 0){
            DrawTexture(blinkyU2Texture,blinkyPosition2.x,blinkyPosition2.y,WHITE);
        }
    }
    if(flagForEatGhost == 1){
        if(timeEat > 100) {
            DrawTexture(blue1Texture, blinkyPosition.x, blinkyPosition.y, WHITE);
            DrawTexture(blue1Texture, clydePosition.x, clydePosition.y, WHITE);
            DrawTexture(blue1Texture, inkyPosition.x, inkyPosition.y, WHITE);
            DrawTexture(blue1Texture, pinkyPosition.x, pinkyPosition.y, WHITE);
            DrawTexture(blue1Texture, ginkyPosition.x, ginkyPosition.y, WHITE);
        }
        else if(timeEat <= 100 && timeEat > 60){
            DrawTexture(whiteTexchure, blinkyPosition.x, blinkyPosition.y, WHITE);
            DrawTexture(whiteTexchure, clydePosition.x, clydePosition.y, WHITE);
            DrawTexture(whiteTexchure, inkyPosition.x, inkyPosition.y, WHITE);
            DrawTexture(whiteTexchure, pinkyPosition.x, pinkyPosition.y, WHITE);
            DrawTexture(whiteTexchure, ginkyPosition.x, ginkyPosition.y, WHITE);
        }
        else if(timeEat <= 60 && timeEat > 30){
            DrawTexture(blue1Texture, blinkyPosition.x, blinkyPosition.y, WHITE);
            DrawTexture(blue1Texture, clydePosition.x, clydePosition.y, WHITE);
            DrawTexture(blue1Texture, inkyPosition.x, inkyPosition.y, WHITE);
            DrawTexture(blue1Texture, pinkyPosition.x, pinkyPosition.y, WHITE);
            DrawTexture(blue1Texture, ginkyPosition.x, ginkyPosition.y, WHITE);
        }
        else if(timeEat <= 30 && timeEat > 15){
            DrawTexture(whiteTexchure, blinkyPosition.x, blinkyPosition.y, WHITE);
            DrawTexture(whiteTexchure, clydePosition.x, clydePosition.y, WHITE);
            DrawTexture(whiteTexchure, inkyPosition.x, inkyPosition.y, WHITE);
            DrawTexture(whiteTexchure, pinkyPosition.x, pinkyPosition.y, WHITE);
            DrawTexture(whiteTexchure, ginkyPosition.x, ginkyPosition.y, WHITE);
        }
        else{
            DrawTexture(blue1Texture, blinkyPosition.x, blinkyPosition.y, WHITE);
            DrawTexture(blue1Texture, clydePosition.x, clydePosition.y, WHITE);
            DrawTexture(blue1Texture, inkyPosition.x, inkyPosition.y, WHITE);
            DrawTexture(blue1Texture, pinkyPosition.x, pinkyPosition.y, WHITE);
            DrawTexture(blue1Texture, ginkyPosition.x, ginkyPosition.y, WHITE);
        }
        if(degree == 12 || degree == 13) {
            if(timeEat > 100) {
                DrawTexture(blue1Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
                DrawTexture(blue1Texture, pinkyPosition2.x, pinkyPosition2.y, WHITE);
            }else if(timeEat <= 100 && timeEat > 60){
                DrawTexture(whiteTexchure, inkyPosition2.x, inkyPosition2.y, WHITE);
                DrawTexture(whiteTexchure, pinkyPosition2.x, pinkyPosition2.y, WHITE);
            }
            else if(timeEat <= 60 && timeEat > 30){
                DrawTexture(blue1Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
                DrawTexture(blue1Texture, pinkyPosition2.x, pinkyPosition2.y, WHITE);
            }
            else if(timeEat <= 30 && timeEat > 15){
                DrawTexture(whiteTexchure, inkyPosition2.x, inkyPosition2.y, WHITE);
                DrawTexture(whiteTexchure, pinkyPosition2.x, pinkyPosition2.y, WHITE);
            }
            else{
                DrawTexture(blue1Texture, inkyPosition2.x, inkyPosition2.y, WHITE);
                DrawTexture(blue1Texture, pinkyPosition2.x, pinkyPosition2.y, WHITE);
            }
        }
        if(degree == 13){
            if(timeEat > 100) {
                DrawTexture(blue1Texture, ginkyPosition2.x, ginkyPosition2.y, WHITE);
                DrawTexture(blue1Texture, clydePosition2.x, clydePosition2.y, WHITE);
                DrawTexture(blue1Texture, blinkyPosition2.x, blinkyPosition2.y, WHITE);
            }
            else if(timeEat <= 100 && timeEat > 60){
                DrawTexture(whiteTexchure, ginkyPosition2.x, ginkyPosition2.y, WHITE);
                DrawTexture(whiteTexchure, clydePosition2.x, clydePosition2.y, WHITE);
                DrawTexture(whiteTexchure, blinkyPosition2.x, blinkyPosition2.y, WHITE);
            }
            else if(timeEat <= 60 && timeEat > 30){
                DrawTexture(blue1Texture, ginkyPosition2.x, ginkyPosition2.y, WHITE);
                DrawTexture(blue1Texture, clydePosition2.x, clydePosition2.y, WHITE);
                DrawTexture(blue1Texture, blinkyPosition2.x, blinkyPosition2.y, WHITE);
            }
            else if(timeEat <= 30 && timeEat > 15){
                DrawTexture(whiteTexchure, ginkyPosition2.x, ginkyPosition2.y, WHITE);
                DrawTexture(whiteTexchure, clydePosition2.x, clydePosition2.y, WHITE);
                DrawTexture(whiteTexchure, blinkyPosition2.x, blinkyPosition2.y, WHITE);
            }
            else{
                DrawTexture(blue1Texture, ginkyPosition2.x, ginkyPosition2.y, WHITE);
                DrawTexture(blue1Texture, clydePosition2.x, clydePosition2.y, WHITE);
                DrawTexture(blue1Texture, blinkyPosition2.x, blinkyPosition2.y, WHITE);
            }
        }

    }
    if(blinkyPosition.y > 960 && clydePosition.y > 960){
        map[11][15]= 2 ;
    }

    if(inkyPosition.y>400 && pinkyPosition.y>400){
        map[4][6]= 2;
    }
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 35; x++) {
            if (map[y][x] == 1) {
                //DrawRectangle(x * 80, y * 80, 80, 80, SKYBLUE);
                DrawRectangleLinesEx((Rectangle){x*80,y*80,80,80},10,DARKBLUE);
            }
            else if(map[y][x]==2){
                DrawRectangleLinesEx((Rectangle){x*80,y*80,80,80},10,DARKGREEN);
            }
            else if(map[y][x]==3){
                if((counter/10)%2 == 0 ){
                    DrawTexture(starTexture,x*80,y*80,WHITE);
                } else{
                    DrawTexture(star2Texture,x*80,y*80,WHITE);
                }

            }
            else if(map[y][x]==5){
                DrawTexture(cherryTexture,x*80,y*80,WHITE);
            }
            else if(map[y][x]==6){
                DrawTexture(appleTexture,x*80,y*80,WHITE);
            }
            else if(map[y][x]==7){
                DrawTexture(pepperTexture,x*80,y*80,WHITE);
            }
            else if(map[y][x]==8){
                DrawTexture(mushroomTexture,x*80,y*80,WHITE);
            }
        }
    }

    if((counter/10)%2 == 0 && flagForUp == 0 && flagForDown == 0 && flagForLeft == 0){
        DrawTexture(packManNarrowTexture, packManPosition.x, packManPosition.y, WHITE);
    } else if((counter/10)%2 == 1 && flagForUp == 0 && flagForDown == 0 && flagForLeft == 0){
        DrawTexture(packManClosedTexture, packManPosition.x, packManPosition.y, WHITE);
    }else if((counter/10)%2 == 0 && flagForUp == 1 && flagForDown == 0 && flagForLeft == 0){
        DrawTexture(packManUpTexture, packManPosition.x, packManPosition.y, WHITE);
    }else if((counter/10)%2 == 1 && flagForUp == 1 && flagForDown == 0 && flagForLeft == 0) {
        DrawTexture(packManClosedTexture, packManPosition.x, packManPosition.y, WHITE);
    }else if((counter/10)%2 == 0 && flagForUp == 0 && flagForDown == 1 && flagForLeft == 0){
        DrawTexture(pacKManDownTexture, packManPosition.x, packManPosition.y, WHITE);
    }else if((counter/10)%2 == 1 && flagForUp == 0 && flagForDown == 1 && flagForLeft == 0) {
        DrawTexture(packManClosedTexture, packManPosition.x, packManPosition.y, WHITE);
    }else if((counter/10)%2 == 0 && flagForUp == 0 && flagForDown == 0 && flagForLeft == 1){
        DrawTexture(packManLeftTexture, packManPosition.x, packManPosition.y, WHITE);
    }else if((counter/10)%2 == 1 && flagForUp == 0 && flagForDown == 0 && flagForLeft == 1) {
        DrawTexture(packManClosedTexture, packManPosition.x, packManPosition.y, WHITE);
    }
    DrawRectangle(0,1600,2800,50,DARKPURPLE);
    Vector2 position = { 2, 1610 };
    DrawTextEx(myFont,TextFormat("Score: %i", score),position,25,3,BLACK);
    Vector2 position2 = { 300, 1610 };
    DrawTextEx(myFont,TextFormat("name: %s", name),position2,25,3,BLACK);
    Vector2 position3 = { 700, 1610 };
    if(degree==11){
        DrawTextEx(myFont,TextFormat("level of game : Easy", name),position3,25,3,BLACK);

    }
    if(degree==12){
        DrawTextEx(myFont,TextFormat("level of game : Normal", name),position3,25,3,BLACK);

    }
    if(degree==13){
        DrawTextEx(myFont,TextFormat("level of game : Hard", name),position3,25,3,BLACK);

    }
    if(life == 3){
        DrawTexture(hearTexture,2750,1600,WHITE);
        DrawTexture(hearTexture,2700,1600,WHITE);
        DrawTexture(hearTexture,2650,1600,WHITE);
    }
    else if(life == 2){
        DrawTexture(hearTexture,2750,1600,WHITE);
        DrawTexture(hearTexture,2700,1600,WHITE);
    }
    else if(life == 1){
        DrawTexture(hearTexture,2750,1600,WHITE);
    }



    EndDrawing();
    flagForUp = 0 ;
    flagForDown = 0 ;
    flagForLeft = 0 ;
}
extern Sound gameOver;

int gameove(){
    if(life <= 0){
        life = 3 ;
         speed = 0 ;
        for(int i = 0 ; i < 20 ; i++){
            for(int j = 0 ; j < 35 ; j++){
                if(map[i][j] == 5 || map[i][j] == 6 || map[i][j] == 7 || map[i][j] == 8 || map[i][j] == 3){
                    map[i][j]=0;
                }
            }
        }
        DrawStar();
        DrawCherry();
        DrawApple();
        DrawPepper();
        DrawMushroom();
        blinkyPosition.x = 1200;
        blinkyPosition.y = 870;
        clydePosition.x = 1200 ;
        clydePosition.y = 870;
        inkyPosition.x = 200 ;
        inkyPosition.y =600;
        inkyPosition2.x =1990;
        inkyPosition2.y = 700 ;
        pinkyPosition.x =485;
        pinkyPosition.y = 200;
        ginkyPosition.x = 1400;
        ginkyPosition.y =  600;
        packManPosition.x=100;
        packManPosition.y = 100 ;
        blinkyPosition2.x = 400;
        blinkyPosition2.y = 1300;
        clydePosition2.x = 1200;
        clydePosition2.y=1500;
        pinkyPosition2.x=1400;
        pinkyPosition2.y=100;
        ginkyPosition2.x=500;
        ginkyPosition2.y=900;

        map[11][15]= 0 ;
        map[4][6]= 0 ;
        PlaySound(gameOver);
        return 0 ;
    }
    return 1;
}
