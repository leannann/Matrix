#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include<stdlib.h>
#include<math.h>

#define OK 0
#define ERROR 1
#define CALCULATION_ERROR 2
#define FAILURE 0
#define SUCCESS 1

typedef struct matrix_struct 
{
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

void complement(matrix_t *A, matrix_t *result);
double determinant(double **A, int size);
void support(double **A, double **tmp, int skip_row, int skip_col, int size);
int matrix_exist(int rows, int columns);
int correct_matrix(matrix_t* matrix);

#endif