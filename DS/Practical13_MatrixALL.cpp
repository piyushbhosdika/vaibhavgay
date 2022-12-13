/*Write a program to implement:
(a) Diagonal Matrix using one-dimensional array
(b) Lower Triangular Matrix using one-dimensional array
(c) Upper Triangular Matrix using one-dimensional array
(d) Symmetric Matrix using one-dimensional array
*/

/**
 *
 *
 *  FILE 1 : Diagonal Matrix
 *
 *
 *
 */

#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class DiagonalMatrix
{
public:
    int *arr;
    int size;
    int nrows;
    int ncols;
    DiagonalMatrix(int rows = MAX_SIZE,
                   int cols = MAX_SIZE)
    {
        if (rows != cols)
            cerr << "ERROR: Invalid Dimensions" << endl;
        else
        {
            size = rows;
            nrows = ncols = rows;
            arr = new int[size];
            for (int i = 0; i < size; i++)
                arr[i] = 0;
        }
    }
    ~DiagonalMatrix()
    {
        delete[] arr;
    }
    void store(int data, int row, int col)
    {
        if (row != col || row >= nrows || col >= ncols)
            cerr << "ERROR: Invalid Location" << endl;
        else
            arr[row] = data;
    }
    int retrieve(int row, int col)
    {
        if (row >= nrows || col >= ncols)
            return INT_MIN;
        if (row != col)
            return 0;
        else
            return arr[row];
    }
    void display()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
                if (i == j)
                    cout << arr[i] << " ";
                else
                    cout << 0 << " ";
            cout << endl;
        }
    }
};
int main(void)
{
    int rows, cols, data, choice = 1;
    cout << "Enter Number of Rows: ";
    cin >> rows;
    cout << "Enter Number of Columns: ";
    cin >> cols;
    clrscr();
    DiagonalMatrix matrix(rows, cols);
    do
    {
        cout << " MENU \n"
             << "================\n"
             << "(1) Display\n"
             << "(2) Store\n"
             << "(3) Retrieve\n"
             << "(0) Exit\n\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nMatrix:\n";
            matrix.display();
            break;
        case 2:
            cout << "Enter Data: ";
            cin >> data;
            cout << "Enter Position: ";
            cin >> rows >> cols;
            matrix.store(data, rows, cols);
            break;
        case 3:
            cout << "Enter Position: ";
            cin >> rows >> cols;
            data = matrix.retrieve(rows, cols);
            if (data != INT_MIN)
                cout << "Retrieved " << data << endl;
            else
                cerr << "ERROR: Invalid Location" << endl;
            break;
        case 0:
        default:
            break;
        }
        getch();
        clrscr();
    } while (choice != 0);
    return 0;
}
void getch()
{
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    return;
}
void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
    return;
}

/*
OUTPUT of FILE Diagonal Matrix

Enter Number of Rows: 3
Enter Number of Columns: 3
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 8
Enter Position: 0 1
ERROR: Invalid Location
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 5
Enter Position: 1 1
Press any key to continue...
 MENU
================
Page 123 of 166
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 1
Matrix:
0 0 0
0 5 0
0 0 0
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 4
Enter Position: 2 2
Press any key to continue..
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 3
Enter Position: 2 2
Retrieved 4
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 3
Page 124 of 166
Enter Position: 0 2
Retrieved 0
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 3
Enter Position: 5 5
ERROR: Invalid Location
Press any key to continue...*/

/*****
 *
 *
 *
 *          FILE 2:Lower Triangular Matrix
 *
 *
 *
 *
 */

#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class LowerTriangularMatrix
{
public:
    int *arr;
    int size;
    int nrows;
    int ncols;
    LowerTriangularMatrix(int rows = MAX_SIZE,
                          int cols = MAX_SIZE)
    {
        if (rows != cols)
            cerr << "ERROR: Invalid Dimensions" << endl;
        else
        {
            size = rows * (rows + 1) / 2;
            nrows = ncols = rows;
            arr = new int[size];
            for (int i = 0; i < size; i++)
                arr[i] = 0;
        }
    }
    ~LowerTriangularMatrix()
    {
        delete[] arr;
    }
    void store(int data, int row, int col)
    {
        if (col > row || row >= nrows || col >= ncols)
            cerr << "ERROR: Invalid Location" << endl;
        else
            arr[row * (row + 1) / 2 + col] = data;
    }
    int retrieve(int row, int col)
    {
        if (row >= nrows || col >= ncols)
            return INT_MIN;
        if (col > row)
            return 0;
        else
            return arr[row * (row + 1) / 2 + col];
    }
    void display()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
                if (i >= j)
                    cout << arr[i * (i + 1) / 2 + j] << " ";
                else
                    cout << 0 << " ";
            cout << endl;
        }
    }
};
int main(void)
{
    int rows, cols, data, choice = 1;
    cout << "Enter Number of Rows: ";
    cin >> rows;
    cout << "Enter Number of Columns: ";
    cin >> cols;
    clrscr();
    LowerTriangularMatrix matrix(rows, cols);
    do
    {
        cout << " MENU \n"
             << "================\n"
             << "(1) Display\n"
             << "(2) Store\n"
             << "(3) Retrieve\n"
             << "(0) Exit\n\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nMatrix:\n";
            matrix.display();
            break;
        case 2:
            cout << "Enter Data: ";
            cin >> data;
            cout << "Enter Position: ";
            cin >> rows >> cols;
            matrix.store(data, rows, cols);
            break;
        case 3:
            cout << "Enter Position: ";
            cin >> rows >> cols;
            data = matrix.retrieve(rows, cols);
            if (data != INT_MIN)
                cout << "Retrieved " << data << endl;
            else
                cerr << "ERROR: Invalid Location" << endl;
            break;
        case 0:
        default:
            break;
        }
        getch();
        clrscr();
    } while (choice != 0);
    return 0;
}
void getch()
{
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    return;
}
void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
    return;
}

/*

 oUTPUT OF LOWER tRIANGULAR mATRIX

Enter Number of Rows: 3
Enter Number of Columns: 3
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 4
Enter Position: 1 0
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Page 128 of 166
Enter Choice: 1
Matrix:
0 0 0
4 0 0
0 0 0
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 2
Enter Position: 0 1
ERROR: Invalid Location
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 8
Enter Position: 2 1
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 1
Matrix:
0 0 0
Page 129 of 166
4 0 0
0 8 0
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 3
Enter Position: 1 0
Retrieved 4
Press any key to continue...


*/

/**
 *
 *
 *              fILE 3: Upper Triangular Matrix

 *
 *
 *
*/

#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class UpperTriangularMatrix
{
public:
    int *arr;
    int size;
    int nrows;
    int ncols;
    UpperTriangularMatrix(int rows = MAX_SIZE,
                          int cols = MAX_SIZE)
    {
        if (rows != cols)
            cerr << "ERROR: Invalid Dimensions" << endl;
        else
        {
            size = cols * (cols + 1) / 2;
            nrows = ncols = rows;
            arr = new int[size];
            for (int i = 0; i < size; i++)
                arr[i] = 0;
        }
    }
    ~UpperTriangularMatrix()
    {
        delete[] arr;
    }
    void store(int data, int row, int col)
    {
        if (row > col || row >= nrows || col >= ncols)
            cerr << "ERROR: Invalid Location" << endl;
        else
            arr[col * (col + 1) / 2 + row] = data;
    }
    int retrieve(int row, int col)
    {
        if (row >= nrows || col >= ncols)
            return INT_MIN;
        if (row > col)
            return 0;
        else
            return arr[col * (col + 1) / 2 + row];
    }
    void display()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
                if (j >= i)
                    cout << arr[j * (j + 1) / 2 + i] << " ";
                else
                    cout << 0 << " ";
            cout << endl;
        }
    }
};
int main(void)
{
    int rows, cols, data, choice = 1;
    cout << "Enter Number of Rows: ";
    cin >> rows;
    cout << "Enter Number of Columns: ";
    cin >> cols;
    clrscr();
    UpperTriangularMatrix matrix(rows, cols);
    do
    {
        cout << " MENU \n"
             << "================\n"
             << "(1) Display\n"
             << "(2) Store\n"
             << "(3) Retrieve\n"
             << "(0) Exit\n\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nMatrix:\n";
            matrix.display();
            break;
        case 2:
            cout << "Enter Data: ";
            cin >> data;
            cout << "Enter Position: ";
            cin >> rows >> cols;
            matrix.store(data, rows, cols);
            break;
        case 3:
            cout << "Enter Position: ";
            cin >> rows >> cols;
            data = matrix.retrieve(rows, cols);
            if (data != INT_MIN)
                cout << "Retrieved " << data << endl;
            else
                cerr << "ERROR: Invalid Location" << endl;
            break;
        case 0:
        default:
            break;
        }
        getch();
        clrscr();
    } while (choice != 0);
    return 0;
}
void getch()
{
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    return;
}
void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
    return;
}

/*
Enter Number of Rows: 3
Enter Number of Columns: 3
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 3
Enter Position: 0 2
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Page 133 of 166
Enter Choice: 2
Enter Data: 5
Enter Position: 1 1
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 1
Matrix:
0 0 3
0 5 0
0 0 0
Press any key to continue...
 MENU
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 7
Enter Position: 2 0
ERROR: Invalid Location
Press any key to continue...
*/

/**
 *
 *
 *           file 4: symmetric matriX
 *
 *
 *
 *
 */

#include <climits>
#include <iostream>
#define MAX_SIZE 10
using namespace std;
void getch();
void clrscr();
class SymmetricMatrix
{
public:
    int *arr;
    int size;
    int nrows;
    int ncols;
    SymmetricMatrix(int rows = MAX_SIZE,
                    int cols = MAX_SIZE)
    {
        if (rows != cols)
            cerr << "ERROR: Invalid Dimensions" << endl;
        else
        {
            size = rows * (rows + 1) / 2;
            nrows = ncols = rows;
            arr = new int[size];
            for (int i = 0; i < size; i++)
                arr[i] = 0;
        }
    }
    ~SymmetricMatrix()
    {
        delete[] arr;
    }
    void store(int data, int row, int col)
    {
        if (row >= nrows || col >= ncols)
            cerr << "ERROR: Invalid Location" << endl;
        else if (col > row)
            arr[col * (col + 1) / 2 + row] = data;
        else
            arr[row * (row + 1) / 2 + col] = data;
    }
    int retrieve(int row, int col)
    {
        if (row >= nrows || col >= ncols)
            return INT_MIN;
        if (col > row)
            return arr[col * (col + 1) / 2 + row];
        else
            return arr[row * (row + 1) / 2 + col];
    }
    void display()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
                if (i > j)
                    cout << arr[i * (i + 1) / 2 + j] << " ";
                else
                    cout << arr[j * (j + 1) / 2 + i] << " ";
            cout << endl;
        }
    }
};
int main(void)
{
    int rows, cols, data, choice = 1;
    cout << "Enter Number of Rows: ";
    cin >> rows;
    cout << "Enter Number of Columns: ";
    cin >> cols;
    clrscr();
    SymmetricMatrix matrix(rows, cols);
    do
    {
        cout << " MENU \n"
             << "================\n"
             << "(1) Display\n"
             << "(2) Store\n"
             << "(3) Retrieve\n"
             << "(0) Exit\n\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nMatrix:\n";
            matrix.display();
            break;
        case 2:
            cout << "Enter Data: ";
            cin >> data;
            cout << "Enter Position: ";
            cin >> rows >> cols;
            matrix.store(data, rows, cols);
            break;
        case 3:
            cout << "Enter Position: ";
            cin >> rows >> cols;
            data = matrix.retrieve(rows, cols);
            if (data != INT_MIN)
                cout << "Retrieved " << data << endl;
            else
                cerr << "ERROR: Invalid Location" << endl;
            break;
        case 0:
        default:
            break;
        }
        getch();
        clrscr();
    } while (choice != 0);
    return 0;
}
void getch()
{
    cout << "\nPress any key to continue...";
    cin.ignore();
    cin.get();
    return;
}
void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
    return;
}


/*
Enter Number of Rows: 3
Enter Number of Columns: 3
 MENU 
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 2
Enter Data: 8
Enter Position: 1 2
Press any key to continue...
 MENU 
================
(1) Display
(2) Store
(3) Retrieve
(0) Exit
Enter Choice: 1
Page 138 of 166
Matrix:
0 0 0
0 0 8
0 8 0
Press any key to continue...
 MENU 
================
(1) Display 
(2) Store 
(3) Retrieve 
(0) Exit 
Enter Choice: 2
Enter Data: 9
Enter Position: 0 2
Press any key to continue...
*/