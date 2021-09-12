#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void saveToXML(cv::Mat &_image_in){
	FileStorage fs;
	// FileStorage fs("CamModel.xml", FileStorage::WRITE);
	// if (!fs.isOpened()){
		fs.open("Table_warna.xml", FileStorage::WRITE);
		fs << "Table_warna" << _image_in;
		fs.release();
	// }
}

int main(void) {

	Mat image = imread("P8151391-01.png", 1);
	resize(image, image, cv::Size(320,240));
	// cvtColor(image, image, COLOR_RGB2BGR);

	int count = 1;

	while (true)
	{

		// imshow("image", image);

		int num_cols = image.cols;
		int num_rows = image.rows;
		int red, green, blue;

		for(int i = 0; i < num_rows; i++){
			cv::Vec3b* out_segment_ptr = image.ptr<cv::Vec3b>(i);
			for(int j = 0; j < num_cols; j++){
				red = int(out_segment_ptr[j][0]);
				green = int(out_segment_ptr[j][1]);
				blue = int(out_segment_ptr[j][2]);  
// 157 73 113
// 133 45 87
				if(red == 157 && green == 73 && blue == 113){
					// cout << "Oke";
					out_segment_ptr[j][0] = 255;  
					out_segment_ptr[j][1] = 255;  
					out_segment_ptr[j][2] = 255;  
				}  
					 
			}
		}

		// saveToXML(image);

		// imwrite("boyGray.jpg", image);
		
		imshow("Grayscale image", image);
		if(waitKey(30)==27){
			break;
		}		
	}
	return 0;
}