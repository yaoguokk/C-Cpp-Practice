//
//  EE599_Lab2_2176023892.c
//
//  Created by Yao on 1/21/19.
//  Copyright © 2019 Yao. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char str[] = "input.txt";
double func2()
{
    int maxpower(int);
    long int **create(int);
    void addmatrix(long int **, long int **, long int **, int);
    void submatrix(long int **, long int **, long int **, int);
    void printmatrix(long int **, int);

    void strassen(long int **, long int **, long int **, int);
    int num;
    time_t start, end;
    int i, j, k;
    FILE *fp = fopen(str, "r");

    //read the first line which is the number of rows and columns
    fscanf(fp, "%d", &num);

    int maxnum;
    maxnum = maxpower(num);

    long int **a = create(maxnum);
    long int **b = create(maxnum);
    long int **result = create(maxnum);

    //read from text file
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            fscanf(fp, "%li", &a[i][j]);
        }
        fscanf(fp, "\n");
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            fscanf(fp, "%li", &b[i][j]);
        }
        fscanf(fp, "\n");
    }

    //calculate

    start = clock();

    strassen(a, b, result, maxnum);

    end = clock();

    //write to files
    FILE *fp1 = fopen("output_p1_m2.txt", "w");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            fprintf(fp1, "%li ", result[i][j]);
        }
        fprintf(fp1, "\n");
        ;
    }
    fclose(fp);
    return (end - start);
}
double func1()
{
    int maxpower(int);
    long int **create(int);
    time_t start, end;
    int i, j, k, rowcolumn, num;
    FILE *fp = fopen(str, "r");

    //read the first line which is the number of rows and columns
    fscanf(fp, "%d", &num);

    long int **a = create(num);
    long int **b = create(num);
    long int **result = create(num);

    //read from text file
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            fscanf(fp, "%li", &a[i][j]);
        }
        fscanf(fp, "\n");
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            fscanf(fp, "%li", &b[i][j]);
        }
        fscanf(fp, "\n");
    }

    fclose(fp);

    //calculate

    start = clock();
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            int sum = 0;
            for (k = 0; k < num; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    end = clock();

    //write to files
    FILE *fp1 = fopen("output_p1_m1.txt", "w");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            fprintf(fp1, "%li ", result[i][j]);
        }
        fprintf(fp1, "\n");
        ;
    }
    fclose(fp1);

    return (end - start);
}

long int **create(int num)
{
    void initial(long int **, int);
    int i;
    long int **matrix = malloc(num * sizeof(long int *));
    for (int i = 0; i < num; i++)
    {
        matrix[i] = malloc(num * sizeof(long int *));
    }
    initial(matrix, num);

    return matrix;
}

void strassen(long int **A, long int **B, long int **result, int num)
{
    long int **create(int);
    void freematrix(long int **, int);
    void addmatrix(long int **, long int **, long int **, int);
    void submatrix(long int **, long int **, long int **, int);
    void printmatrix(long int **, int);
    void matrixsplit(long int **, long int **, long int **, long int **, long int **, int);
    void matrixmerge(long int **, long int **, long int **, long int **, long int **, int);
    if (num == 1)
    {
        result[0][0] = A[0][0] * B[0][0];
    }
    else if (num == 2)
    {
        int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        int m2 = (A[1][0] + A[1][1]) * B[0][0];
        int m3 = A[0][0] * (B[0][1] - B[1][1]);
        int m4 = A[1][1] * (B[1][0] - B[0][0]);
        int m5 = (A[0][0] + A[0][1]) * B[1][1];
        int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

        result[0][0] = m1 + m4 - m5 + m7;
        result[0][1] = m3 + m5;
        result[1][0] = m2 + m4;
        result[1][1] = m1 - m2 + m3 + m6;
    }
    else
    {
        // create and initialize
        long int **a11 = create(num / 2);
        long int **a12 = create(num / 2);
        long int **a21 = create(num / 2);
        long int **a22 = create(num / 2);
        long int **b11 = create(num / 2);
        long int **b12 = create(num / 2);
        long int **b21 = create(num / 2);
        long int **b22 = create(num / 2);

        long int **s1 = create(num / 2);
        long int **s2 = create(num / 2);
        long int **s3 = create(num / 2);
        long int **s4 = create(num / 2);
        long int **s5 = create(num / 2);
        long int **s6 = create(num / 2);
        long int **s7 = create(num / 2);
        long int **s8 = create(num / 2);
        long int **s9 = create(num / 2);
        long int **s10 = create(num / 2);

        //split matrix  A and B into 8submatrix
        matrixsplit(A, a11, a12, a21, a22, num / 2);

        matrixsplit(B, b11, b12, b21, b22, num / 2);

        addmatrix(a11, a22, s1, num / 2);
        addmatrix(b11, b22, s2, num / 2);
        addmatrix(a21, a22, s3, num / 2);
        submatrix(b12, b22, s4, num / 2);
        submatrix(b21, b11, s5, num / 2);
        addmatrix(a11, a12, s6, num / 2);
        submatrix(a21, a11, s7, num / 2);
        addmatrix(b11, b12, s8, num / 2);
        submatrix(a12, a22, s9, num / 2);
        addmatrix(b21, b22, s10, num / 2);

        long int **p1 = create(num / 2);
        long int **p2 = create(num / 2);
        long int **p3 = create(num / 2);
        long int **p4 = create(num / 2);
        long int **p5 = create(num / 2);
        long int **p6 = create(num / 2);
        long int **p7 = create(num / 2);

        strassen(s1, s2, p1, num / 2);
        strassen(s3, b11, p2, num / 2);
        strassen(a11, s4, p3, num / 2);
        strassen(a22, s5, p4, num / 2);
        strassen(s6, b22, p5, num / 2);
        strassen(s7, s8, p6, num / 2);
        strassen(s9, s10, p7, num / 2);

        //merge
        long int **c11 = create(num / 2);
        long int **c12 = create(num / 2);
        long int **c21 = create(num / 2);
        long int **c22 = create(num / 2);
        long int **temp1 = create(num / 2);
        long int **temp2 = create(num / 2);
        long int **temp3 = create(num / 2);
        long int **temp4 = create(num / 2);

        addmatrix(p1, p4, temp1, num / 2);
        submatrix(p7, p5, temp2, num / 2);
        addmatrix(temp1, temp2, c11, num / 2);
        addmatrix(p3, p5, c12, num / 2);
        addmatrix(p2, p4, c21, num / 2);
        addmatrix(p3, p6, temp3, num / 2);
        submatrix(p1, p2, temp4, num / 2);
        addmatrix(temp3, temp4, c22, num / 2);

        matrixmerge(result, c11, c12, c21, c22, num);

        // freematrix(c11,num/2);
        // freematrix(c12,num/2);
        // freematrix(c21,num/2);
        // freematrix(c22,num/2);
        // freematrix(temp1,num/2);
        // freematrix(temp2,num/2);
        // freematrix(temp3,num/2);
        // freematrix(temp4,num/2);
        // freematrix(p1,num/2);
        // freematrix(p2,num/2);
        // freematrix(p3,num/2);
        // freematrix(p4,num/2);
        // freematrix(p5,num/2);
        // freematrix(p6,num/2);
        // freematrix(p7,num/2);
        // freematrix(s1,num/2);
        // freematrix(s2,num/2);
        // freematrix(s3,num/2);
        // freematrix(s4,num/2);
        // freematrix(s5,num/2);
        // freematrix(s6,num/2);
        // freematrix(s7,num/2);
        // freematrix(s8,num/2);
        // freematrix(s9,num/2);
        // freematrix(s10,num/2);
        // freematrix(a11,num/2);
        // freematrix(a12,num/2);
        // freematrix(a21,num/2);
        // freematrix(a22,num/2);
        // freematrix(b11,num/2);
        // freematrix(b12,num/2);
        // freematrix(b21,num/2);
        // freematrix(b22,num/2);
    }
}

void addmatrix(long int **a, long int **b, long int **result, int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}
void submatrix(long int **a, long int **b, long int **result, int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrixsplit(long int **a, long int **a11, long int **a12, long int **a21, long int **a22, int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][num + j];
            a21[i][j] = a[num + i][j];
            a22[i][j] = a[num + i][num + j];
        }
    }
}

void matrixmerge(long int **result, long int **a11, long int **a12, long int **a21, long int **a22, int numofresult)
{
    int i, j;
    for (i = 0; i < numofresult / 2; i++)
    {
        for (j = 0; j < numofresult / 2; j++)
        {
            result[i][j] = a11[i][j];
            result[i][numofresult / 2 + j] = a12[i][j];
            result[i + numofresult / 2][j] = a21[i][j];
            result[i + numofresult / 2][numofresult / 2 + j] = a22[i][j];
        }
    }
}

int maxpower(int num)
{
    int i, pow = 1;
    for (i = 0; i < 10; i++)
    {
        if (pow >= num)
        {
            num = pow;
            break;
        }
        pow *= 2;
    }
    return num;
}

void freematrix(long int **m, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        free(m[i]);
    }
    free(m);
}

void initial(long int **a, int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            a[i][j] = 0;
        }
    }
}

void printmatrix(long int **a, int num)
{
    int i, j;
    printf("\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%li ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    // method 1;
    int time1 = func1() / CLOCKS_PER_SEC * 1000;
    // int time1 = func1();
    // method 2;
    int time2 = func2() / CLOCKS_PER_SEC * 1000;
    // int time2 = func1();
    FILE *fptime = fopen("output_p2.txt", "w");
    fprintf(fptime, "%d %d", time1, time2);
    return 0;
}
