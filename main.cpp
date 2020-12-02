#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

const int SCREEN_WIDTH = 320;
const int SCREEN_HEIGHT = 240;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *surface = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the global
SDL_Color colors = { 0, 0, 0 };

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

//Menu's finite state
int active_menu = 0;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the surface image
    surface = load_image( "surface.png" );

    //Open the font
    font = TTF_OpenFont( "lazy.ttf", 72 );

    //If there was a problem in loading the surface
    if( surface == NULL )
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void mainmenu(){

}

void logoBar_draw(){

}

void redraw(){
    colors={41,41,41};  //darkbg
    SDL_FillRect(surface,NULL,colors);
    logoBar_draw();
    //mainmenu();z
}


int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    redraw();
    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        //Get the keystates
        Uint8 *keystates = SDL_GetKeyState( NULL );

        //If up is pressed
        if( keystates[ SDLK_UP ] )
        {
        }

        //If down is pressed
        if( keystates[ SDLK_DOWN ] )
        {
 
        }

        //If left is pressed
        if( keystates[ SDLK_LEFT ] )
        {
            
        }

        //If right is pressed
        if( keystates[ SDLK_RIGHT ] )
        {
        
        }

        //If right is pressed
        if( keystates[ SDLK_LCTRL ] )
        {
        
        }

        //If right is pressed
        if( keystates[ SDLK_LALT ] )
        {
        
        }
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    //Clean up
    clean_up();

    return 0;
}
