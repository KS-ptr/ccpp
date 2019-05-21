#include "mine.hpp"
#include<iostream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <time.h>
using std::cout;
using settings::open_value;

mine::mine(int height, int width, int bombs)
{   
    opened_blocks = 0;
    mheight = height;
    mwidth = width;
    mbombs = bombs;
    field = new block*[mheight];
    for(int i = 0; i < mheight; i++)
    {
        field[i] = new block[mwidth];
    }
};

settings::open_value mine::open(int y, int x)
{
    if (y < 0 || y >= mheight || x < 0 || x >= mwidth)
        return open_value::out_of_bounds;
    if (field[y][x].state)
        return open_value::already_open;
    if (field[y][x].isbomb)
        return open_value::game_over;
    if (opened_blocks == 0)
        initialize(y, x);
    field[y][x].state = true;
    opened_blocks += 1;
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
    if (opened_blocks == mheight * mwidth - mbombs)
        return open_value::clear;
    else
        return open_value::on_game;
}

void mine::coutfield()
{
    coutheader(mwidth);
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
    coutfooter(mwidth);
}

void mine::coutover()
{
    coutheader(mwidth);
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
    coutfooter(mwidth);
}

void mine::coutheader(int width)
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
}

void mine::coutfooter(int width)
{
    cout << "---+";
    for (int i = 0; i < width; i++)
    {
        cout << "---";
    }
    cout << "-\n";
}

void mine::initialize(int y, int x)
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

vector<int> mine::notbombv(int y, int x)
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

int mine::countneighbor(int y, int x)
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