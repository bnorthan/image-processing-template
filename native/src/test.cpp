#include <iostream>
#include "tifstack.h"
#include "debugutil.h"

#ifdef _WIN64
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#define VIEW_WITH_OPENCV
#ifdef VIEW_WITH_OPENCV
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
#endif 

using namespace std;

int main() {
    cout<<"Image processing template project test.\n"<<flush; 

    char buff[FILENAME_MAX];
    GetCurrentDir( buff, FILENAME_MAX );
    cout<<"Current working dir: "<<buff<<"\n"<<flush;
   
    unsigned int size[3];

    float * data = read3DTiff("PSF32.tif", size);

    #ifdef VIEW_WITH_OPENCV

    float * rescaled = new float[size[0]*size[1]];
    rescale(data, rescaled, 1., size[0]*size[1]);

    Mat cvImg(size[0], size[1], CV_32F, rescaled);
    //namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Img", cvImg);                   // Show our image inside it.
    waitKey(0); 

    #endif 

}