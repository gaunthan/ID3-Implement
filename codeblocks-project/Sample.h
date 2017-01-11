#ifndef SAMPLE_H
#define SAMPLE_H

#include <iosfwd>
#include <vector>
#include <list>
#include <string>

namespace ID3 {

struct Sample {
	typedef std::size_t size_t;

	size_t headache;
	size_t courbature;
	size_t temperature;
	size_t birdFlu;

	size_t getAttrValue(const std::string& attrName) const
	{
		if(attrName == "headache")
			return headache;
		else if(attrName == "courbature")
			return courbature;
		else if(attrName == "temperature")
			return temperature;
		return 0;
	}

	size_t getDecision() const { return birdFlu; }
};

typedef std::string Attribute;
typedef std::list<Sample> Samples;
typedef std::list<Attribute> Attributes;

std::istream& operator>>(std::istream& is,
						 Sample& sample);

void CollectSamples(Samples& samples,
					Attributes& attributes,
					const std::string& filename);

Samples GenerateSamplesByAttrValue(const Samples& samples,
								   const Attribute& attr,
								   std::size_t attrValue);

void PrintSamples(std::ostream& os,
				  const Attributes& attributes,
				  const Samples& samples);
}
#endif // SAMPLE_H
