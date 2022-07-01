#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#include "Segment.h"

typedef std::priority_queue<Segment> SegmentQueue;

SegmentQueue readGenomeData(const std::string& fileName);

SegmentQueue readComplementData(const std::string& fileName, unsigned int trim);

void writeData(const std::string& fileName, const std::vector<Segment>& segments);

std::string generateOutputFileName(const std::string& fileName);

// Removes Segments from complements queue and add them to candidates until segment is shorter than genome segment
void findCandidates(std::vector<Segment>& candidates, const Segment& genomeSegment, SegmentQueue& complements, unsigned int padding);

#endif