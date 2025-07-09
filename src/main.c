#include "raylib.h"
#include "../include/menu.h"
#include "../include/game.h"
#include "../include/records.h"
#include "stdlib.h"
#include "../include/gameOver.h"
#include "../include/degreeOfDifficulty.h"
#include <stdio.h>
#include <time.h>
Font myFont;
int degree;
int gameScreen = -1;
Sound scoreSound;
Sound menuSound;
Sound bumpToGhost;
Sound gameOver;
Sound bithing;
Sound backSound;
extern int score ;
extern char name[11];
int main(void) {
    const int screenWidth = 2800;
    const int screenHeight = 1650;
    InitAudioDevice();
    InitWindow(screenWidth, screenHeight, "Pack_Man");
    time_t t;
    struct tm *tm_info;
    char buffer[26];
    time(&t);
    tm_info = localtime(&t); strftime(buffer, 26, "%Y-%m-%d", tm_info);
    InitGame();
    Init3();
    init4();
    Init5();
    InitGame2();
    DrawStar();
    DrawCherry();
    DrawApple();
    DrawPepper();
    DrawMushroom();
    backSound = LoadSound("C:\\Users\\alite\\pack man project\\sounds\\resources_Audio_siren_1.mp3");
    bithing = LoadSound("C:\\Users\\alite\\pack man project\\sounds\\bithing.mp3");
    menuSound= LoadSound("C:\\Users\\alite\\pack man project\\sounds\\menuAndrecords.mp3");
    bumpToGhost = LoadSound("C:\\Users\\alite\\pack man project\\sounds\\bumpToGhost.mp3");
    gameOver = LoadSound("C:\\Users\\alite\\pack man project\\sounds\\Game-Over-Voice-Scary-Sound.mp3");
    scoreSound = LoadSound("C:\\Users\\alite\\pack man project\\sounds\\Score-points-in-game (7).mp3");
    FILE * fpRecords;
    fpRecords = fopen("C:\\Users\\alite\\pack man project\\assets\\records.txt","a");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        gameScreen = updateMenu();

        if (gameScreen == -1) {
            PauseSound(backSound);
            if (!IsSoundPlaying(menuSound)) {
                PlaySound(menuSound);
            }
            DrawMenu(0);
        }
        else if (gameScreen == 2) {
            break;
        }
        while(gameScreen == 4 && !WindowShouldClose()){
            if (!IsSoundPlaying(menuSound)) {
                PlaySound(menuSound);
            }
            DrawDegree();
            gameScreen = updateDegree();
            if(gameScreen == 11 || gameScreen == 12 || gameScreen == 13){
                degree = gameScreen;
                gameScreen = 0 ;
            }
        }
        while (gameScreen == 0 && !WindowShouldClose()) {
            PauseSound(menuSound);
            if (!IsSoundPlaying(backSound)) {
                PlaySound(backSound);
                SetSoundVolume(backSound,0.5f);
            }
            if(degree == 11){
                MovePackMan();
                DrawGame();
                MoveGhost1();
                MoveGhost2();
                MoveGhost3();
                MoveGhost4();
                MoveGhost5();
                if (gameove() == 0) {
                    gameScreen = 3;
                    break;
                }
            }
            else if(degree == 12){
                MovePackMan();
                DrawGame();
                MoveGhost1();
                MoveGhost2();
                MoveGhost3();
                MoveGhost4();
                MoveGhost5();
                MoveGhost6();
                MoveGhost7();
                if (gameove() == 0) {
                    gameScreen = 3;
                    break;
                }
            }
            else{
                MovePackMan();
                DrawGame();
                MoveGhost1();
                MoveGhost2();
                MoveGhost3();
                MoveGhost4();
                MoveGhost5();
                MoveGhost6();
                MoveGhost7();
                MoveGhost8();
                MoveGhost9();
                MoveGhost10();
                if (gameove() == 0) {
                    gameScreen = 3;
                    break;
                }
            }



        }

        while (gameScreen == 1 && !WindowShouldClose()) {
            if (!IsSoundPlaying(menuSound)) {
                PlaySound(menuSound);
            }
            DrawRecords();
            gameScreen = backToMenu2();
        }
        while (gameScreen == 3 && !WindowShouldClose()) {
            PauseSound(backSound);
            DrawGameOver();

            gameScreen = backToMenu();
            if(gameScreen == 0){
                fprintf(fpRecords,"%s %d %s\n",name,score,buffer);
                score = 0 ;
            }
        }
    }

    CloseGame();
    CloseGame2();
    close3();
    close4();
    close5();
    CloseWindow();
    CloseAudioDevice();
    fclose(fpRecords);

}
