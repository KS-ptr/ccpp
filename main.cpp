#include "mine.hpp"

using namespace settings;
using std::cin; using std::cout;

int main()
{
    msg sysmsg;
    bool game = true;
    int cd, ch, cw, cb; //difficulty, height, width, numbers of bombs

    do{
        cout << sysmsg.difficulty;
        cin >> cd;
        
         switch(cd-1)
        {
            case difficulty::easy:
                ch = height[easy];
                cw = width[easy];
                cb = bombs[easy];
                break;
            case difficulty::medium:
                ch = height[medium];
                cw = width[medium];
                cb = bombs[medium];
                break;
            case difficulty::hard:
                ch = height[hard];
                cw = width[hard];
                cb = bombs[hard];
                break;
            default:
                cout << sysmsg.again;
                break;
        } 
     }while(cd-1 < easy || cd-1 > hard);
    cout << ch << " * " << cw << "," << cb << " bombs\n";
    mine cmine(ch, cw, cb);
    
    while(game)
    {
        int x, y;
        cmine.coutfield();
        cout << sysmsg.input;
        cin >> x >> y;
        switch(cmine.open(y, x))
        {
            case out_of_bounds:
                cout << sysmsg.out_of_bounds;
                break;
            case already_open:
                cout << sysmsg.already_open;
                break;
            case game_over:
                cout << sysmsg.over;
                game = false;
                cmine.coutover();
                break;
            case on_game:
                break;
            case clear:
                cout << sysmsg.clear;
                game = false;
                cmine.coutover();
                break;
            default:
                return -1;
        }
    }
    return 0;
}