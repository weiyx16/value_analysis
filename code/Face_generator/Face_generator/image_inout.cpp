#include "image_inout.h"

using namespace std;
using namespace cv;

cv::Mat image_inout::image_load()
{
	std::cout << "Loading image from " << img_path << endl;
	Mat img_in = cv::imread(img_path, 1);
	std::cout << "Finished loading" << endl;
	return img_in;
}

std::vector<Location_fea> image_inout::image_features_load()
{
	std::vector<Location_fea> fea_data;
	std::string file_path;
	file_path = img_name + ".txt";

	int num = 0;
	std::cout << "Loading image features from " << file_path << endl;

	std::ifstream fea_load;
	fea_load.open(file_path);
	if (fea_load.is_open())
	{
		while (!fea_load.eof())
		{
			Location_fea fea_point;
			fea_load >> fea_point.loc_x;
			fea_load >> fea_point.loc_y;
			fea_data.push_back(fea_point);
			num++;
			// cout << "Input:: " << num << fea_point.loc_x << ' ' << fea_point.loc_y << endl;
		}
		fea_load.close();
		std::cout << "Successfully load " << num << "points" << endl;
	}
	else std::cout << "Fail to load image features";
	fea_data.pop_back(); // Seems to have a problem of reloading the final line.
	return fea_data;
}

void image_inout::image_save(cv::Mat img_save)
{
	cv::String img_save_path = img_name + "_altered.jpg";
	std::cout << "Saving image to " << img_save_path << endl;
	cv::imwrite(img_save_path, img_save);
	std::cout << "Finished saving" << endl;
}
