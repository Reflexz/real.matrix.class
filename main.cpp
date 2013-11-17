//
//  main.cpp
//  ppvis1
//
//  Created by Андрей Мясоеденков on 24.09.13.
//  Copyright (c) 2013 Андрей Мясоеденков. All rights reserved.
//

#include "matrix.h"
#include "iostream"
#include "stdio.h"

using std::cin;
using std::cout;
using std::endl;
using std::fscanf;
using std::fopen;

int kod1=0, kod2=0;
int str, stl, **M, **N;
int m1, m2, e;
FILE *f;

cmatrix matrix1;
int main()
{
    while(true)       //// МЕНЮ
    {
        puts("Вещественная матрица\nМеню:\n1 - Ввод произвольной матрицы\n2 - Загрузка матрицы из файла\n3 - Изменение числа строк и столбцов\n4 - Извлечение подматрицы заданного размера\n5 - Проверка типа матрицы\n6 - Транспонирование матрицы");
        scanf("%d", &kod1);
        switch(kod1)
        {
            case 1:
            {
                puts("Введите кол-во строк, столбцов:");
                scanf("%d", &str);
                scanf("%d", &stl);
               // matrix1.opencon(str*stl);
                
                int **M=new int *[str*stl];       // выделение памяти
                for(int k=0; k<str; k++)
                {
                    M[k]=new int[stl];
                }
                puts("Введите элементы:");
                for(int i=0; i<str; i++)
                {
                    std::cout << i+1 <<" строка: ";
                    for(int j=0; j<stl; j++)
                    {
                        scanf("%d", &e);
                        M[i][j]=e;
                        e=0;
                    }
                }
                cout<< "Введенная матрица:" << endl;
                matrix1.output(M, str, stl);
                break;
            }
            case 2:
            {
                f=fopen("/Users/Reflexz/Downloads/___1Uni___/in-developing/ppvis1/matrix.txt", "r+"); // файл
                if(!f)
                {
                    puts("Ошибка загрузки файла! Укажите matrix.txt!");
                    exit(1);
                }
                cout << "Файл загружен." << endl;    //успешное открытие
                
                matrix1.open(f);
                fclose(f);
                cout << "Завершено." << endl;
                break;
            }
            case 3:
            
                break;
            case 4:
                break;
            case 5:
                if(M!=0)
                {
                    cout << "Типы матрицы: " << endl;
                    int a=0, b=0, p;
                // квадратная
                    if(str==stl)
                    {
                        cout << "-квадратная " << endl;
                        // диагональная
                        p=0;
                        for(int i=0; i<str; i++)
                        {
                            for(int j=0; j<stl; j++)
                            {
                                if(i!=j)
                                {
                                    if(M[i][j]!=0)
                                    {
                                        p=1;
                                        break;
                                    }
                                }
                                
                            }
                        }
                        if(p!=1)
                        {
                            cout << "-диагональная " << endl;
                            cout << "-верхнетреугольная " << endl;
                            a=1;
                            cout << "-нижнетреугольная " << endl;
                            b=1;
                        }
                    }
                // нулевая
                    p=0;
                    for(int i=0; i<str; i++)
                    {
                        for(int j=0; j<stl; j++)
                        {
                                if(M[i][j]!=0)
                                {
                                    p=1;
                                    break;
                                }
                        }
                    }
                    if(p!=1)
                    {
                        cout << "-нулевая " << endl;
                    }
                // единичная
                    if(str==stl)
                    {
                        p=0;
                        for(int i=0; i<str; i++)
                        {
                            for(int j=0; j<stl; j++)
                            {
                                if(M[i][j]!=1)
                                {
                                    p=1;
                                    break;
                                }
                            }
                        }
                        if(p!=1)
                        {
                            cout << "-единичная " << endl;
                        }
                    }
                // симметрическая
                // верхняя треугольная
                    if(a==0)
                    {
                        
                    }
                // нижняя треугольная
                    if(b==0)
                    {
                        
                    }
                    
                    
                }
                else
                {
                    cout << "-Введите матрицу!" << endl;
                }
                
                break;
            case 6:
            {
                if(M!=0)
                {
                    matrix1.trans(M, stl, str);
                }
                else
                {
                    cout << "-Введите матрицу!" << endl;
                }
                break;
            }
        }
    }
}

int cmatrix::opencon(int kol)
{
    
    return **M;
}

void cmatrix::open(FILE *f)   //// функция открытия матрицы из файла
{
    fscanf(f, "%d", &str);   // считываем число строк
    fscanf(f, "%d", &stl);   // считываем число столбцов
    int **M=new int *[str*stl];       // выделение памяти
    for(int k=0; k<str; k++)
    {
        M[k]=new int[stl];
    }
    for(int i=0; i<str; i++)      // заполнение массива элементами матрицы
    {
        int h;
        h=0;
        for(int j=0; j<stl; j++)
        {
            int r;
            fscanf(f, "%d", &r);
            M[i][h]=r;
            h++;
        }
    }
    cout<<"Загружена матрица:"<<endl;
    matrix1.output(M, str, stl);
}

void cmatrix::clear(int **M, int kol)    //// функция удаление массива и освобождение памяти
{
    for(int m=0; m<kol; m++)  delete [] M[m];
    delete []M;
}

void cmatrix::output(int **M, int a, int b)  //// функция вывода
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

void cmatrix::trans(int **M, int c, int v)  //// функция транспонирования
{
    int **N=new int *[c*v];       // выделение памяти
    for(int k=0; k<v; k++)
    {
        N[k]=new int[c];
    }
    int bufer;
    for(int b=0; b<v; b++)
    {
        int h;
        h=0;
        for(int v=0; v<c; v++)
        {
            bufer=M[b][h];
            N[b][h]=bufer;
            h++;
        }
    }
    cout<<"Транспонированная матрица:"<<endl;
    matrix1.output(N, v, c);
}




