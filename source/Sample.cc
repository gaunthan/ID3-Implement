#include "Sample.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cstdlib>
using namespace std;

namespace ID3 {

std::istream& operator>>(std::istream& is,
						 Sample& sample)
{
	is >> sample.headache >> sample.courbature >> sample.temperature
		>> sample.birdFlu;
	return is;
}

void CollectSamples(Samples& samples,
					Attributes& attributes,
					const std::string& filename)
{
	ifstream sampleStream(filename);
	if(!sampleStream) {
		cerr << "cannot open file: " + filename;
		exit(EXIT_FAILURE);
	}
	// collect attributes
	string attrLine;
	getline(sampleStream, attrLine);
	stringstream ss(attrLine);
	Attribute attribute;
	while(ss >> attribute) {
		attributes.push_back(attribute);
	}
	// collect samples
	Sample sample;
	while(sampleStream >> sample) {
		samples.push_back(sample);
	}
}

Samples GenerateSamplesByAttrValue(const Samples& samples,
								   const Attribute& attr,
								   std::size_t attrValue)
{
	Samples newSamples;
	Samples::const_iterator last = samples.end();
	for(auto first = samples.begin(); first != last; ++first) {
		if(first->getAttrValue(attr) == attrValue) {
			newSamples.push_back(*first);
		}
	}
	return newSamples;
}

void PrintSamples(std::ostream& os,
				  const Attributes& attributes,
				  const Samples& samples)
{
	copy(attributes.begin(), attributes.end(),
			ostream_iterator<string>(os, "\t"));
	os << endl;
	Samples::const_iterator last = samples.end();
	for(auto first = samples.begin(); first != last; ++first) {
		os << first->headache << "\t\t"
			<< first->courbature << "\t\t"
			<< first->temperature << "\t\t"
			<< first->birdFlu << endl;
	}
}
}
