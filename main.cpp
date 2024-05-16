#include <cmath>
#include <iostream>
#include <limits>
#include <queue>

#include "utils.h"

using namespace std;

int main(int argc, char** argv) {
	srand(0);

	if (argc >= 3) {
		string genomeFile = argv[1], complementFile = argv[2];
		unsigned int padding = argc >= 4 ? stoul(argv[3]) : 0;
		unsigned int trim = argc >= 5 ? stoul(argv[4]) : 5;
		SegmentQueue genomeSegments = readGenomeData(genomeFile), complementSegments = readComplementData(complementFile, trim);

		cout << "Genome segments: " << genomeSegments.size() << endl;
		cout << "Complement segments: " << complementSegments.size() << endl;

		vector<Segment> generatedSegments, candidates;

		Segment genomeSegment;
		unsigned int i = 0;
		while (!genomeSegments.empty()) {
			genomeSegment = genomeSegments.top();
			genomeSegments.pop();

			findCandidates(candidates, genomeSegment, complementSegments, padding);

			if (i % 1000000 == 0) {
				cout << i / 1000000 << endl;
			}
			if (candidates.size() == 0) {
				cout << "No more candidates" << endl;
				return 1;
			}

			unsigned int requiredLength = genomeSegment.length(), complementIdx = rand() % candidates.size();

			Segment& complementSegment = candidates[complementIdx];
			Segment generatedSegment = {genomeSegment.name + "ctrl", complementSegment.chromosome, complementSegment.start,
										complementSegment.start + requiredLength};
			complementSegment.start += requiredLength + padding;

			generatedSegments.push_back(generatedSegment);

			if (genomeSegments.top().length() + padding > complementSegment.length()) {
				complementSegments.emplace(complementSegment);
				candidates.erase(candidates.begin() + complementIdx);
			}
			i++;
		}

		writeData(generateOutputFileName(genomeFile), generatedSegments);
	} else {
		cout << "Usage: " << argv[0] << " <genome file> <complement file> [padding length] [trim length]" << endl;
		return 1;
	}

	return 0;
}