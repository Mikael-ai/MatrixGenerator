#ifndef GENERATORUTILS_H
#define GENERATORUTILS_H

#include <QObject>

typedef QVector<QVector<int> > Matrix;

struct MatrixData
{
    unsigned int id;
    unsigned int generationTime;
    unsigned int rows;
    unsigned int cols;
    Matrix matrix;

    friend QDataStream &operator << (QDataStream &out,
                                     const MatrixData &matrix)
    {
        out << (qint32) matrix.id
            << (qint32) matrix.generationTime
            << (qint32) matrix.cols
            << (qint32) matrix.rows;

        for (int row = 0; row < matrix.rows; ++row)
        {
            for (int col = 0; col < matrix.cols; ++col)
            {
                out << matrix.matrix[row][col];
            }
        }

        return out;
    }
};

class GeneratorUtils : public QObject
{
    Q_OBJECT
private:
    unsigned long generationNumber;
    static GeneratorUtils *p_generatorInstance;

private:
    GeneratorUtils(QObject *parent = nullptr);

public:
    static GeneratorUtils* getGeneratorInstance();

    MatrixData generateMatrix(const unsigned int rows,
                              const unsigned int cols);

    void writeMatrixDataToFile(const MatrixData &matrix,
                               const QString path);
};

#endif // GENERATORUTILS_H
