#ifndef CHECK_UTILS_H
#define CHECK_UTILS_H

#include <fstream>
#include <iostream>
#include <vector>

#include "Segment.h"

std::vector<Segment> readGenomeData(const std::string& fileName);

std::vector<Segment> readSynthesizedData(const std::string& fileName);

#endif