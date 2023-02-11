#ifndef MATRIXDATA_H
#define MATRIXDATA_H

#include <QObject>

typedef QVector<QVector<int> > Matrix;

class MatrixData
{
public:
    unsigned int id;
    unsigned int generationTime;
    unsigned int rows;
    unsigned int cols;
    Matrix matrix;

    inline friend QDataStream &operator << (QDataStream &out,
                                            const MatrixData &matrix)
    {
        out << (qint32) matrix.id
            << (qint32) matrix.generationTime
            << (qint32) matrix.cols
            << (qint32) matrix.rows;

        for (unsigned int row = 0; row < matrix.rows; ++row)
        {
            for (unsigned int col = 0; col < matrix.cols; ++col)
            {
                out << matrix.matrix[row][col];
            }
        }

        return out;
    }
};

#endif // MATRIXDATA_H
