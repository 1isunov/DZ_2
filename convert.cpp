#include "convert.h"
#include "matrix.h"
#include "processingimage.h"
#include "saveimage.h"

Convert::Convert()
{

}

void Convert::convertImageToBW()
{
    wayToFile = beginningWay.currentPath();
    Image.load(wayToFile+"/image.png");

    for(int i = 0; i < Image.width(); i++){
        for( int j = 0; j < Image.height(); j++){
            pixColor = Image.pixel(i, j);
            pixColorInInt = pixColor;
            if(pixColorInInt > -12000000){ // значение 12 млн. взято приблизительно для отделения светлых оттенков цветов от тёмных
                Image.setPixel(i, j, qRgb( 255,  255,  255));
            }
            else{
                Image.setPixel(i, j, qRgb(0, 0, 0));
            }
        }
    }
    SaveImage::saveImage(1);
}

QString Convert::giveWayToFile()
{
    return wayToFile;
}

QImage Convert::giveConvertedImage()
{
    return Image;
}
