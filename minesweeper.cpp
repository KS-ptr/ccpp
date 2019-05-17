#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<time.h>
#define WIDTH 16
#define HEIGHT 16
#define BOMBS 40
using namespace std;

bool game = true;

void open(int, int);    //マスを開く関数, if(block.neighbor == 0)で再帰的に呼び出す

int countneighbor(int, int);    //周囲の爆弾マスをカウントする(レンジオーバーしたときreturnする)

struct msg{
    char header[128] = "  | 0 1 2 3 4 5 6 7 8 9 a b c d e f\n--+---------------------------------\n";
    char alreadyopen[128] = "already opened block. Please input again.\n";
    char input[128] = "where to open?(input x-ax, y-ax)\n>>";
    char over[32] = "------GAME OVER------\n";
    char clear[32] = "/\\/\\/\\CONGRATS!\\/\\/\\/\n";
}sysmsg;

class block
{
public:
    int neighbor;   //隣接する爆弾マスの数 <- state==trueの場合coutでコンソールに表示する
    bool state;     //まだ開いていない->false | 開いている->true
    bool isbomb;    //爆弾マス->true | 普通のマス->false
};

void initialize(block[HEIGHT][WIDTH], int, int);        //盤面の初期化

block field[HEIGHT][WIDTH];     //盤面そのもの

int count_opened = 0;       //空いたマスをカウント

int main()
{
    int x, y, ix, iy;
    cout << sysmsg.header;
    for(int i = 0; i < HEIGHT; i++)
    {
        cout << std::hex << i << " |";
        for(int j = 0; j < WIDTH; j++)
        {
            field[i][j].state = false;
            cout << " _";
        }
        cout << "\n";
    }
    cout << sysmsg.input;
    cin >> std::hex >> ix >> std::hex >> iy;
    initialize(field, ix, iy);
    open(ix, iy);
    if(count_opened == (HEIGHT * WIDTH - BOMBS))
        game = false;

    while(game){
        cout << sysmsg.header;
        for(int i = 0; i < HEIGHT; i++)
        {
            cout << std::hex << i << " |";
            for(int j = 0; j < WIDTH; j++)
            {
                if(field[i][j].state)
                    cout << " " << field[i][j].neighbor;
                else
                    cout << " _";
            }
            cout << "\n";
        }
        cout << sysmsg.input;
        cin >> std::hex >> x >> std::hex >> y;
        if(field[y][x].state)
        {
            cout << sysmsg.alreadyopen;
            continue;
        }
        else
            open(x, y);
        if(count_opened == (HEIGHT * WIDTH - BOMBS))
            game = false;
    }

    if(!game) 
    {
        if(count_opened == (HEIGHT * WIDTH - BOMBS))
            cout << sysmsg.clear;
        cout << sysmsg.header;
        for(int i = 0; i < HEIGHT; i++)
        {
            cout << std::hex << i << " |";
            for(int j = 0; j < WIDTH; j++)
            {
                if(!field[i][j].isbomb)
                    cout << " " << field[i][j].neighbor;
                else
                    cout << " *";
            }
            cout << "\n";
        }
    }

    return 0;
}

//盤面の初期化を行う関数
void initialize(block[HEIGHT][WIDTH], int x, int y)
{
    srand((unsigned int)time(NULL));
    vector<int> bombv;
    vector<int> notbombv;

    if(y == 0)
    {
        if(x == 0)
            notbombv = {0, 1, WIDTH, WIDTH+1};
        else if(x == WIDTH-1)
            notbombv = {WIDTH-2, WIDTH-1, WIDTH*2-2, WIDTH*2-1};
        else
            notbombv = {x-1, x, x+1, x+WIDTH-1, x+WIDTH, x+WIDTH+1};
    }

    else if(y == HEIGHT-1)
    {
        if(x == 0)
            notbombv = {WIDTH*(HEIGHT-2), WIDTH*(HEIGHT-2)+1, WIDTH*(HEIGHT-1),  WIDTH*(HEIGHT-1)+1};
        else if(x == WIDTH-1)
            notbombv = {WIDTH*(HEIGHT-1)-2, WIDTH*(HEIGHT-1)-1, WIDTH*HEIGHT-2, WIDTH*HEIGHT-1};
        else
            notbombv = {x+WIDTH*(HEIGHT-2)-1, x+WIDTH*(HEIGHT-2), x+WIDTH*(HEIGHT-2)+1, x+WIDTH*(HEIGHT-1)-1, x+WIDTH*(HEIGHT-1), x+WIDTH*(HEIGHT-1)+1};
    }

    else
    {
        if(x == 0)
            notbombv = {(y-1)*HEIGHT+x, (y-1)*HEIGHT+x+1, y*HEIGHT+x, y*HEIGHT+x+1, (y+1)*HEIGHT+x, (y+1)*HEIGHT+x+1};
        else if(x==WIDTH-1)
            notbombv = {(y-1)*HEIGHT+x-1, (y-1)*HEIGHT+x, y*HEIGHT+x-1, y*HEIGHT+x, (y+1)*HEIGHT+x-1, (y+1)*HEIGHT+x};
        else
            notbombv = {(y-1)*HEIGHT+x-1, (y-1)*HEIGHT+x, (y-1)*HEIGHT+x+1, y*HEIGHT+x-1, y*HEIGHT+x, y*HEIGHT+x+1,(y+1)*HEIGHT+x-1, (y+1)*HEIGHT+x, (y+1)*HEIGHT+x+1};
    }

    for(int i = 0; bombv.size() != BOMBS; i++)
    {
        int a = rand() / (1.0 + RAND_MAX) * (WIDTH * HEIGHT);
        auto itr = find(bombv.begin(), bombv.end(), a);
        auto itrn = find(notbombv.begin(), notbombv.end(), a);
        if(itr == bombv.end() && itrn == notbombv.end())
            bombv.push_back(a);
    }

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            auto itr = find(bombv.begin(), bombv.end(), 16 * i + j);
            if(itr != bombv.end())
                field[i][j].isbomb = true;
            else
                field[i][j].isbomb = false;
        }
    }

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(int dy = -1; dy <= 1; dy++)
            {
                for(int dx = -1; dx <= 1; dx++)
                {
                    if(dx != 0 || dy != 0)
                        field[i][j].neighbor += countneighbor(j + dx, i + dy);
                }
            }
        }
    }

    return;
}

void open(int x_c, int y_c)
{   
    if(x_c < 0 || x_c >= WIDTH || y_c < 0 || y_c >= HEIGHT || field[y_c][x_c].state)
        return;

    field[y_c][x_c].state = true;
    count_opened += 1;

    if(field[y_c][x_c].isbomb)
    {
        cout << sysmsg.over;
        game = false;
        return;
    }

    if(field[y_c][x_c].neighbor == 0)
    {
        open(x_c-1, y_c-1);
        open(x_c-1, y_c);
        open(x_c-1, y_c+1);
        open(x_c, y_c-1);
        open(x_c, y_c+1);
        open(x_c+1, y_c-1);
        open(x_c+1, y_c);
        open(x_c+1, y_c+1);
    }
    return;
}

int countneighbor(int x_s, int y_s)
{
    if(x_s < 0 || x_s >= WIDTH || y_s < 0 || y_s >= HEIGHT)
        return 0;
    if(field[y_s][x_s].isbomb)
        return 1;
    else
        return 0;
}
