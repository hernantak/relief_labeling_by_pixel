#include <iostream>
#include <sstream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

string file_name = "P8151391-01";
string extension = ".png";

int label_bg, label_human, label_building, label_animal, label_vegetation, label_artefak, label_decoration;
int bg_val[3],
	human_val1[3], human_val2[3], human_val3[3], human_val4[3], human_val5[3], human_val6[3],
	human_val7[3], human_val8[3], human_val9[3], human_val10[3], human_val11[3], human_val12[3],
	human_val13[3], human_val14[3], human_val15[3], human_val16[3], human_val17[3], human_val18[3],
	building_val1[3], building_val2[3], building_val3[3], building_val4[3], building_val5[3], building_val6[3],
	animal_val1[3], animal_val2[3], animal_val3[3], animal_val4[3], animal_val5[3], animal_val6[3],
	animal_val7[3], animal_val8[3], animal_val9[3], animal_val10[3], animal_val11[3], animal_val12[3],	
	vegetation_val1[3], vegetation_val2[3], vegetation_val3[3], vegetation_val4[3], vegetation_val5[3], vegetation_val6[3],
	artefak_val1[3], artefak_val2[3], artefak_val3[3], artefak_val4[3], artefak_val5[3], artefak_val6[3],
	artefak_val7[3], artefak_val8[3], artefak_val9[3], artefak_val10[3], artefak_val11[3], artefak_val12[3],	
	decoration_val1[3], decoration_val2[3], decoration_val3[3], decoration_val4[3], decoration_val5[3], decoration_val6[3];

void saveToXML(cv::Mat &_image_in){
	FileStorage fs;
	// FileStorage fs("in.xml", FileStorage::WRITE);
	// if (!fs.isOpened()){
	fs.open(file_name + "_label.xml", FileStorage::WRITE);
	fs << file_name + "_label" << _image_in;
	fs.release();
	// }
}

void loadConfig(){
	FileStorage fs2("config.yml", FileStorage::READ);

// value label
	fs2["label"]["background"] >> label_bg;
	fs2["label"]["human"] >> label_human;
	fs2["label"]["building"] >> label_building;
	fs2["label"]["animal"] >> label_animal;
	fs2["label"]["vegetation"] >> label_vegetation;
	fs2["label"]["artefak"] >> label_artefak;
	fs2["label"]["decoration"] >> label_decoration;

// value rgb label
	//for background
	FileNode tm_background = fs2["background"];
	FileNodeIterator it_background1 = tm_background["val"].begin();
	for(int k = 0; k < 3; k++, ++it_background1)
		bg_val[k] = ((int)*it_background1);

	//for human
	FileNode tm_human = fs2["human"];
	FileNodeIterator it_human1 = tm_human["val1"].begin();
	for(int k = 0; k < 3; k++, ++it_human1)
		human_val1[k] = ((int)*it_human1);

	FileNodeIterator it_human2 = tm_human["val2"].begin();
	for(int k = 0; k < 3; k++, ++it_human2)
		human_val2[k] = ((int)*it_human2);

	FileNodeIterator it_human3 = tm_human["val3"].begin();
	for(int k = 0; k < 3; k++, ++it_human3)
		human_val3[k] = ((int)*it_human3);		

	FileNodeIterator it_human4 = tm_human["val4"].begin();
	for(int k = 0; k < 3; k++, ++it_human4)
		human_val4[k] = ((int)*it_human4);

	FileNodeIterator it_human5 = tm_human["val5"].begin();
	for(int k = 0; k < 3; k++, ++it_human5)
		human_val5[k] = ((int)*it_human5);

	FileNodeIterator it_human6 = tm_human["val6"].begin();
	for(int k = 0; k < 3; k++, ++it_human6)
		human_val6[k] = ((int)*it_human6);

	FileNodeIterator it_human7 = tm_human["val7"].begin();
	for(int k = 0; k < 3; k++, ++it_human7)
		human_val7[k] = ((int)*it_human7);

	FileNodeIterator it_human8 = tm_human["val8"].begin();
	for(int k = 0; k < 3; k++, ++it_human8)
		human_val8[k] = ((int)*it_human8);

	FileNodeIterator it_human9 = tm_human["val9"].begin();
	for(int k = 0; k < 3; k++, ++it_human9)
		human_val9[k] = ((int)*it_human9);		

	FileNodeIterator it_human10 = tm_human["val10"].begin();
	for(int k = 0; k < 3; k++, ++it_human10)
		human_val10[k] = ((int)*it_human10);

	FileNodeIterator it_human11 = tm_human["val11"].begin();
	for(int k = 0; k < 3; k++, ++it_human11)
		human_val11[k] = ((int)*it_human11);

	FileNodeIterator it_human12 = tm_human["val12"].begin();
	for(int k = 0; k < 3; k++, ++it_human12)
		human_val12[k] = ((int)*it_human12);

	FileNodeIterator it_human13 = tm_human["val13"].begin();
	for(int k = 0; k < 3; k++, ++it_human13)
		human_val13[k] = ((int)*it_human13);

	FileNodeIterator it_human14 = tm_human["val14"].begin();
	for(int k = 0; k < 3; k++, ++it_human14)
		human_val14[k] = ((int)*it_human14);

	FileNodeIterator it_human15 = tm_human["val15"].begin();
	for(int k = 0; k < 3; k++, ++it_human15)
		human_val15[k] = ((int)*it_human15);		

	FileNodeIterator it_human16 = tm_human["val16"].begin();
	for(int k = 0; k < 3; k++, ++it_human16)
		human_val16[k] = ((int)*it_human16);

	FileNodeIterator it_human17 = tm_human["val17"].begin();
	for(int k = 0; k < 3; k++, ++it_human17)
		human_val17[k] = ((int)*it_human17);

	FileNodeIterator it_human18 = tm_human["val18"].begin();
	for(int k = 0; k < 3; k++, ++it_human18)
		human_val18[k] = ((int)*it_human18);				

	//for building
	FileNode tm_building = fs2["building"];
	FileNodeIterator it_building1 = tm_building["val1"].begin();
	for(int k = 0; k < 3; k++, ++it_building1)
		building_val1[k] = ((int)*it_building1);

	FileNodeIterator it_building2 = tm_building["val2"].begin();
	for(int k = 0; k < 3; k++, ++it_building2)
		building_val2[k] = ((int)*it_building2);

	FileNodeIterator it_building3 = tm_building["val3"].begin();
	for(int k = 0; k < 3; k++, ++it_building3)
		building_val3[k] = ((int)*it_building3);		

	FileNodeIterator it_building4 = tm_building["val4"].begin();
	for(int k = 0; k < 3; k++, ++it_building4)
		building_val4[k] = ((int)*it_building4);

	FileNodeIterator it_building5 = tm_building["val5"].begin();
	for(int k = 0; k < 3; k++, ++it_building5)
		building_val5[k] = ((int)*it_building5);

	FileNodeIterator it_building6 = tm_building["val6"].begin();
	for(int k = 0; k < 3; k++, ++it_building6)
		building_val6[k] = ((int)*it_building6);	

	//for animal
	FileNode tm_animal = fs2["animal"];
	FileNodeIterator it_animal1 = tm_animal["val1"].begin();
	for(int k = 0; k < 3; k++, ++it_animal1)
		animal_val1[k] = ((int)*it_animal1);

	FileNodeIterator it_animal2 = tm_animal["val2"].begin();
	for(int k = 0; k < 3; k++, ++it_animal2)
		animal_val2[k] = ((int)*it_animal2);

	FileNodeIterator it_animal3 = tm_animal["val3"].begin();
	for(int k = 0; k < 3; k++, ++it_animal3)
		animal_val3[k] = ((int)*it_animal3);		

	FileNodeIterator it_animal4 = tm_animal["val4"].begin();
	for(int k = 0; k < 3; k++, ++it_animal4)
		animal_val4[k] = ((int)*it_animal4);

	FileNodeIterator it_animal5 = tm_animal["val5"].begin();
	for(int k = 0; k < 3; k++, ++it_animal5)
		animal_val5[k] = ((int)*it_animal5);

	FileNodeIterator it_animal6 = tm_animal["val6"].begin();
	for(int k = 0; k < 3; k++, ++it_animal6)
		animal_val6[k] = ((int)*it_animal6);

	FileNodeIterator it_animal7 = tm_animal["val7"].begin();
	for(int k = 0; k < 3; k++, ++it_animal7)
		animal_val7[k] = ((int)*it_animal7);

	FileNodeIterator it_animal8 = tm_animal["val8"].begin();
	for(int k = 0; k < 3; k++, ++it_animal8)
		animal_val8[k] = ((int)*it_animal8);

	FileNodeIterator it_animal9 = tm_animal["val9"].begin();
	for(int k = 0; k < 3; k++, ++it_animal9)
		animal_val9[k] = ((int)*it_animal9);		

	FileNodeIterator it_animal10 = tm_animal["val10"].begin();
	for(int k = 0; k < 3; k++, ++it_animal10)
		animal_val10[k] = ((int)*it_animal10);

	FileNodeIterator it_animal11 = tm_animal["val11"].begin();
	for(int k = 0; k < 3; k++, ++it_animal11)
		animal_val11[k] = ((int)*it_animal11);

	FileNodeIterator it_animal12 = tm_animal["val12"].begin();
	for(int k = 0; k < 3; k++, ++it_animal12)
		animal_val12[k] = ((int)*it_animal12);		

	//for vegetation
	FileNode tm_vegetation = fs2["vegetation"];
	FileNodeIterator it_vegetation1 = tm_vegetation["val1"].begin();
	for(int k = 0; k < 3; k++, ++it_vegetation1)
		vegetation_val1[k] = ((int)*it_vegetation1);

	FileNodeIterator it_vegetation2 = tm_vegetation["val2"].begin();
	for(int k = 0; k < 3; k++, ++it_vegetation2)
		vegetation_val2[k] = ((int)*it_vegetation2);

	FileNodeIterator it_vegetation3 = tm_vegetation["val3"].begin();
	for(int k = 0; k < 3; k++, ++it_vegetation3)
		vegetation_val3[k] = ((int)*it_vegetation3);		

	FileNodeIterator it_vegetation4 = tm_vegetation["val4"].begin();
	for(int k = 0; k < 3; k++, ++it_vegetation4)
		vegetation_val4[k] = ((int)*it_vegetation4);

	FileNodeIterator it_vegetation5 = tm_vegetation["val5"].begin();
	for(int k = 0; k < 3; k++, ++it_vegetation5)
		vegetation_val5[k] = ((int)*it_vegetation5);

	FileNodeIterator it_vegetation6 = tm_vegetation["val6"].begin();
	for(int k = 0; k < 3; k++, ++it_vegetation6)
		vegetation_val6[k] = ((int)*it_vegetation6);	

	//for artefak
	FileNode tm_artefak = fs2["artefak"];
	FileNodeIterator it_artefak1 = tm_artefak["val1"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak1)
		artefak_val1[k] = ((int)*it_artefak1);

	FileNodeIterator it_artefak2 = tm_artefak["val2"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak2)
		artefak_val2[k] = ((int)*it_artefak2);

	FileNodeIterator it_artefak3 = tm_artefak["val3"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak3)
		artefak_val3[k] = ((int)*it_artefak3);		

	FileNodeIterator it_artefak4 = tm_artefak["val4"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak4)
		artefak_val4[k] = ((int)*it_artefak4);

	FileNodeIterator it_artefak5 = tm_artefak["val5"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak5)
		artefak_val5[k] = ((int)*it_artefak5);

	FileNodeIterator it_artefak6 = tm_artefak["val6"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak6)
		artefak_val6[k] = ((int)*it_artefak6);

	FileNodeIterator it_artefak7 = tm_artefak["val7"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak7)
		artefak_val7[k] = ((int)*it_artefak7);

	FileNodeIterator it_artefak8 = tm_artefak["val8"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak8)
		artefak_val8[k] = ((int)*it_artefak8);

	FileNodeIterator it_artefak9 = tm_artefak["val9"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak9)
		artefak_val9[k] = ((int)*it_artefak9);		

	FileNodeIterator it_artefak10 = tm_artefak["val10"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak10)
		artefak_val10[k] = ((int)*it_artefak10);

	FileNodeIterator it_artefak11 = tm_artefak["val11"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak11)
		artefak_val11[k] = ((int)*it_artefak11);

	FileNodeIterator it_artefak12 = tm_artefak["val12"].begin();
	for(int k = 0; k < 3; k++, ++it_artefak12)
		artefak_val12[k] = ((int)*it_artefak12);

	//for decoration
	FileNode tm_decoration = fs2["decoration"];
	FileNodeIterator it_decoration1 = tm_decoration["val1"].begin();
	for(int k = 0; k < 3; k++, ++it_decoration1)
		decoration_val1[k] = ((int)*it_decoration1);

	FileNodeIterator it_decoration2 = tm_decoration["val2"].begin();
	for(int k = 0; k < 3; k++, ++it_decoration2)
		decoration_val2[k] = ((int)*it_decoration2);

	FileNodeIterator it_decoration3 = tm_decoration["val3"].begin();
	for(int k = 0; k < 3; k++, ++it_decoration3)
		decoration_val3[k] = ((int)*it_decoration3);		

	FileNodeIterator it_decoration4 = tm_decoration["val4"].begin();
	for(int k = 0; k < 3; k++, ++it_decoration4)
		decoration_val4[k] = ((int)*it_decoration4);

	FileNodeIterator it_decoration5 = tm_decoration["val5"].begin();
	for(int k = 0; k < 3; k++, ++it_decoration5)
		decoration_val5[k] = ((int)*it_decoration5);

	FileNodeIterator it_decoration6 = tm_decoration["val6"].begin();
	for(int k = 0; k < 3; k++, ++it_decoration6)
		decoration_val6[k] = ((int)*it_decoration6);						
}

int main(void) {
	loadConfig();

	Mat image = imread(file_name + extension);
	// resize(image, image, cv::Size(320,240));
	int num_cols = image.cols;
	int num_rows = image.rows;	

	Mat out_label = cv::Mat::zeros(image.size().height, image.size().width, CV_8UC1);

	while (true)
	{
		for(int i = 0; i < num_rows; i++){
			cv::Vec3b* out_segment_ptr = image.ptr<cv::Vec3b>(i);
			uchar* out_ptr = out_label.ptr<uchar>(i);
			for(int j = 0; j < num_cols; j++){
				for(int k = 0; k<3; k++){
					//human
					if(out_segment_ptr[j][k] == human_val1[k] || out_segment_ptr[j][k] == human_val2[k] || 
						out_segment_ptr[j][k] == human_val3[k] || out_segment_ptr[j][k] == human_val4[k] || 
						out_segment_ptr[j][k] == human_val5[k] || out_segment_ptr[j][k] == human_val6[k] ||
						out_segment_ptr[j][k] == human_val7[k] || out_segment_ptr[j][k] == human_val8[k] || 
						out_segment_ptr[j][k] == human_val9[k] || out_segment_ptr[j][k] == human_val10[k] || 
						out_segment_ptr[j][k] == human_val11[k] || out_segment_ptr[j][k] == human_val12[k] ||
						out_segment_ptr[j][k] == human_val13[k] || out_segment_ptr[j][k] == human_val14[k] || 
						out_segment_ptr[j][k] == human_val15[k] || out_segment_ptr[j][k] == human_val16[k] || 
						out_segment_ptr[j][k] == human_val17[k] || out_segment_ptr[j][k] == human_val18[k]
					)
						out_ptr[j] = label_human;

					//building
					else if(out_segment_ptr[j][k] == building_val1[k] || out_segment_ptr[j][k] == building_val2[k] || 
						out_segment_ptr[j][k] == building_val3[k] || out_segment_ptr[j][k] == building_val4[k] || 
						out_segment_ptr[j][k] == building_val5[k] || out_segment_ptr[j][k] == building_val6[k] 
					)
						out_ptr[j] = label_building;

					//animal
					else if(out_segment_ptr[j][k] == animal_val1[k] || out_segment_ptr[j][k] == animal_val2[k] || 
						out_segment_ptr[j][k] == animal_val3[k] || out_segment_ptr[j][k] == animal_val4[k] || 
						out_segment_ptr[j][k] == animal_val5[k] || out_segment_ptr[j][k] == animal_val6[k] ||
						out_segment_ptr[j][k] == animal_val7[k] || out_segment_ptr[j][k] == animal_val8[k] || 
						out_segment_ptr[j][k] == animal_val9[k] || out_segment_ptr[j][k] == animal_val10[k] || 
						out_segment_ptr[j][k] == animal_val11[k] || out_segment_ptr[j][k] == animal_val12[k] 
					)
						out_ptr[j] = label_animal;		

					//vegetation
					else if(out_segment_ptr[j][k] == vegetation_val1[k] || out_segment_ptr[j][k] == vegetation_val2[k] || 
						out_segment_ptr[j][k] == vegetation_val3[k] || out_segment_ptr[j][k] == vegetation_val4[k] || 
						out_segment_ptr[j][k] == vegetation_val5[k] || out_segment_ptr[j][k] == vegetation_val6[k] 
					)
						out_ptr[j] = label_vegetation;

					//artefak
					else if(out_segment_ptr[j][k] == artefak_val1[k] || out_segment_ptr[j][k] == artefak_val2[k] || 
						out_segment_ptr[j][k] == artefak_val3[k] || out_segment_ptr[j][k] == artefak_val4[k] || 
						out_segment_ptr[j][k] == artefak_val5[k] || out_segment_ptr[j][k] == artefak_val6[k] ||
						out_segment_ptr[j][k] == artefak_val7[k] || out_segment_ptr[j][k] == artefak_val8[k] || 
						out_segment_ptr[j][k] == artefak_val9[k] || out_segment_ptr[j][k] == artefak_val10[k] || 
						out_segment_ptr[j][k] == artefak_val11[k] || out_segment_ptr[j][k] == artefak_val12[k] 
					)
						out_ptr[j] = label_artefak;		

					//decoration
					else if(out_segment_ptr[j][k] == decoration_val1[k] || out_segment_ptr[j][k] == decoration_val2[k] || 
						out_segment_ptr[j][k] == decoration_val3[k] || out_segment_ptr[j][k] == decoration_val4[k] || 
						out_segment_ptr[j][k] == decoration_val5[k] || out_segment_ptr[j][k] == decoration_val6[k] 
					)
						out_ptr[j] = label_decoration;											

					//background
					else
						out_ptr[j] = label_bg;
				}	 
			}
		}
		
		imshow("Original", image);
		imshow("Label", out_label);

		char k = waitKey(0);
		if(k == 's'){
			cout << "Saved Label";
			saveToXML(out_label);
		}
		else
			break;
	
	}
	return 0;
}