#include "../include/gameOver.h"
#include "../include/game.h"
#include "../include/menu.h"
#include "raylib.h"
#include "stdlib.h"
#include "../include/menu.h"
extern  int score;
extern char name[11];
extern Font myFont;
Texture2D gameOverTexture;

void InitGame2(){
    Image gameOver = LoadImage("C:\\Users\\alite\\pack man project\\gameOver.jpg");
    gameOverTexture = LoadTextureFromImage(gameOver);
}
void CloseGame2(){
    UnloadTexture(gameOverTexture);
}
int backToMenu(){
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        if (mousePos.x >= 0 && mousePos.x <= 150 && mousePos.y >= 0 && mousePos.y <= 100) {
            return 0;
        }
        else{
            return 3;
        }
    }
    else{
        return 3;
    }
}
void DrawGameOver(){
    Vector2 mousePos = GetMousePosition();

    BeginDrawing();
    Vector2 position1 = {1700,1250};
    DrawTexture(gameOverTexture,0,0,WHITE);
    DrawTextEx(myFont,TextFormat("Score : %d",score),position1,90,3,WHITE);
    Vector2 position2 = {550,1250};

    DrawTextEx(myFont,TextFormat("name : %s",name),position2,90,3,WHITE);
    DrawRectangle(0,0,150,100,GRAY);
    Vector2 position = {35,35};
    DrawTextEx(myFont,"Menu",position,40,3,BLACK);
    if( (mousePos.x >= 0 && mousePos.x <= 150 && mousePos.y >= 0 && mousePos.y <= 100)){
        DrawRectangleLines(0,0,150,100,RED);
    }

    EndDrawing();
}
