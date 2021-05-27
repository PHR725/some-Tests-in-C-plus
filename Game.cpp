#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
using namespace std;

string name;
double Stats[] = { 6, 100, 100 };
int rnum, rnum2, rnum3, choice, Ichoice, Mchoice;

void ignoreLine()
{
    cin.clear();
    cin.ignore();
}

int main()
{

    cout << "what is your name?" << endl;
    cin >> name;

    cout << name << ", thats a good one, anyway you are about to fight a very powerful foe, be ready" << endl;

    cout << "--------------------------------------------------------" << endl;

    cout << "Boss: i shall destroy you " << name << "!!!" << endl;

    cout << "--------------------------------------------------------" << endl;
jump:
    cout << "BOSS HEALTH: " << Stats[1] << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << name << " HEALTH: " << Stats[2] << endl;
    cout << endl;
    cout << "your choices: " << endl;
    cout << "\t 1-Attack | 2-Defend | 3-Magic | 4-Item" << endl;
    cin >> choice;

    while (cin.fail()) {
        ignoreLine();
        cout << "please select a number: " << endl;
        cout << "\t 1-Attack | 2-Defend | 3-Magic | 4-Item" << endl;
        cin >> choice;
    }
    cout << "--------------------------------------------------------" << endl;

    switch (choice) {

    case 1:

        cout << "you have decided to attack" << endl;
        srand((unsigned)time(0));
        rnum = (rand() % 10) + 1;

        cout << "the boss has taken " << rnum << " damage" << endl;
        cout << "You have taken " << Stats[0] << " damage" << endl;

        cout << "--------------------------------------------------------" << endl;

        Stats[1] = Stats[1] - rnum;
        Stats[2] = Stats[2] - Stats[0];

        break;

    case 2:

        cout << "you have decided to defend" << endl;

        cout << "--------------------------------------------------------" << endl;

        Stats[2] = Stats[2] - (Stats[0] - 3);

        break;

    case 3:

        cout << "you have decided to use Magic" << endl;
    Mjump:;
        cout << "your choices: " << endl;
        cout << "\t 1-Magic Attack | 2-Null attack" << endl;
        cin >> Mchoice;

        while (cin.fail()) {
            ignoreLine();
            cout << "please select a number: " << endl;
            cout << "\t 1-Magic Attack | 2-Null attack" << endl;
            cin >> Mchoice;
        }

        switch (Mchoice) {

        case 1:

            cout << "you decided to use a magic attack" << endl;

            Stats[1] = Stats[1] - 16;
            Stats[2] = Stats[2] - Stats[0];

            cout << "the boss has taken 16 damage" << endl;

            cout << "--------------------------------------------------------" << endl;

            break;

        case 2:

            cout << "you have decided to cast null attack" << endl;

            Stats[2] = Stats[2] - 0;

            cout << "the attack reflected to the boss" << endl;

            cout << "--------------------------------------------------------" << endl;

            Stats[1] = Stats[1] - Stats[0];

            break;

        default:
            cout << "that is not a choice" << endl;
            cout << "--------------------------------------------------------" << endl;
            goto Mjump;

        }

        break;

    case 4:

        cout << "you have decided to use an Item" << endl;
        cout << "what item will you use?" << endl;
        cout << "--------------------------------------------------------" << endl;
    Ijump:;
        cout << "your choices: " << endl;
        cout << "\t 1-Attack item | 2-Heal item" << endl;
        cin >> Ichoice;

        while (cin.fail()) {
            ignoreLine();
            cout << "please select a number: " << endl;
            cout << "\t 1-Attack item | 2-Heal item" << endl;
            cin >> Ichoice;
        }

        switch (Ichoice) {
        case 1:

            srand((unsigned)time(0));
            rnum2 = (rand() % 10) + 12;

            cout << "You have used an attack item at the boss" << endl;
            cout << "Boss has taken " << rnum2 << " damage" << endl;

            cout << "--------------------------------------------------------" << endl;

            Stats[1] = Stats[1] - rnum2;
            Stats[2] = Stats[2] - Stats[0];

            break;

        case 2:
            cout << "you have used an healing item on yourself" << endl;

            srand((unsigned)time(0));
            rnum3 = (rand() % 10) + 13;

            Stats[2] = Stats[2] + rnum3;
            Stats[2] = Stats[2] - Stats[0];

            cout << "you have restored " << rnum3 << " health" << endl;

            cout << "--------------------------------------------------------" << endl;
            break;

        default:
            cout << "that is not a choice" << endl;
            cout << "--------------------------------------------------------" << endl;
            goto Ijump;
        }

        break;

    default:
        cout << "that is not a choice" << endl;
        cout << "--------------------------------------------------------" << endl;

    }

    if (Stats[1] > 0 && Stats[2] > 0) {
        goto jump;
    }
    else if (Stats[1] <= 0 && Stats[2] > 0) {
        cout << "Boss: impossible, how can this beeeeeeeeeeeeeeee" << endl;
        cout << endl;
        cout << "the Boss has fallen and you have saved the world" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Good ending" << endl;
    }
    else if (Stats[1] > 0 && Stats[2] <= 0) {

        cout << "Boss: Hahahahaha you have been defeated now the world is mine" << endl;
        cout << endl;
        cout << "you have failed and now the world shall be conquered by the boss" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Bad ending" << endl;
    }
    else if (Stats[1] <= 0 && Stats[2] <= 0) {

        cout << "Boss: You may have beaten me but it costed your own life" << endl;
        cout << endl;
        cout << "you did it, you beat the boss but also lost your own life : C " << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Neutral ending" << endl;
    }

    return 0;
}


