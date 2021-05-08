#include "convert.h"
#include "matrix.h"
#include "processingimage.h"
#include "saveimage.h"

Matrix::Matrix()
{

}

void Matrix::MatrixConvertedImage()
{
    ;
    wayToImage = Convert::giveWayToFile()+ "/image_new.png";
    tempImage.load(wayToImage);

    widthImage = tempImage.width();
    heightImage = tempImage.height();

    matrixImage = new int *[widthImage];
    for (int k = 0; k < widthImage; ++k)
        matrixImage[k] = new int [heightImage];

    for(int i = 0; i < widthImage; i++){
        for( int j = 0; j < heightImage; j++){

            pixColor = tempImage.pixel(i, j);
            pixColorToInt = pixColor;

            if(pixColorToInt == -16777216){
                matrixImage[i][j] = 1;
            }
            else{
                matrixImage[i][j] = 0;

            }
        }
    }
}

void Matrix::MatrixMask()
{
    wayToMask = Convert::giveWayToFile()+ "/mask.txt";
    QFile mask(wayToMask);
    mask.open(QIODevice::ReadOnly | QIODevice::Text);

    sizeMask = mask.readLine();
    positionCentralElementMask = mask.readLine();

    widthMask = sizeMask[0]-48;
    heightMask = sizeMask[2]-48;
    positionToWidthCentralElementMask = positionCentralElementMask[0] - 48;
    positionToHeightCentralElementMask = positionCentralElementMask[2] - 48;

    for(int j=0; j < heightMask; j++){
        oneLineMask = mask.readLine();
        for(int i=0; i < (widthMask-1)*2 +1; i+=2){
            matrixMask[tempCounter] = oneLineMask[i] - 48;
            tempCounter++;

        }
        oneLineMask.clear();
        positionCentralElementMask.clear();
        sizeMask.clear();
    }
    mask.close();
}

int *Matrix::giveMatrixMask()
{
    return matrixMask;
}

int Matrix::givepositionToHeightCentralElementMask()
{
    return positionToHeightCentralElementMask;
}

int Matrix::givepositionToWidthCentralElementMask()
{
    return positionToWidthCentralElementMask;
}

int **Matrix::giveMatrixImage()
{
    return matrixImage;
}
