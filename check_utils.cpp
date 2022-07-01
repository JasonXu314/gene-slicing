#include "check_utils.h"

std::vector<Segment> readGenomeData(const std::string& fileName) {
	std::vector<Segment> segments;
	std::ifstream file(fileName);
	std::string _;

	// std::getline(file, _);	// ignore the first (header) line
	Segment segment;
	while (file >> segment.chromosome >> segment.start >> segment.end >> segment.name) {
		segments.push_back(segment);
	}

	file.close();

	return segments;
}

std::vector<Segment> readSynthesizedData(const std::string& fileName) {
	std::vector<Segment> segments;
	std::ifstream file(fileName);
	std::string _;

	std::getline(file, _);	// ignore the first (header) line
	Segment segment;
	while (file >> segment.chromosome >> segment.start >> segment.end >> segment.name) {
		if (segment.end < segment.start) {
			std::cout << "End position before start: " << segment.name << std::endl;
		}

		segments.push_back(segment);
	}

	file.close();

	return segments;
}