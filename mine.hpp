#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

using std::cout;
using std::vector;

namespace settings
{
    struct msg
    {
        const char difficulty[64] = "difficulty?\n1:easy, 2:medium, 3:hard\n";
        const char again[32] = "invalid input. Try again.\n";
        const char alreadyopen[64] = "already opened block. Please input again.\n";
        const char rangeover[64] = "out of bounds. Please input again.\n";
        const char input[64] = "where to open?(input x-ax, y-ax)\n>>";
        const char over[32] = "------GAME OVER------\n";
        const char clear[32] = "/\\/\\/CONGRATS!\\/\\/\\\n";
        void coutheader(int width)
        {
            cout << "   |";
            for (int i = 0; i < width; i++)
            {
                cout << std::setw(3) << std::right << i;
            }
            cout << "\n---+";
            for (int i = 0; i < width; i++)
            {
                cout << "---";
            }
            cout << "-\n";
            return;
        };
        void coutfooter(int width)
        {
            cout << "---+";
            for (int i = 0; i < width; i++)
            {
                cout << "---";
            }
            cout << "-\n";
        }
    } sysmsg;

    enum difficulty
    {
        easy = 0,
        medium,
        hard
    };

    const int height[3] = {10, 16, 20};
    const int width[3] = {10, 16, 20};
    const int bombs[3] = {14, 40, 75};

    class mine
    {
        struct block
        {
            int neighbor = 0;
            bool state = false;
            bool isbomb = false;
        };
        int opend_blocks = 0;

    public:
        int mheight, mwidth, mbombs;
        block **field = new block *[mheight];

        //constructor => decides size of field, numbers of bombs
        mine(int height, int width, int bombs)
        {
            mheight = height;
            mwidth = width;
            mbombs = bombs;
            for (int i = 0; i < mheight; i++)
                field[i] = new block[mwidth];
        }

        //return value : -1 => invalid input, -2 => already opened, -3 => gameover, 0 => on game, 1 => clear
        //calls initialize(init_y, init_x) when first input occurs
        //calls itself recursively if field[y][x].neighbor == 0
        int open(int y, int x)
        {
            if (y < 0 || y >= mheight || x < 0 || x >= mwidth)
                return -1;
            if (field[y][x].state)
                return -2;

            if (opend_blocks == 0)
                initialize(y, x);

            field[y][x].state = true;
            opend_blocks += 1;

            if (field[y][x].isbomb)
                return -3;

            if (field[y][x].neighbor == 0)
            {
                open(y - 1, x - 1);
                open(y - 1, x);
                open(y - 1, x + 1);
                open(y, x - 1);
                open(y, x + 1);
                open(y + 1, x - 1);
                open(y + 1, x);
                open(y + 1, x + 1);
            }
            if (opend_blocks == mheight * mwidth - mbombs)
                return 1;
            else
                return 0;
        }

        //displays field on console
        void coutfield()
        {
            sysmsg.coutheader(mwidth);
            for (int i = 0; i < mheight; i++)
            {
                cout << std::setw(3) << std::right << i << "|";
                for (int j = 0; j < mwidth; j++)
                {
                    if (field[i][j].state)
                        cout << "  " << field[i][j].neighbor;
                    else
                        cout << "  -";
                }
                cout << "\n";
            }
            sysmsg.coutfooter(mwidth);
        }

        //displays field on console when the game is over
        void coutover()
        {
            sysmsg.coutheader(mwidth);
            for (int i = 0; i < mheight; i++)
            {
                cout << std::setw(3) << std::right << i << "|";
                for (int j = 0; j < mwidth; j++)
                {
                    if (!field[i][j].isbomb)
                        cout << "  " << field[i][j].neighbor;
                    else
                        cout << "  *";
                }
                cout << "\n";
            }
            sysmsg.coutfooter(mwidth);
        }

    private:
        //decides field informations, called by open(y, x) on first input
        void initialize(int y, int x)
        {
            srand((unsigned int)time(NULL));
            vector<int> bombv;
            vector<int> nbombv = notbombv(y, x);

            for (int i = 0; bombv.size() != mbombs; i++)
            {
                int a = rand() / (1.0 + RAND_MAX) * (mheight * mwidth);
                auto itr = find(bombv.begin(), bombv.end(), a);
                auto nitr = find(nbombv.begin(), nbombv.end(), a);
                if (itr == bombv.end() && nitr == nbombv.end())
                    bombv.push_back(a);
            }

            for (int i = 0; i < mheight; i++)
            {
                for (int j = 0; j < mwidth; j++)
                {
                    auto bitr = find(bombv.begin(), bombv.end(), i * mwidth + j);
                    if (bitr != bombv.end())
                        field[i][j].isbomb = true;
                    else
                        field[i][j].isbomb = false;
                }
            }

            for (int i = 0; i < mheight; i++)
            {
                for (int j = 0; j < mwidth; j++)
                {
                    field[i][j].neighbor = countneighbor(i, j);
                }
            }

            return;
        }

        //determines which block is NOT bomb by first input, called by initialize(y, x)
        vector<int> notbombv(int y, int x)
        {
            if (y == 0)
            {
                if (x == 0)
                    return {0, 1, mwidth, mwidth + 1};
                else if (x == mwidth - 1)
                    return {mwidth - 2, mwidth - 1, mwidth * 2 - 2, mwidth * 2 - 1};
                else
                    return {x - 1, x, x + 1, mwidth + x - 1, mwidth + x, mwidth + x + 1};
            }
            else if (y == mheight - 1)
            {
                if (x == 0)
                    return {mwidth * (mheight - 2), mwidth * (mheight - 2) + 1, mwidth * (mheight - 1), mwidth * (mheight - 1) + 1};
                else if (x == mwidth - 1)
                    return {mwidth * (mheight - 1) - 2, mwidth * (mheight - 1) - 1, mwidth * mheight - 2, mwidth * mheight - 1};
                else
                    return {x + mwidth * (mheight - 2) - 1, x + mwidth * (mheight - 2), x + mwidth * (mheight - 2) + 1, x + mwidth * (mheight - 1) - 1, x + mwidth * (mheight - 1), x + mwidth * (mheight - 1) + 1};
            }
            else
            {
                if (x == 0)
                    return {(y - 1) * mwidth, (y - 1) * mwidth + 1, y * mwidth, y * mwidth + 1, (y + 1) * mwidth, (y + 1) * mwidth + 1};
                else if (x == mwidth - 1)
                    return {(y - 1) * mwidth + x - 1, (y - 1) * mwidth + x, y * mwidth + x - 1, y * mwidth + x, (y + 1) * mwidth + x - 1, (y + 1) * mwidth + x};
                else
                    return {(y - 1) * mwidth + x - 1, (y - 1) * mwidth + x, (y - 1) * mwidth + x + 1, y * mwidth + x - 1, y * mwidth + x, y * mwidth + x + 1, (y + 1) * mwidth + x - 1, (y + 1) * mwidth + x, (y + 1) * mwidth + x + 1};
            }
        }

        //counts each block's neighboring bombs called by initialize(y, x)
        int countneighbor(int y, int x)
        {
            int counter = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (y + i < 0 || y + i >= mheight || x + j < 0 || x + j >= mwidth)
                    {}
                    else if (field[y + i][x + j].isbomb)
                        counter += 1;
                    else
                    {}
                }
            }
            return counter;
        }
    };
}