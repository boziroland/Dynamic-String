/**
 * foprogram az F10 osztaly kiprobalasahoz.
 * Bozi Roland Sa'ndor, EO7EGE reszere
 * Datum: 2018-03-08 22:23:21
 * Ez az allomany tetszes szerint modosithato
 */

#include <iostream>
#include "f10.h"

using namespace std;

int main() {
  F10 a, c;

  cout << a.ident() << endl;
  cout << a.match("xxa blaszinuk as \n") << endl;
  for (int i = 0; i < 5; i ++) { 
    F10 b = a;
    cout << b.match(" detekciot ") << endl;
  }
  F10 b = a;
  a = a;
  c = b;

  cout << c.getLine();
  return 0;
}
