#include "convert.h"
#include "matrix.h"
#include "processingimage.h"
#include "saveimage.h"

SaveImage::SaveImage()
{

}

void SaveImage::saveImage(int type) // сохранение: 1-конвертированной, 2-делатации, 3-эрозии, 4-контура изображения
{
    tempWayToFile = Convert::giveWayToFile();
    tempImage = Convert::giveConvertedImage();
    switch(type)
    {
    case 1:
        tempImage.save(tempWayToFile+"/ConvertedImage.png");

    case 2:
        tempImage.save(tempWayToFile+"/DilatationImage.png");

    case 3:
        tempImage.save(tempWayToFile+"/ErosionImage.png");

    case 4:
        tempImage.save(tempWayToFile+"/OutlineImage.png");
    }
}
