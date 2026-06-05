#include <iostream>
#include<cmath>
using namespace std;
long long getmaxprimefactor(long long n) {
   long long maxpf = -1;
   while (n % 2 == 0) {
      maxpf = 2;
      n /= 2;
   }
   for (int i = 3; i <= sqrt(n); i += 2) {
      while (n % i == 0) {
         maxpf = i;
         n = n / i;
      }
   }
   if (n > 2)
   maxpf = n;
   return maxpf;
}
int main() {
   long long n;
   cout << "Enter a positive integer: ";
    cin >> n;
   cout << "Max Prime factor of " << n << " is " << getmaxprimefactor(n);
}