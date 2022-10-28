// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "locale.h"
#include "tmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  TDynamicMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование класс работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;

  TDynamicMatrix<int> d(3);
  TDynamicVector<int> e(3), f(3);
  d[0][0] = 2;
  d[0][1] = 4;
  d[0][2] = 0;
  d[1][0] = -2;
  d[1][1] = 1;
  d[1][2] = 3;
  d[2][0] = -1;
  d[2][1] = 0;
  d[2][2] = 1;

  e[0] = 1;
  e[1] = 2;
  e[2] = -1;

  f = d * e;

  cout << f << endl;
}
//---------------------------------------------------------------------------
