#include <QCoreApplication>
#include <generatorutils.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GeneratorUtils *generatorUtils = GeneratorUtils::getGeneratorInstance();
    generatorUtils->generateMatrix(1, 2);
    delete generatorUtils;

    return a.exec();
}
