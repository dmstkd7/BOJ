//#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;
 
 
int main(void){
 
 
    int Test_Case, h, m, a, d, ah, am, aa, ad, th=0, tm=0, ta=0, td=0;
    int ret;
    scanf("%d", &Test_Case);
 
    for (int i = 1; i <= Test_Case; i++){
        scanf("%d%d%d%d%d%d%d%d", &h, &m, &a, &d, &ah,&am,&aa,&ad);
         
 
        //init
        if (h < 1)
            h = 1;
        if (m < 1)
            m = 1;
        if (a < 0)
            a = 0;
         
        th = h + ah;
        tm = m + am;
        ta = a + aa;
        td = d + ad;
 
 
        if (th < 1)
            th = 1;
        if (tm < 1)
            tm = 1;
        if (ta < 0)
            ta = 0;
 
        ret = 1 * th + 5 * tm + 2 * ta + 2 * td;
        printf("%d\n", ret);
    }
 
 
 
 
    return 0;
}
