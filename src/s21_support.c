#include "s21_matrix.h"

double determinant(double **A, int size) {
  double result = OK;
  matrix_t tmp = {0};

  if (size == 1)

    result = A[0][0];

  else {
    if (s21_create_matrix(size, size, &tmp))
      return CALCULATION_ERROR;

    else {
      int sign = 1;

      for (int i = 0; i < size; i++) {
        support(A, tmp.matrix, 0, i, size);
        result += sign * A[0][i] * determinant(tmp.matrix, size - 1);
        sign = -sign;
      }
    }
  }

  s21_remove_matrix(&tmp);

  return result;
}

void support(double **A, double **tmp, int skip_row, int skip_col, int size) {
  for (int i = 0, row = 0; row < size; ++row)

    for (int j = 0, col = 0; col < size; ++col)

      if (row != skip_row && col != skip_col) {
        tmp[i][j] = A[row][col];
        j++;

        if (j == size - 1) {
          j = 0;
          i++;
        }
      }
}

void complement(matrix_t *A, matrix_t *result) {
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
    return;
  }

  matrix_t tmp = {0};

  if (s21_create_matrix(A->rows, A->rows, &tmp)) return;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      support(A->matrix, tmp.matrix, i, j, A->rows);
      int sign = ((i + j) % 2 == 0) ? 1 : -1;
      result->matrix[i][j] = sign * determinant(tmp.matrix, A->rows - 1);
    }
  }

  s21_remove_matrix(&tmp);
}

int matrix_exist(int rows, int columns) {
  int status = OK;

  if (rows <= 0 || columns <= 0) status = ERROR;

  return status;
}

int correct_matrix(matrix_t *matrix) {
  int status = OK;

  if (!(matrix && matrix->rows > 0 && matrix->columns > 0)) status = ERROR;

  return status;
}