#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

bool leftDown=false,leftup=false;
Mat img;
Point cor1,cor2;
Rect box;

void mouse_call(int event,int x,int y,int,void*)
{
    if(event==EVENT_LBUTTONDOWN)
    {
        leftDown=true;
        cor1.x=x;
        cor1.y=y;
        cout <<"Corner 1: "<<cor1<<endl;
     
    }
    if(event==EVENT_LBUTTONUP)
    {
        // if(abs(x-cor1.x)>20&&abs(y-cor1.y)>20) //checking whether the region is too small
        // {
            leftup=true;
            cor2.x=x;
            cor2.y=y;
            cout<<"Corner 2: "<<cor2<<endl;
        // }
        // else
        // {
        //     cout<<"Select a region more than 20 pixels"<<endl;
        // }
    }
 
    if(leftDown==true&&leftup==false) //when the left button is down
    {
        Point pt;
        pt.x=x;
        pt.y=y;
        Mat temp_img=img.clone();
        rectangle(temp_img,cor1,pt,Scalar(0,0,255)); //drawing a rectangle continuously
        imshow("Original",temp_img);
     
    }
    if(leftDown==true&&leftup==true) //when the selection is done
    {
     
        box.width=abs(cor1.x-cor2.x);
        box.height=abs(cor1.y-cor2.y);
        box.x=min(cor1.x,cor2.x);
        box.y=min(cor1.y,cor2.y);
        Mat crop(img,box); //Selecting a ROI(region of interest) from the original pic
        namedWindow("Cropped Image");
        imshow("Cropped Image",crop); //showing the cropped image
		imwrite("crop.jpg", crop);
        leftDown=false;
        leftup=false;
     
    }
 
}

void saveToXML(cv::Mat &_image_in){
	FileStorage fs;
	// FileStorage fs("CamModel.xml", FileStorage::WRITE);
	// if (!fs.isOpened()){
		fs.open("Table_warna.xml", FileStorage::WRITE);
		fs << "Table_warna" << _image_in;
		fs.release();
	// }
}

void segmentColor(cv::Mat &_image_in){
	int num_cols = _image_in.cols;
	int num_rows = _image_in.rows;
	int red, green, blue;

	for(int i = 0; i < num_rows; i++){
		cv::Vec3b* out_segment_ptr = _image_in.ptr<cv::Vec3b>(i);
		for(int j = 0; j < num_cols; j++){
			red = int(out_segment_ptr[j][0]);
			green = int(out_segment_ptr[j][1]);
			blue = int(out_segment_ptr[j][2]);  

			if(red == 112 && green == 84 && blue == 162){
				out_segment_ptr[j][0] = 0;  
				out_segment_ptr[j][1] = 0;  
				out_segment_ptr[j][2] = 0;  
			}  
					
		}
	}
}

int main(void) {

    img=imread("boy.jpg");
    namedWindow("Original");
    imshow("Original",img);
     
    setMouseCallback("Original",mouse_call); //setting the mouse callback for selecting the region with mouse
     
    while(char(waitKey(1)!='q')) //waiting for the 'q' key to finish the execution
    {
     
    }
}