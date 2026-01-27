#include <bits/stdc++.h>
using namespace std;


void complexRec(int n) {

    opc ++;

   if (n <= 2) {
       return;
   }


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       opc ++;
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           opc++;
       }
       p >>= 1;
       opc++;
   }

   // n log(n)

   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       opc++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       opc++;
   } else {
       reverse(small.begin(), small.end());
       opc++;
   }
   complexRec(n / 2);// t(n/2)
   complexRec(n / 2);// t(n/2)
   complexRec(n / 2);// t(n/2)  Total = 3t(n/2)
}
int main() {


    complexRec(10)
    cout <<"opc";

    return 0;
}

// Recurrece relation : T(n)= 3t(n/2)+ nlogn
// Time complexity : O(n^log(3)) using master theorem (case-1)

// Operations 

// depth = n/2*k=1


