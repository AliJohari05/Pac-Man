#include <string.h>
#include "../include/records.h"
#include "raylib.h"
#include "stdlib.h"
#include "../include/menu.h"
#include <stdio.h>
Texture2D backt2;
extern Font myFont;
void Init5(){
    Image back = LoadImage("C:\\Users\\alite\\pack man project\\images\\degreeBack.jpg");
    backt2 = LoadTextureFromImage(back);
}
void close5(){
    UnloadTexture(backt2);
}
int selectedDegree = 0;

int updateDegree() {
    if(IsKeyPressed(KEY_DOWN)) {
        selectedDegree += 1;
        if (selectedDegree > 2) {
            selectedDegree = 0;
        }
    }
    if(IsKeyPressed(KEY_UP)){
        selectedDegree -= 1;
        if(selectedDegree < 0 ){
            selectedDegree = 2;
        }
    }
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        if (mousePos.x >= 800 && mousePos.x <= 1300 && mousePos.y >= 250 && mousePos.y <= 500){
            return 11;
        }
        else if (mousePos.x >= 1500 && mousePos.x <= 2000 && mousePos.y >= 800 && mousePos.y <= 1050){
            return 12;
        }
        else if (mousePos.x >= 800 && mousePos.x <= 1300 && mousePos.y >= 1300 && mousePos.y <= 1550){
            return 13;
        }
    }
    if(IsKeyPressed(KEY_ENTER)){
        if(selectedDegree == 0){
            return 11;
        }
        else if(selectedDegree == 1){
            return 12;
        }
        else if(selectedDegree == 2){
            return 13;
        }
    }
    return 4;
}
void DrawDegree(){
    Vector2 mousePos = GetMousePosition();
    BeginDrawing();
    DrawTexture(backt2,0,0,WHITE);
    DrawRectangle(800,250,500,250,SKYBLUE);
    Vector2 position = { 935, 350 };
    DrawTextEx(myFont,"Easy",position,110,3,BLACK);
    DrawRectangle(1500,800,500,250,YELLOW);
    Vector2 position1 = { 1600, 900 };
    DrawTextEx(myFont,"Normal",position1,110,3,BLACK);
    DrawRectangle(800,1300,500,250,RED);
    Vector2 position2 = { 935, 1400 };
    DrawTextEx(myFont,"Hard",position2,110,3,BLACK);
    if(selectedDegree == 0 || (mousePos.x >= 800 && mousePos.x <= 1300 && mousePos.y >= 250 && mousePos.y <= 500)){
        DrawRectangleLinesEx((Rectangle){800,250,500,250},10,BLACK);
    }
    if(selectedDegree == 1 || (mousePos.x >= 1500 && mousePos.x <= 2000 && mousePos.y >= 800 && mousePos.y <= 1050)){
        DrawRectangleLinesEx((Rectangle){1500,800,500,250},10,BLACK);
    }
    if(selectedDegree == 2 || (mousePos.x >= 800 && mousePos.x <= 1300 && mousePos.y >=1300  && mousePos.y <= 1550)){
        DrawRectangleLinesEx((Rectangle){800,1300,500,250},10,BLACK);
    }
    EndDrawing();

}