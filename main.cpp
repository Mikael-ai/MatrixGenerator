#include <QCoreApplication>
#include <generatorutils.h>

#include "matrixdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GeneratorUtils *generatorUtils = GeneratorUtils::getGeneratorInstance();
    generatorUtils->writeMatrixDataToFile(generatorUtils->generateMatrix(3, 3),
                                          QString("D:/file.txt"));
    delete generatorUtils;

    return a.exec();
}
