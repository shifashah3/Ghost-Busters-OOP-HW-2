# **Ghost Busters

## **Overview**  
This project is part of **Object-Oriented Programming (OOP) Homework 2**. **Ghost Busters** is a grid-based game where the player must locate a hidden ghost by strategically clicking on blocks. The game provides hints based on the player's clicks, guiding them closer to the ghost’s location. The objective is to correctly identify the ghost's position and capture it.  

## **Game Rules**  
- The grid starts with all blocks locked.  
- Clicking on a block provides hints about the ghost’s location:  
  - 🐢 **Turtle**: The ghost is **0-1 blocks away**.  
  - 🐰 **Bunny**: The ghost is **2-3 blocks away**.  
  - 🐍 **Snake**: The ghost is **4-5 blocks away**.  
  - If the ghost is **more than 5 blocks away**, a random hint (Turtle, Bunny, or Snake) is displayed.  
- Once enough information is gathered, the player **right-clicks to bust the ghost**.  
- If the chosen block is correct, a ghost appears, and the player **wins**. Otherwise, the game is lost.  

### Requirements  
- **C++ Compiler** (**MinGW** recommended for Windows)  
- **SDL2 Libraries**:  
  - `SDL2`  
  - `SDL2_image`  
  - `SDL2_mixer`  

### How to Compile and Run  

#### Windows  
Open the project folder in **VSCode** (or any terminal) and run: 
```sh
g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
```
Then, execute the game: 
```sh
./a.exe 
```

**Note:** The provided files are configured for Windows. If using another OS, modifications may be required.
