//
//  Header.h
//  ppvis1
//
//  Created by Андрей Мясоеденков on 24.09.13.
//  Copyright (c) 2013 Андрей Мясоеденков. All rights reserved.
//

#ifndef ppvis1_matrix_h
#define ppvis1_matrix_h


#include "iostream"

class cmatrix
{
public:
    int opencon(int kol);  // ввод матрицы с консоли
    void open(FILE *f);  // открытие матрицы из файла
    void clear(int **M, int kol);   // очистка матрицы
    void trans(int **M, int c, int v);  // транспонирование матрицы
    void output(int **M, int a, int b);  // вывод матрицы на экран пользователя
private:
    
};

#endif