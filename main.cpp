#include "mine.hpp"

using std::cin;
using namespace settings;

int main()
{
    bool game = true;
    int cd, ch, cw, cb; //difficulty, height, width, numbers of bombs

    do{
        cout << sysmsg.difficulty;
        cin >> cd;
        
         switch(cd-1)
        {
            case difficulty::easy:
                ch = height[difficulty::easy];
                cw = width[difficulty::easy];
                cb = bombs[difficulty::easy];
                break;
            case difficulty::medium:
                ch = height[difficulty::medium];
                cw = width[difficulty::medium];
                cb = bombs[difficulty::medium];
                break;
            case difficulty::hard:
                ch = height[difficulty::hard];
                cw = width[difficulty::hard];
                cb = bombs[difficulty::hard];
                break;
            default:
                cout << sysmsg.again;
                break;
        } 
     }while(cd < 1 || cd > 3);
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
            case -1:
                cout << sysmsg.again;
                break;
            case -2:
                cout << sysmsg.alreadyopen;
                break;
            case -3:
                cout << sysmsg.over;
                game = false;
                cmine.coutover();
                break;
            case 0:
                break;
            case 1:
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