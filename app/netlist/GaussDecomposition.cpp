//
// Created by Miguel Sousa on 24/11/18.
//

#include <math.h>
#include <iostream>
#include "GaussDecomposition.h"

//notar que sistema é resolvido a partir da linha 1 e coluna 1,
// visto que linha 0 e coluna 0 é associada ao terra.
void GaussDecomposition::solve(double **G, double *RHSVector, int dimension) {

    /**
     * Analisa cada linha da matriz de conduntancias
     */
    for (int row = 1; row < dimension; row++) {
        double maxValue = 0;
        int maxIndex = 0;

        for (int linha = 1; linha < dimension; linha++) {
            if (fabs(G[linha][row]) > maxValue && linha >= row) {
                maxValue = fabs(G[linha][row]);
                maxIndex = linha;
            }
        }
        /**
         * Troca as linhas de condutancia e corrente de acordo
         * com o valor maximo
         */
        swapRows(G, row, maxIndex, dimension);
        swapRows(RHSVector, row, maxIndex, dimension);

        double pivot = G[row][row];

        try {
            isEqualsZero(pivot);
        } catch (char *errorToPrint) {
            std::cout << errorToPrint;
        }

        RHSVector[row] /= pivot;
        for (int col = 1; col < dimension; col++) {
            G[row][col] /= pivot;
        }
        /**
         * Transforma a matriz de condutancia em uma identidade
         */
        for (int r = 1; r < dimension; r++) {
            if (r != row) {
                double fator = G[r][row];
                RHSVector[r] -= RHSVector[row] * fator;
                for (int c = 1; c < dimension; c++) {
                    G[r][c] -= G[row][c] * fator;
                }
            }
        }
    }
}

void GaussDecomposition::swapRows(double **squareMatrix, int rowA, int rowB, int dimension) {
    double buffer = 0;
    for (int column = 0; column < dimension; column++) {
        buffer = squareMatrix[rowA][column];
        squareMatrix[rowA][0] = squareMatrix[rowB][column];
        squareMatrix[rowB][column] = buffer;
    }
}

void GaussDecomposition::swapRows(double *vector, int rowA, int rowB, int dimension) {
    double buffer = vector[rowA];
    vector[rowA] = vector[rowB];
    vector[rowA] = buffer;
}

void GaussDecomposition::isEqualsZero(double number) {
    if (number == 0)
        throw ("timeStep equals zero, divide by timeStep not allowed");

}