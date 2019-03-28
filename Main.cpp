#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* Window = NULL;

SDL_GLContext glContext;

float paddleSizeX = 10;
float paddleSizeY = 100;

float playerX = 40;
float playerY = 480/2;

float cpuX = 640-40;
float cpuY = 480/2;
float cpuMoveSpeed = 1.5f;

float ballX = 640/2;
float ballY = 480/2;
float ballXV = 2.f;
float ballYV = 2.f;
float ballSize = 20;

float oldtime, newtime, delta = 0;

void init(){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 1);

    Window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    glContext = SDL_GL_CreateContext(Window);

    SDL_GL_SetSwapInterval(1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glOrtho(0, 640, 480, 0, 0, 1000);

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f);

    
}

void handleKeys( unsigned char key, int x, int y){
    if( key == 'q') {
        SDL_GL_SetSwapInterval(0);
    }
}

void update(){

}

void render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Draw Player
    glBegin( GL_QUADS );
		glVertex2f( playerX-paddleSizeX/2.f, playerY-paddleSizeY/2.f );
		glVertex2f( playerX+paddleSizeX/2.f, playerY-paddleSizeY/2.f );
		glVertex2f( playerX+paddleSizeX/2.f, playerY+paddleSizeY/2.f );
		glVertex2f( playerX-paddleSizeX/2.f, playerY+paddleSizeY/2.f );
	glEnd();

    //Draw CPU
    glBegin( GL_QUADS );
		glVertex2f( cpuX-paddleSizeX/2.f, cpuY-paddleSizeY/2.f );
		glVertex2f( cpuX+paddleSizeX/2.f, cpuY-paddleSizeY/2.f );
		glVertex2f( cpuX+paddleSizeX/2.f, cpuY+paddleSizeY/2.f );
		glVertex2f( cpuX-paddleSizeX/2.f, cpuY+paddleSizeY/2.f );
	glEnd();

    //Draw Ball
    glBegin( GL_QUADS );
		glVertex2f( ballX-ballSize/2.f, ballY-ballSize/2.f );
		glVertex2f( ballX+ballSize/2.f, ballY-ballSize/2.f );
		glVertex2f( ballX+ballSize/2.f, ballY+ballSize/2.f );
		glVertex2f( ballX-ballSize/2.f, ballY+ballSize/2.f );
	glEnd();
}

void close(){
    SDL_DestroyWindow(Window);
    Window = NULL;

    SDL_Quit();
}

int main(int argc, char* args[]){
    init();

    bool quit = false;

    SDL_Event e;

    SDL_StartTextInput();

    while(!quit){

        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            } else if(e.type == SDL_TEXTINPUT){
                int x = 0, y = 0;
                SDL_GetMouseState( &x, &y);
                handleKeys(e.text.text[0], x, y);
            }
        }

        //Mouse input
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        playerY = mouseY;

        //Ball velocity
        ballX = ballX+ballXV*delta;
        ballY = ballY+ballYV*delta;

        //Ball and wall collision
        if(ballY > SCREEN_HEIGHT-ballSize/2.f){
            ballYV = -2.f;
        }
        if(ballY < 0+ballSize/2.f){
            ballYV = 2.f;
        }
        if(ballX > SCREEN_WIDTH-ballSize/2.f || ballX < 0+ballSize/2.f){
            ballXV = -ballXV;
        }

        //Paddle and ball collision
        if(ballY > playerY-paddleSizeY/2.f && ballY < playerY+paddleSizeY/2.f && ballX-ballSize/2.f < playerX+paddleSizeX/2.f){
            ballXV = 2.f;
        }
        if(ballY > cpuY-paddleSizeY/2.f && ballY < cpuY+paddleSizeY/2.f && ballX+ballSize/2.f > cpuX-paddleSizeX/2.f){
            ballXV = -2.f;
        }

        //CPU AI
        if(ballY > cpuY){
            cpuY = cpuY+cpuMoveSpeed*delta;
        }
        if(ballY < cpuY){
            cpuY = cpuY-cpuMoveSpeed*delta;
        }

        std::cout << delta << std::endl;

        //Delta calculations
        oldtime = newtime;
        newtime = SDL_GetTicks();
        delta = (newtime - oldtime)/7;

        render();

        //Refresh window
        SDL_GL_SwapWindow(Window);
    }

    SDL_StopTextInput();

    close();

    return 0;
}