// (c) Tivole

// 506

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
   char c=' ', prev=' ';
   bool com=0;
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   while(c!=EOF) {
       while((c=getchar())!=EOF) {
           if(c=='/'&&prev=='/') com=1;
           if(c=='\n') com=0;
           if(!com&&c=='>'&&prev=='-') {
               cout.seekp(-1, ios_base::cur);
               cout << '.';
           }
           else cout << c;
           prev=c;
       }
   }
   return 0;
}