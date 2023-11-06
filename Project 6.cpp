// Braden Drewery
// Project 6
// Tinker With Tables
// CPP File due 5/3

/*PROJECT DESCRIPTION:
For this project, you will be writing functions to tinker with 2-D arrays. You
will already have some of this code that was developed in class and from
Project 4.*/

#include <iostream>
using namespace std;

// Constant Variables
const int ROW = 10;
const int COL = 10;
const string line = "----------------------------------";

// Function Declarations
int GetChoice();
void FillMatrix(int ar[][COL], int &row, int &col);
void PrintRowMajorMatrix(int ar[][COL], int row, int col);
void PrintColMajorMatrix(int ar[][COL], int row, int col);
bool PrintDiagonal(int ar[][COL], int row, int col);
int GetSumOfValues(int ar[][COL], int row, int col);
void PrintColumnProducts(int ar[][COL], int row, int col);

// Main Function
int main() {
  // Variable Declarations
  int row = 0;
  int col = 0;
  int ar[ROW][COL];
  int choice = GetChoice();
  int Sum;

  // While loop for GetChoice Function
  while (choice != 0) {
    if (choice == 1) {
      FillMatrix(ar, row, col);
    } else if (choice == 2) {
      PrintRowMajorMatrix(ar, row, col);
    } else if (choice == 3) {
      PrintColMajorMatrix(ar, row, col);
    } else if (choice == 4) {
      PrintDiagonal(ar, row, col);
      if (row != col) {
        cout << "Error: Matrix is not square" << endl;
      }
    } else if (choice == 5) {
      Sum = GetSumOfValues(ar, row, col);
      cout << Sum;
    } else if (choice == 6) {
      PrintColumnProducts(ar, row, col);
    }
    cout << endl;
    choice = GetChoice();
  }
  return 1;
}

// Function Definitions

/*This function should pass back as parameters a 2-D array and the row and
column values entered from the user. The function will ask the user for the row
and column number, then ask the user for the values to be entered into the array
in row major order.*/
void FillMatrix(int ar[][COL], int &row, int &col) {
  cout << "Enter number of rows: ";
  cin >> row;
  cout << "Enter number of columns: ";
  cin >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << "Enter value for row " << i << " and column " << j << ": ";
      cin >> ar[i][j];
    }
  }
}

/*This function should take in as parameters a 2-D array, the row, and the
column values. Print the matrix in row major order.*/
void PrintRowMajorMatrix(int ar[][COL], int row, int col) {
  cout << "Array in row major order:" << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << ar[i][j] << " ";
    }
    cout << endl;
  }
}

/*This function should take in as parameters a 2-D array, the row, and the
column values. Print the matrix in col major order.*/
void PrintColMajorMatrix(int ar[][COL], int row, int col) {
  cout << "Matrix in col major order:" << endl;
  for (int j = 0; j < col; j++) {
    for (int i = 0; i < row; i++) {
      cout << ar[i][j] << " ";
    }
    cout << endl;
  }
}

/*This function should take in as parameters a 2-D array, the row, and the
column values. If the matrix is a square matrix (row == column), print the
diagonal and return true. If the row and column values do not match, the
function should return false. From the main function, if this function returns
false, the main function should print a message.*/
bool PrintDiagonal(int ar[][COL], int row, int col) {
  if (row != col) {
    return false;
  }
  cout << "Diagonal values:" << endl;
  for (int i = 0; i < row; i++) {
    cout << ar[i][i] << " ";
  }
  cout << endl;
  return true;
}

/*This function should take in as parameters a 2-D array, the row, and the
column values. The function should return the sum of the values in the matrix.
The result should be printed in the main function.*/
int GetSumOfValues(int ar[][COL], int row, int col) {
  int Sum = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      Sum += ar[i][j];
    }
  }
  return Sum;
}

/*This function should take in as parameters a 2-D array, the row, and the
column values. For each column, display the column number and the sum of the
values stored in that column of the 2-D array. No return value.*/
void PrintColumnProducts(int ar[][COL], int row, int col) {
  for (int j = 0; j < col; j++) {
    int product = 1;
    for (int i = 0; i < row; i++) {
      product *= ar[i][j];
    }
    cout << "Product of column " << j + 1 << ": " << product << endl;
  }
}
// This function helps display the different options for the users and returns
// their choice to the main or exits the program.
int GetChoice() {
  int result = 0;
  cout << line << endl;
  cout << "Menu:" << endl;
  cout << line << endl;
  cout << "1. Fill the Matrix" << endl;
  cout << "2. Print the Matrix in Row Major Order" << endl;
  cout << "3. Print the Matrix in Col Major Order" << endl;
  cout << "4. Print Diagonal" << endl;
  cout << "5. Get the Sum of the Values" << endl;
  cout << "6. Print the Product of each column" << endl;
  cout << "0. Quit" << endl;
  cout << line << endl;

  cout << "Enter your choice: ";
  cin >> result;
  return result;
}