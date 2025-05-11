// Aru, Thomas, Everett
// Grantham Airplanes Project

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int seats[12][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0},
                    {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
int children;
int section;
int age;
bool full = 0;
int seat = 1;
int section1 = 12;
int section2 = 24;
int section3 = 12;

void printGrid() {
  for (int x = 0; x < 12; x++) {
    for (int y = 0; y < 4; y++) {
      cout << seats[x][y] << " ";
    }
    cout << endl;
  }
}

bool planeFull() {
  for (int x = 0; x < 12; x++) {
    for (int y = 0; y < 4; y++) {
      if (seats[x][y] == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  while (1) {
    seat = 1;
    full = planeFull();
    if (full == true) {
      cout << "Plane full!" << endl;
      printGrid();
      break;
    }

    printGrid();

    while (1) {
      cout << "Which section are you sitting in?" << endl
           << "(1) first class" << endl
           << "(2) economy" << endl
           << "(3) other" << endl
           << endl;
      cin >> section;
      if (section >= 1 && section <= 3) {
        break;
      } else if (section < 1 || section > 3) {
        cout << "Invalid section. Try again" << endl;
      } else {
        continue;
      }
    }

    while (1) {
      cout << "Please enter the number of children traveling with you: ";
      cin >> children;
      if (children < 0) {
        continue;
      }
      break;
    }

    for (int n = 0; n < children; n++) {
      cout << "Enter your child's age: " << endl;
      cin >> age;
      if (age >= 2) {
        seat++;
      } else if (age < 0) {
        cout << "Invalid age. Try again" << endl;
        n--;
      }
    }

    if (section == 1) {
      for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 4; y++) {
          if (seats[x][y] == 0 && seat > 0 && seat <= section1) {
            seats[x][y] = 1;
            seat--;
            section1--;
          }
        }
        if (seat == 0)
          break;
      }
      if (seat > 0) {
        cout << "There are no more first class seats available. Choose a "
                "different section."
             << endl;
      }
    } else if (section == 2) {
      for (int x = 3; x < 9; x++) {
        for (int y = 0; y < 4; y++) {
          if (seats[x][y] == 0 && seat > 0 && seat <= section2) {
            seats[x][y] = 1;
            seat--;
            section2--;
          }
        }
        if (seat == 0)
          break;
      }
      if (seat > 0) {
        cout << "There are no more economy seats available. Choose a different "
                "section."
             << endl;
      }
    } else if (section == 3) {
      for (int x = 9; x < 12; x++) {
        for (int y = 0; y < 4; y++) {
          if (seats[x][y] == 0 && seat > 0 && seat <= section3) {
            seats[x][y] = 1;
            seat--;
            section3--;
          }
        }
        if (seat == 0)
          break;
      }
      if (seat > 0)
        cout << "There are no more other seats available. Try somewhere else."
             << endl;
    }
  }
}
