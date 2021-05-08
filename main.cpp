#include "convert.h"
#include "matrix.h"
#include "processingimage.h"

int main()
{
    Convert a;
    a.convertImageToBW();

    Matrix b;
    b.MatrixConvertedImage();
    b.MatrixMask();

    ProcessingImage c;
    c.delatationImage();
    c.erosionImage();
    c.outlineImage();
}
