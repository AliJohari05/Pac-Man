#include <string.h>
#include "../include/records.h"
#include "raylib.h"
#include "stdlib.h"
#include "../include/menu.h"
#include <stdio.h>
Texture2D backt;
#define MAX_LINES 500
#define MAX_NAME_LENGTH 30
extern Font myFont;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    char date[11];
} Record;

int compareScores(const void *a, const void *b) {
    Record *recordA = (Record *)a;
    Record *recordB = (Record *)b;
    return recordB->score - recordA->score;
}

void readFile( Record records[], int *count) {
    FILE *file = fopen("C:\\Users\\alite\\pack man project\\records.txt", "r");
    if (file == NULL) {
        printf("Error opening file ");
        return;
    }

    char line[256];
    *count = 0;
    while (fgets(line, sizeof(line), file) && *count < MAX_LINES) {
        if (*count == 0) {
            (*count)++;
            continue;
        }
        sscanf(line, "%s %d %s", records[*count - 1].name, &records[*count - 1].score, records[*count - 1].date);
        (*count)++;
    }
    fclose(file);
    (*count)--;
}






void init4(){
    Image back = LoadImage("C:\\Users\\alite\\pack man project\\images\\Picture1.png");
    backt = LoadTextureFromImage(back);
}
void close4(){
    UnloadTexture(backt);
}
int backToMenu2(){
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePos = GetMousePosition();
        if (mousePos.x >= 0 && mousePos.x <= 150 && mousePos.y >= 0 && mousePos.y <= 100) {
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
}
void DrawRecords(){
    Vector2 mousePos = GetMousePosition();
    Record records[MAX_LINES];
    int recordCount = 0;

    readFile( records, &recordCount);

    // Sort records by score in descending order
    qsort(records, recordCount, sizeof(Record), compareScores);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(backt,0,0,WHITE);
    DrawRectangle(0,0,150,100,GRAY);
    Vector2 position = {35,35};
    DrawTextEx(myFont,"Menu",position,40,3,BLACK);
    if( (mousePos.x >= 0 && mousePos.x <= 150 && mousePos.y >= 0 && mousePos.y <= 100)){
        DrawRectangleLines(0,0,150,100,RED);
    }
    for (int i = 0; i < recordCount && i < 10; i++) {
        Vector2 position1 = {850, 450  + i*110};

        DrawTextEx(myFont,TextFormat(" %s", records[i].name), position1, 70,3, BLACK);
        Vector2 position2 = {1300, 450  + i*110};

        DrawTextEx(myFont,TextFormat(" %d", records[i].score), position2, 70,3, BLACK);
        Vector2 position3 = {1600, 450  + i*110};
        DrawTextEx(myFont,TextFormat(" %s",records[i].date), position3, 70,3, BLACK);


    }
    EndDrawing();
}
