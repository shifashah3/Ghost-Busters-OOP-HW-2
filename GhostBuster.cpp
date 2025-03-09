#include "GhostBuster.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Currently rows and columns are set to 8, however your game implementation should work for any other number
const int rows = 8, cols = 8;

// grid will store characters matrix of rows*cols size, you have to allocate memory to it in initialize function below
char* grid = NULL;

// Ghost will be placed over this location
int ghostRow, ghostCol;

// *****************************************************************************************************
// No change zone: Don't change anything until the next stars line
// *****************************************************************************************************

// Don't Change it: Screen width and height values
const int width = 1000, height = 600;

// Don't Change: This function is dealing with SDL and currently it's complete. Don't change anything here
void drawOneBlock(SDL_Renderer* renderer, SDL_Texture* texture, int row, int col, char sym){
    int xbox = width/cols;
    int ybox = height/rows;
    SDL_Rect src;
    switch(sym){
        case 'L': src = {141, 7, 104, 113}; break;
        case 'S': src = {427, 12, 129, 103}; break;
        case 'T': src = {268, 10, 130, 111}; break;
        case 'B': src = {0, 3, 114, 111}; break;
        case 'G': src = {571, 0, 123, 121}; break;
        case 'Z': src = {571, 0, 25, 25}; break;
        case 'F': src = {707, 16, 90, 86}; break;
    }
    SDL_Rect mov = { xbox*col, ybox*row, xbox - 10, ybox - 10};
    SDL_RenderCopy(renderer, texture, &src, &mov);
}

void drawBlocks(SDL_Renderer* renderer, SDL_Texture* texture){
    // Call drawOneBlock for all of the blocks of grid
    // for example to draw a snake over block (3, 5) you call it this way:
    // drawOneBlock(renderer, texture, 3, 5, 'S');
    if(grid == NULL) return;
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            drawOneBlock(renderer, texture, i, j, grid[i*cols+j]);
        }   
    }
}

// *****************************************************************************************************
// No change zone ends here
// *****************************************************************************************************



// To Do zone: 

bool ended = false;

void initialize(){
    // Create memory for grid here, it should be one dimensional array.
    // The memory should be rows*cols size.
    // Initialize entire grid with 'L' so that locks are displayed all over
    // generate two random numbers and store in ghostRow and ghostCol variables
    
    const int arr_size=rows*cols;
    grid = new char[arr_size];
    for (int i = 0; i < arr_size; i++) 
    {
        grid[i] = 'L';
    }

    //generating random numners for ghostrow and ghostcol
    srand(time(0));
    ghostRow=rand() % 8;
    ghostCol=rand() % 8;
}

void huntGhost(int x, int y){
    // this function is called every time you click on the screen
    // x, y are screen coordinates, you need to identify the block from these coordinates and using screen width and height values
    // each block size is width/cols x height/rows
    // according to game rules you need to put appropriate character in the grid for that block
    // Place 'S' to draw a snake
    // place 'T' to draw a turtle
    // place 'B' to draw a bunny


    if (ended)
    {
        return;
    }
    const int block_width = width/cols;
    const int block_height = height/rows;

    // finding the position of the user
    int user_x = x/block_width;
    int user_y = y/block_height;

    int distance_from_ghost = sqrt((pow(ghostRow - user_x, 2)) + (pow(ghostCol - user_y, 2)));

    // finding the index of user in grid to replace it 
    int idx = user_y*cols + user_x;
 
    if (distance_from_ghost==0 || distance_from_ghost==1)
    { 
        grid[idx] = 'T';
    }
    else if (distance_from_ghost==2 || distance_from_ghost==3)
    {
        grid[idx] = 'B';
    }
    else if (distance_from_ghost==4 || distance_from_ghost==5)
    {
        grid[idx] = 'S';
    }
    else if (distance_from_ghost>5)
    {
        // generating a random num to assign T, B or S if distance is >5
        srand(time(0));
        int num = rand()%3;
        if (num==0)
        {
            grid[idx] = 'T';
        }
        else if (num==1)
        {
            grid[idx] = 'B';
        }
        else
        {
            grid[idx] = 'S';
        }
    }
}

void bustGhost(int x, int y){
    // this function is called when you right-click
    // it should work only one time, and you decide whether game is won or failed
    // once the game is won/failed, nothing in game should change anymore.
    // according to game rules you need to put appropriate character in the grid for that block
    // place 'S' to draw snake, when the game is won
    // place 'F' to draw failed symbol, when the game is failed
    if (ended)
    {
        return;
    }
    const int block_width = width/cols;
    const int block_height = height/rows;

    // finding the position of the user
    int user_x = x/block_width;
    int user_y = y/block_height;
    int distance_from_ghost = sqrt(pow(ghostRow - user_x, 2) + pow(ghostCol - user_y, 2));

    // finding the index of user in grid to replace it 
    int idx = user_y*cols + user_x;
   
    if (distance_from_ghost==0)
    {
        grid[idx] = 'G';
    }
    else
    {
        grid[idx] = 'F';
    }

    //ending the game on one right click
    ended = true;
    return;
}

void quitGhostBuster()
{
    // delete the grid here
    delete[] grid;
    grid = nullptr;

}