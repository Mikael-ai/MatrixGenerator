#include "generatorutils.h"
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QDataStream>
#include <QFile>

GeneratorUtils *GeneratorUtils::p_generatorInstance = Q_NULLPTR;

GeneratorUtils::GeneratorUtils(QObject *parent)
    : QObject{parent}
{
    generationNumber = 0;
}

GeneratorUtils* GeneratorUtils::getGeneratorInstance()
{
    if (!p_generatorInstance)
        return new GeneratorUtils();

    return p_generatorInstance;
}

MatrixData GeneratorUtils::generateMatrix(const unsigned int rows,
                                          const unsigned int cols)
{
    QElapsedTimer timer;
    timer.start();

    Matrix matrix(rows, QVector<int>(cols));
    for (unsigned int row = 0; row < rows; ++row)
    {
        for (unsigned int col = 0; col < cols; ++col)
        {
            // Assign random value to each element of the matrix
            matrix[row][col] = QRandomGenerator::global()->generate();
        }
    }
    // Measure the generation time
    unsigned int generationTime = timer.elapsed();
    timer.invalidate();

    return MatrixData { generationNumber++, generationTime, rows, cols, matrix };
}

void GeneratorUtils::writeMatrixDataToFile(const MatrixData &matrix,
                                           const QString path)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    if (!file.isOpen())
        return;

    QDataStream out(&file);
    out << matrix;

    file.close();
}

