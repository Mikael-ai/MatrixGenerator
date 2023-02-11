#ifndef GENERATORUTILS_H
#define GENERATORUTILS_H

#include <QObject>
class MatrixData;

class GeneratorUtils
{
private:
    unsigned long generationNumber;
    static GeneratorUtils *p_generatorInstance;

private:
    GeneratorUtils();

public:
    static GeneratorUtils* getGeneratorInstance();

    MatrixData generateMatrix(const unsigned int rows,
                              const unsigned int cols);

    void writeMatrixDataToFile(const MatrixData &matrix,
                               const QString path);
};

#endif // GENERATORUTILS_H
