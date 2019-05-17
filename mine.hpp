#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

using std::vector;

namespace settings
{
    struct msg
    {
        const char difficulty[64] = "difficulty?\n1:easy, 2:medium, 3:hard\n";
        const char again[32] = "invalid input. Try again.\n";
        const char already_open[64] = "already opened block. Please input again.\n";
        const char out_of_bounds[64] = "out of bounds. Please input again.\n";
        const char input[64] = "where to open?(input x-ax, y-ax)\n>>";
        const char over[32] = "------GAME OVER------\n";
        const char clear[32] = "*****CONGRATS!*****\n";
    };

    enum difficulty
    {
        easy = 0,
        medium,
        hard
    };

    enum open_value
    {
        out_of_bounds,
        already_open,
        game_over,
        on_game,
        clear
    };

    const int height[3] = {10, 16, 20};
    const int width[3] = {10, 16, 20};
    const int bombs[3] = {14, 40, 75};
};

class mine
{
    struct block
    {
        int neighbor = 0;
        bool state = false;
        bool isbomb = false;
    };

    block **field;
    
    int opend_blocks;

public:
    //constructor => decides size of field, numbers of bombs
    mine(int height, int width, int bombs);

    //calls initialize(init_y, init_x) when first input occurs
    //calls itself recursively if field[y][x].neighbor == 0
    settings::open_value open(int, int);

    //displays field on console
    void coutfield();

    //displays field on console when the game is over
    void coutover();

private:
    int mheight, mwidth, mbombs;

    //decides field informations, called by open(y, x) on first input
    void initialize(int, int);

    //determines which block is NOT bomb by first input, called by initialize(y, x)
    vector<int> notbombv(int, int);

    //counts each block's neighboring bombs called by initialize(y, x)
    int countneighbor(int, int);

    //output header, called by coutfield
    void coutheader(int);

    //output footer, called by coutfield
    void coutfooter(int);
};
