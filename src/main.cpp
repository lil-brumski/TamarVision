#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <vector>
#include <filesystem>

#include "TamarVision.h"
#include <opencv2/opencv.hpp>

std::string Time() {
	std::time_t now = std::time(0);
	std::tm* localTime = std::localtime(&now);

	std::ostringstream oss;
	oss << std::put_time(localTime, "%I:%M %p %d/%m/%Y");

	std::string value = oss.str();

	return value;
}

int main(int argc, char **arg_char) {
	std::vector<std::string> argv(arg_char, arg_char + argc);
	std::string location = "";

	std::vector<std::string> TV_options = {
		"TamarVision --version",
		"TamarVision <path_to_image>",
		"TamarVision --help"
	};

	// Alternative to if-else statements for those who might not know, lol!
	switch (argc) {
	case 1:
		std::cout << "Made by David Tamaratare Oghenebrume\n" << 
			"Usage:\n" << "\n    Run \'TamarVision --help\' for more information.\n";
		return 0;
		break;
	case 2:
		if (argv[1] == "--version" || argv[1] == "--v" || argv[1] == "--V") {
			std::cout << "TamarVision version: " << TamarVision_VERSION_MAJOR << "." <<
				TamarVision_VERSION_MINOR << "." <<
				TamarVision_VERSION_PATCH << "\n\n" <<
				"Made by David Tamaratare Oghenebrume\n";
			return 0;
		}
		else if (argv[1] == "--help" || argv[1] == "--h") {
			std::cout << "Made by David Tamaratare Oghenebrume\n" <<
				"\nTamarVision is a computer-vision-based application that was made using OpenCV and the C++ programming language.\n" <<
				"This application was made for the purpose of displaying images from the command line.\n\n" <<

				"TamarVision options:\n\n";
			for (const auto& option : TV_options) {
				std::cout << "    " << option << "\n";
			}
			return 0;
		}
		else if (std::filesystem::exists(argv[1])) {
			location = argv[1];
		}
		else{ 
			std::cout << "Invalid parameters!\n";
			return 0;
		}
		break;
	default:
		std::cout << "Invalid amount of parameters!\n";
		return 0;
		break;
	}

	std::string windowName = "TamarVision " + Time();

	cv::Mat image = cv::imread(location);

	if (image.empty()) {
		std::cout << "Error, cannot open image.\n";
		return -1;
	}
	cv::resize(image, image, cv::Size(800, 600));

	cv::imshow(windowName, image);

	cv::waitKey(0);
	cv::destroyAllWindows();
}