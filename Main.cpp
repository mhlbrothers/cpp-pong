#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* Window = NULL;

SDL_GLContext glContext;

bool renderQuad = true;

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

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f);  
}

void handleKeys( unsigned char key, int x, int y){
    if( key == 'q') {
        renderQuad = !renderQuad;
    }
}

void update(){

}

void render(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(renderQuad){
        glBegin( GL_QUADS );
			glVertex2f( -0.5f, -0.5f );
			glVertex2f( 0.5f, -0.5f );
			glVertex2f( 0.5f, 0.5f );
			glVertex2f( -0.5f, 0.5f );
		glEnd();
    }
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

        render();

        SDL_GL_SwapWindow(Window);
    }

    SDL_StopTextInput();

    close();

    return 0;
}