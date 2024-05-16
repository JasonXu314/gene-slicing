#include "utils.h"

#include <limits>

SegmentQueue readGenomeData(const std::string& fileName) {
	SegmentQueue segments;
	std::ifstream file(fileName);

	// std::getline(file, _);	// ignore the first (header) line
	Segment segment;
	while (file >> segment.chromosome >> segment.start >> segment.end >> segment.name) {
		segments.emplace(segment);
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	file.close();

	return segments;
}

SegmentQueue readComplementData(const std::string& fileName, unsigned int trim) {
	SegmentQueue segments;
	std::ifstream file(fileName);

	// std::getline(file, _);	// ignore the first (header) line
	Segment segment;
	while (file >> segment.chromosome >> segment.start >> segment.end) {
		// if (segment.chromosome == "") {
		// 	std::cout << segment.start << " " << segment.end << std::endl;
		// }

		if (segment.length() > trim * 2) {
			// strip off a little of the head and tail of each segment
			segment.start += trim;
			segment.end -= trim;

			segments.emplace(segment);
		}

		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	file.close();

	return segments;
}

void writeData(const std::string& fileName, const std::vector<Segment>& segments) {
	std::ofstream file(fileName);

	file << "chromosome\tstart\tend\tname\n";
	for (const Segment& segment : segments) {
		file << segment.chromosome << "\t" << segment.start << "\t" << segment.end << "\t" << segment.name << std::endl;
	}

	file.close();
}

std::string generateOutputFileName(const std::string& fileName) {
	std::string outputFileName = fileName;
	std::size_t idx = outputFileName.find(".txt");

	if (idx != std::string::npos) {
		outputFileName.replace(idx, 4, "_out.txt");
	} else {
		outputFileName += ".out";
	}

	return outputFileName;
}

void findCandidates(std::vector<Segment>& candidates, const Segment& genomeSegment, SegmentQueue& complements, unsigned int padding) {
	while (!complements.empty() && candidates.size() < 100) {
		Segment complement = complements.top();

		if (complement.length() >= genomeSegment.length() + padding) {
			complements.pop();
			candidates.push_back(complement);
		} else {
			break;
		}
	}
}