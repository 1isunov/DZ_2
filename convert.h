#ifndef CONVERT_H
#define CONVERT_H
#include <QCoreApplication>
#include <QImage>
#include <QString>
#include <QDir>
#include <QColor>
#include <QRgb>
#include <QFile>
#include "matrix.h"
#include "processingimage.h"
#include "saveimage.h"

class Convert
{
private:
    static QDir beginningWay;
    static QString wayToFile;
    static QRgb pixColor;
    static QImage Image;
    static int pixColorInInt;
public:
    Convert();
    static void convertImageToBW();
    static QString giveWayToFile();
    static QImage giveConvertedImage();
};

#endif // CONVERT_H
