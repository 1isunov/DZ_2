#include "convert.h"
#include "matrix.h"
#include "processingimage.h"
#include "saveimage.h"

ProcessingImage::ProcessingImage()
{

}

void ProcessingImage::erosionImage()
{
    tempImage = Convert::giveConvertedImage();
    heightImage = tempImage.height();
    widthImage = tempImage.width();
    tempMatrix = Matrix::giveMatrixImage();

    matrixErosion = new int *[widthImage];
    for (int k = 0; k < widthImage; k++)
        matrixErosion[k] = new int [heightImage];


    for(int i = 0; i < widthImage; i++){
        for( int j = 0; j < heightImage; j++){
            matrixErosion[i][j] =  tempMatrix[i][j];
        }
    }

    heightMask = Matrix::giveHeightMask();
    widthMask = Matrix::giveWidthMask();
    matrixMask = Matrix::giveMatrixMask();
    positionToWidhtCentralElementMask = Matrix::givepositionToWidthCentralElementMask();
    positionToHeightCentralElementMask = Matrix::givepositionToHeightCentralElementMask();

    for(int i = 0; i < widthImage-2; i++){
        for(int j = 0; j < heightImage-2; j++){
            tempCounter = 0;
            for(int k = 0; k < widthMask; k++){
                for(int l = 0; l < heightMask; l ++){
                    if((tempMatrix[i+k][j+l] !=matrixMask[tempCounter]) && (matrixMask[tempCounter]==1)){
                        matrixErosion[i+positionToWidhtCentralElementMask][j+positionToHeightCentralElementMask] = 0;
                    }
                    tempCounter++;
                }
            }
        }
    }

    for(int i = 0; i< widthImage; i++){
        for(int j = 0; j < heightImage; j++){
            if(matrixErosion[i][j] == 1){
                tempImage.setPixel(i, j, qRgb( 0, 0, 0));
            }
            else{
                tempImage.setPixel(i, j, qRgb(255,  255,  255));
            }

        }
    }

    SaveImage::saveImage(3);
}

void ProcessingImage::delatationImage()
{
    tempImage = Convert::giveConvertedImage();
    heightImage = tempImage.height();
    widthImage = tempImage.width();
    tempMatrix = Matrix::giveMatrixImage();

    matrixDelatation = new int *[widthImage];
    for (int k = 0; k < widthImage; k++)
        matrixDelatation[k] = new int [heightImage];

    for(int i = 0; i < widthImage; i++){
        for( int j = 0; j < heightImage; j++){
            matrixDelatation[i][j] =  tempMatrix[i][j];
        }
    }

    heightMask = Matrix::giveHeightMask();
    widthMask = Matrix::giveWidthMask();
    matrixMask = Matrix::giveMatrixMask();
    positionToWidhtCentralElementMask = Matrix::givepositionToWidthCentralElementMask();
    positionToHeightCentralElementMask = Matrix::givepositionToHeightCentralElementMask();

    for(int i = 0; i < widthImage-2; i++){
        for(int j = 0; j < heightImage-2; j++){
            if(tempMatrix[i+positionToWidhtCentralElementMask][j+positionToHeightCentralElementMask] == matrixMask[positionToWidhtCentralElementMask*widthMask+positionToHeightCentralElementMask]){
                matrixDelatation[i+1][j] = 1;
                matrixDelatation[i][j+1] = 1;
                matrixDelatation[i+2][j+1] = 1;
                matrixDelatation[i+1][j+2] = 1;
            }
        }

    }

    for(int i = 0; i< widthImage; i++){
        for(int j = 0; j < heightImage; j++){
            if(matrixDelatation[i][j] == 1){
                tempImage.setPixel(i, j, qRgb( 0, 0, 0));
            }
            else{
                tempImage.setPixel(i, j, qRgb(255,  255,  255));
            }

        }
    }
    SaveImage::saveImage(2);
}

void ProcessingImage::outlineImage()
{

    matrixOutline = new int *[widthImage];
    for (int k = 0; k < widthImage; k++)
        matrixOutline[k] = new int [heightImage];

    for( int i = 0; i< widthImage; i ++){
        for(int j = 0; j < heightImage; j++){
            if((matrixDelatation[i][j] == 1) && (matrixErosion[i][j] == 0)){
                matrixOutline[i][j] = 1;
            }
            else{
                matrixOutline[i][j] = 0;
            }
        }
    }

    for(int i = 0; i< widthImage; i++){
        for(int j = 0; j < heightImage; j++){
            if(matrixOutline[i][j] == 1){
                tempImage.setPixel(i, j, qRgb( 0, 0, 0));
            }
            else{
                tempImage.setPixel(i, j, qRgb(255,  255,  255));
            }

        }
    }
}
