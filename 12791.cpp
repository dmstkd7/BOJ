//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
 
 
vector <char*> list[50];
 
int tmp[25] = {
    1967,
    1969,
    1970,
    1971,
    1972,
    1973,
    1973,
    1974,
    1975,
    1976,
    1977,
    1977,
    1979,
    1980,
    1983,
    1984,
    1987,
    1993,
    1995,
    1997,
    1999,
    2002,
    2003,
    2013,
    2016
};
 
char * tmp1[25] = {
        "DavidBowie",
        "SpaceOddity",
        "TheManWhoSoldTheWorld",
        "HunkyDory",
        "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars",
        "AladdinSane",
        "PinUps",
        "DiamondDogs",
        "YoungAmericans",
        "StationToStation",
        "Low",
        "Heroes",
        "Lodger",
        "ScaryMonstersAndSuperCreeps",
        "LetsDance",
        "Tonight",
        "NeverLetMeDown",
        "BlackTieWhiteNoise",
        "1.Outside",
        "Earthling",
        "Hours",
        "Heathen",
        "Reality",
        "TheNextDay",
        "BlackStar"
    };
 
 
void query(int a, int b){
 
     
 
    a -= 1967;
    b -= 1967;
 
    if (a < 0)
        a = 0;
    if (b < 0){
        printf("0\n");
        return;
 
    }
         
 
    int count = 0;
 
    for (int i = a; i <= b; i++){
        if (!list[i].empty())
            for (int j = 0; j < list[i].size(); ++j)
                count++;
    }
 
    printf("%d\n", count);
 
    for (int i = a; i <= b; i++){
        if (!list[i].empty())
            for (int j = 0; j < list[i].size(); ++j)
                printf("%d %s\n", i+1967, list[i][j]);
    }
}
 
 
int main(void){
 
 
    int Test_Case,a, b;
    int y;
    char * n;
 
 
    for (int i = 0; i < 25; i++){
        y = tmp[i] - 1967;
        n = tmp1[i];
        list[y].push_back(n);
    }
     
    scanf("%d", &Test_Case);
    for (int i = 1; i <= Test_Case; i++){
        scanf("%d%d", &a, &b);
         
        query(a, b);
 
    }
 
 
 
 
    return 0;
}
