#include "../include/menu.h"
#include "raylib.h"
#include "stdlib.h"
#include <stdio.h>
#include "../include/records.h"
#include "../include/gameOver.h"
# define MAX_INPUT_CHARS 11
int selectedOption = 0;
char name[MAX_INPUT_CHARS + 1] = "\0";
int letterCount = 0;
Rectangle textBox = { 1225, 1200, 400, 150 };
bool mouseOnText = false;
int framesCounter = 0;

int updateMenu() {
    if(IsKeyPressed(KEY_LEFT)) {
        selectedOption += 1;
        if (selectedOption > 2) {
            selectedOption = 0;
        }
    }
    if(IsKeyPressed(KEY_RIGHT)){
        selectedOption -= 1;
        if(selectedOption < 0 ){
            selectedOption = 2;
        }
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        if (mousePos.x >= 1225 && mousePos.x <= 1625 && mousePos.y >= 1000 && mousePos.y <= 1150){
            return 4;
        }
        else if (mousePos.x >= 800 && mousePos.x <= 1200 && mousePos.y >= 1000 && mousePos.y <= 1150){
            return 1;
        }
        else if (mousePos.x >= 1650 && mousePos.x <= 2050 && mousePos.y >= 1000 && mousePos.y <= 1150){
            return 2;
        }
    }
    if(IsKeyPressed(KEY_ENTER)){
        if(selectedOption == 0){
            return 4;
        }
        else if(selectedOption == 1){
            return 1;
        }
        else if(selectedOption == 2){
            return 2;
        }
    }
    return -1;
}
Texture2D backGroundTexture;
extern Font myFont;
void Init3(){
    myFont = LoadFont("C:\\Users\\alite\\pack man project\\fonts\\Lobster_1.3.otf");

    Image Background = LoadImage("C:\\Users\\alite\\pack man project\\images\\pac-man-1920-x-1200-background.jpg");
    backGroundTexture = LoadTextureFromImage((Background));
}
void close3(){
    UnloadTexture(backGroundTexture);
    UnloadFont(myFont);

}
void DrawMenu(int selectedItem) {

    Vector2 mousePos = GetMousePosition();
    BeginDrawing();

    DrawTexture(backGroundTexture,0,0,WHITE);
    DrawRectangle(1225,1000,400,150,GRAY);
    Vector2 position = { 1350, 1040 };
    DrawTextEx(myFont,"Play",position,70,3,BLACK);
    DrawRectangle(800,1000,400,150,GRAY);
    Vector2 position1 = { 855, 1030 };
    DrawTextEx(myFont,"Records",position1,70,3,BLACK);
    DrawRectangle(1650,1000,400,150,GRAY);
    Vector2 position2 = { 1780, 1040 };
    DrawTextEx(myFont,"Exit",position2,70,3,BLACK);

    if(selectedOption == 0 || (mousePos.x >= 1225 && mousePos.x <= 1625 && mousePos.y >= 1000 && mousePos.y <= 1150)){
        DrawRectangleLines(1225,1000,400,150,RED);
    }
    if(selectedOption == 1 || (mousePos.x >= 800 && mousePos.x <= 1200 && mousePos.y >= 1000 && mousePos.y <= 1150)){
        DrawRectangleLines(800,1000,400,150,RED);
    }
    if(selectedOption == 2 || (mousePos.x >= 1650 && mousePos.x <= 2050 && mousePos.y >= 1000 && mousePos.y <= 1150)){
        DrawRectangleLines(1650,1000,400,150,RED);
    }

    if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
    else mouseOnText = false;

    if (mouseOnText) {
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        int key = GetCharPressed();

        while (key > 0) {
            if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
                name[letterCount] = (char)key;
                name[letterCount+1] = '\0';
                letterCount++;
            }
            key = GetCharPressed();
            framesCounter++;
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            letterCount--;
            if (letterCount < 0) letterCount = 0;
            name[letterCount] = '\0';
        }
    } else {
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        framesCounter = 0;
    }



    DrawRectangleRec(textBox, GRAY);
    if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
    else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);
    Vector2 position3 = { (int)textBox.x + 5, (int)textBox.y + 15 };
    DrawTextEx(myFont,name, position3, 70,3, BLACK);
    Vector2 position4 = { 1100, 1160 };
    DrawTextEx(myFont,"Please enter your name without spaces", position4, 35,3, DARKGRAY);
    Vector2 position5 = { 1300, 1375 };
    DrawTextEx(myFont,TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), position5, 25,3, DARKGRAY);

    if (mouseOnText) {
        if (letterCount < MAX_INPUT_CHARS) {
            if (((framesCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 70), (int)textBox.y + 19, 70, BLACK);
        } else {
            DrawText("Press BACKSPACE to delete chars...", 1225, 1400, 20, GRAY);
        }
    }

    EndDrawing();
}
