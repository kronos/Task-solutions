#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
string f[8];
string line;
bool good = false;

string pieces[] = {"PCTBRK", "pctbrk"};
int idx;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 8; i++) {
    cin >> f[i];
  }

  cin >> line;
  int ii,jj;
  ii = 7-(line[1]-'1');
  jj = line[0] - 'a';
  if (f[ii][jj] != '.') {
    if (f[ii][jj] < 'a') {
      idx = 1;
    }
    // pawn left
    if (jj > 0 && ii < 7 && f[ii+1][jj-1] == pieces[idx][0] && idx == 1) {
      good = true;
    // pawn right
    } else if (jj < 7 && ii < 7 && f[ii+1][jj+1] == pieces[idx][0] && idx == 1) {
      good = true;
    } else if (jj > 0 && ii > 0 && f[ii-1][jj-1] == pieces[idx][0] && idx == 0) {
      good = true;
    } else if (jj < 7 && ii > 0 && f[ii-1][jj+1] == pieces[idx][0] && idx == 0) {
      good = true;
    } else if (ii-1 >= 0 && jj - 2 >= 0 && f[ii-1][jj-2] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii-1 >= 0 && jj + 2 < 8  && f[ii-1][jj+2] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii+1 < 8  && jj - 2 >= 0 && f[ii+1][jj-2] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii+1 < 8  && jj + 2 < 8  && f[ii+1][jj+2] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii-2 >= 0 && jj - 1 >= 0 && f[ii-2][jj-1] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii+2 < 8  && jj - 1 >= 0 && f[ii+2][jj-1] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii-2 >= 0 && jj + 1 < 8  && f[ii-2][jj+1] == pieces[idx][1]) { // knight
      good = true;
    } else if (ii+2 < 8  && jj + 1 < 8 && f[ii+2][jj+1] == pieces[idx][1]) {  // knight
      good = true;
    } else if (ii-1 >= 0 && jj - 1 >= 0 && f[ii-1][jj-1] == pieces[idx][5]) { // king
      good = true;
    } else if (ii+1  < 8 && jj + 1 < 8 && f[ii+1][jj+1] == pieces[idx][5]) { // king
      good = true;
    } else if (             jj - 1 >= 0 && f[ii][jj-1] == pieces[idx][5]) { // king
      good = true;
    } else if (             jj + 1 <  8 && f[ii][jj+1] == pieces[idx][5]) { // king
      good = true;
    } else if (ii-1 >= 0                && f[ii-1][jj] == pieces[idx][5]) { // king
      good = true;
    } else if (ii+1 < 8                && f[ii+1][jj] == pieces[idx][5]) { // king
      good = true;
    } else if (ii-1 >= 0 && jj + 1 < 8  && f[ii-1][jj+1] == pieces[idx][5]) { // king
      good = true;
    } else if (ii+1 < 8 && jj - 1 >= 0 && f[ii+1][jj-1] == pieces[idx][5]) { // king
      good = true;
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (ii + i < 8) {
        if (f[ii+i][jj] == pieces[idx][4] ||    // queen
            f[ii+i][jj] == pieces[idx][2]) {    // rook
          good = true;
        } else if (f[ii+i][jj] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (ii - i >= 0) {
        if (f[ii-i][jj] == pieces[idx][4] ||    // queen
            f[ii-i][jj] == pieces[idx][2]) {    // rook
          good = true;
        } else if (f[ii-i][jj] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (jj + i < 8) {
        if (f[ii][jj+i] == pieces[idx][4] ||    // queen
            f[ii][jj+i] == pieces[idx][2]) {    // rook
          good = true;
        } else if (f[ii][jj+i] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (jj - i >= 0) {
        if (f[ii][jj-i] == pieces[idx][4] ||    // queen
            f[ii][jj-i] == pieces[idx][2]) {    // rook
          good = true;
        } else if (f[ii][jj-i] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (ii - i >= 0 && jj-i >= 0) {
        if (f[ii-i][jj-i] == pieces[idx][4] ||    // queen
            f[ii-i][jj-i] == pieces[idx][3]) {    // bishop
          good = true;
        } else if (f[ii-i][jj-i] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (ii + i < 8 && jj+i < 8) {
        if (f[ii+i][jj+i] == pieces[idx][4] ||    // queen
            f[ii+i][jj+i] == pieces[idx][3]) {    // bishop
          good = true;
        } else if (f[ii+i][jj+i] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (ii - i >= 0 && jj+i < 8) {
        if (f[ii-i][jj+i] == pieces[idx][4] ||    // queen
            f[ii-i][jj+i] == pieces[idx][3]) {    // bishop
          good = true;
        } else if (f[ii-i][jj+i] != '.') {
          break;
        }
      } else {
        break;
      }
    }

    for (int i = 1; (i < 8) && !good; i++) {
      if (ii + i < 8 && jj-i >= 0) {
        if (f[ii+i][jj-i] == pieces[idx][4] ||    // queen
            f[ii+i][jj-i] == pieces[idx][3]) {    // bishop
          good = true;
        } else if (f[ii+i][jj-i] != '.') {
          break;
        }
      } else {
        break;
      }
    }

  }

  if (good) {
    cout << "Sim\n";
  } else {
    cout << "Nao\n";
  }
  return 0;
}
