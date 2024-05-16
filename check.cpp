#include <iostream>
#include <queue>

#include "check_utils.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc >= 3) {
		string genomeFile = argv[1], synthesizedFile = argv[2];
		vector<Segment> genomeSegments = readGenomeData(genomeFile), synthesizedSegments = readSynthesizedData(synthesizedFile);

		cout << "Genome segments: " << genomeSegments.size() << endl;
		cout << "Synthesized segments: " << synthesizedSegments.size() << endl;

		for (const Segment& genomeSegment : genomeSegments) {
			for (const Segment& synthesizedSegment : synthesizedSegments) {
				if (synthesizedSegment.chromosome == genomeSegment.chromosome &&
					!((synthesizedSegment.start <= genomeSegment.start && synthesizedSegment.end <= genomeSegment.start) ||
					  (synthesizedSegment.end >= genomeSegment.end && synthesizedSegment.start >= genomeSegment.end))) {
					cout << genomeSegment.name << " (" << genomeSegment.chromosome << ": " << genomeSegment.start << "-" << genomeSegment.end
						 << ") overlaps with " << synthesizedSegment.name << " (" << synthesizedSegment.chromosome << ": " << synthesizedSegment.start << "-"
						 << synthesizedSegment.end << ")" << endl;
				}
			}
		}
	} else {
		cout << "Usage: " << argv[0] << " <input file> <output file>" << endl;
		return 1;
	}

	return 0;
}