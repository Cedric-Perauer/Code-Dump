#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
cv::Mat image0;

image0.create(480,640,CV_8UC1); //grayscale image 640x480

image0.setTo(0); //make image completely black
cv::Point center(image0.cols / 2, image0.rows / 2);
int radius = image0.rows / 2; 

cv::circle(image0,center,radius,128,3); //intensity 128
cv::Mat image1;
//image1 = image0;
image0.copyTo(image1);
cv::rectangle(image1,center - cv::Point(radius,radius),
center + cv::Point(radius,radius),
255,
3);
//2 images reference to the same data, if we want two different
//outputs, we need to call the copyTo function
cv::Mat image2;
cv::cvtColor(image1,image2, CV_GRAY2BGR);

int in_radius = radius / sqrt(2);

cv::Rect rect(center - cv::Point(in_radius, in_radius),
 center + cv::Point(in_radius, in_radius));

//Region of interest
cv::Mat roi = image2(rect); 

roi.setTo(cv::Scalar(0,185,118)); //make rectangle light green

for(int i = 0; i <image1.rows;i++ )
{   uchar *row = image1.ptr<uchar>(i);  //access row with ptr template function

    for(int j = 0; j < image1.cols;j++)
    { if(row[j] == 128) {
        row[j] = j*i *255 / image1.total(); //gradient effect circle
    }

    }
}

//Rectangle Gradient effect
for(int i = 0; i <image2.rows;i++ )
{   cv::Vec3b *row = image2.ptr<cv::Vec3b>(i);  //access row with ptr template function
    //cv::Vec3b array type of 3 unsigned char values
    for(int j = 0; j < image2.cols;j++)
    { if(row[j][1] == 185) {
        row[j] = cv::Vec3b(0 ,j*i *255 / image1.total(), 118); //gradient effect circle
    }

    }
}

cv::imshow("image2",image2);
cv::imshow("image1",image1);
cv::imshow("image0",image0);
cv::waitKey();

return 0;

}
