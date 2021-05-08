#ifndef SAVEIMAGE_H
#define SAVEIMAGE_H
#include "convert.h"
#include "matrix.h"
#include "processingimage.h"

class SaveImage
{
private:
    static QString tempWayToFile;
    static QImage tempImage;

public:
    SaveImage();
    static void saveImage(int type);
};

#endif // SAVEIMAGE_H
