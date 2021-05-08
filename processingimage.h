#ifndef PROCESSINGIMAGE_H
#define PROCESSINGIMAGE_H
#include "matrix.h"
#include "saveimage.h"
#include "convert.h"
#include "matrix.h"

class ProcessingImage
{
private:
    static int** matrixErosion;
    static int** tempMatrix;
    static int* matrixMask;
    static int tempCounter;
    static QImage tempImage;
    static int heightImage;
    static int widthImage;
    static int heightMask;
    static int widthMask;
    static int positionToHeightCentralElementMask;
    static int positionToWidhtCentralElementMask;
    static int** matrixDelatation;
    static int** matrixOutline;

public:
    ProcessingImage();
    static void erosionImage();
    static void delatationImage();
    static void outlineImage();
};

#endif // PROCESSINGIMAGE_H
