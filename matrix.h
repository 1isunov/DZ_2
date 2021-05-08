#ifndef MATRIX_H
#define MATRIX_H
#include "convert.h"
#include "processingimage.h"
#include "saveimage.h"
class Matrix
{
private:
    // для изображения
    static QString wayToImage;
    static int heightImage;
    static int widthImage;
    static QRgb pixColor;
    static QImage tempImage;
    static int** matrixImage;
    static int pixColorToInt;

    // для маски :
    static int positionToHeightCentralElementMask;
    static int positionToWidthCentralElementMask;
    static QString wayToMask;
    static QByteArray sizeMask;
    static int heightMask;
    static int widthMask;
    static QByteArray positionCentralElementMask;
    static QByteArray oneLineMask;
    static int* matrixMask;
    static int tempCounter;
public:
    Matrix();
    static void MatrixConvertedImage();
    static void MatrixMask();
    static int** giveMatrixImage();
    static int* giveMatrixMask();
    static int giveHeightMask();
    static int giveWidthMask();
    static int givepositionToHeightCentralElementMask();
    static int givepositionToWidthCentralElementMask();
};

#endif // MATRIX_H
