#ifndef SEGMENT_H
#define SEGMENT_H

#include <string>

struct Segment {
	std::string name;
	std::string chromosome;
	unsigned int start;
	unsigned int end;

	unsigned int length() const { return end - start; }

	bool operator>(const Segment& other) const { return length() > other.length(); }
	bool operator<(const Segment& other) const { return length() < other.length(); }
};

#endif