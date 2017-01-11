#include "Sample.h"
#include "DecisionTree.h"
#include <iostream>
#include <string>
using namespace std;
using namespace ID3;

void Test_CollectSamples()
{
	const string filename = "samples.txt";
	Samples samples;
	Attributes attributes;
	CollectSamples(samples, attributes, filename);
	PrintSamples(cout, attributes, samples);
}


void Test_CalcEntropyOf()
{
	const string filename = "samples.txt";
	Samples samples;
	Attributes attributes;
	CollectSamples(samples, attributes, filename);
	cout << "Entropy of 'headache:1' is: "
		<< CalcEntropyOf(samples, "headache", 1) << endl;
	cout << "Entropy of 'headache:0' is: "
		<< CalcEntropyOf(samples, "headache", 0) << endl;

	cout << "Entropy of 'courbature:1' is: "
		<< CalcEntropyOf(samples, "courbature", 1) << endl;
	cout << "Entropy of 'courbature:0' is: "
		<< CalcEntropyOf(samples, "courbature", 0) << endl;

	cout << "Entropy of 'temperature:2' is: "
		<< CalcEntropyOf(samples, "temperature", 2) << endl;
	cout << "Entropy of 'temperature:1' is: "
		<< CalcEntropyOf(samples, "temperature", 1) << endl;
	cout << "Entropy of 'temperature:0' is: "
		<< CalcEntropyOf(samples, "temperature", 0) << endl;
}

void Test_CalcConditionalEntropyOf()
{
	const string filename = "samples.txt";
	Samples samples;
	Attributes attributes;
	CollectSamples(samples, attributes, filename);
	cout << "Conditional entropy of 'headache' is: "
		<< CalcConditionalEntropyOf(samples, "headache") << endl;
	cout << "Conditional entropy of 'courbature' is: "
		<< CalcConditionalEntropyOf(samples, "courbature") << endl;
	cout << "Conditional entropy of 'temperature' is: "
		<< CalcConditionalEntropyOf(samples, "temperature") << endl;
}

void Test_FindBestAttribute()
{
	const string filename = "samples.txt";
	Samples samples;
	Attributes attributes;
	CollectSamples(samples, attributes, filename);
	cout << "The best attribute is: "
			<< FindBestAttribute(samples, attributes) << endl;
}

void Test_GenerateDecisionTree()
{
	const string filename = "samples.txt";
	Samples samples;
	Attributes attributes;
	CollectSamples(samples, attributes, filename);
	auto tree = GenerateDecisionTree(samples, attributes);
	cout << "The generating tree: " << endl;
	tree->print(cout);
}


int main()
{
	Test_CollectSamples();
	Test_CalcEntropyOf();
	Test_CalcConditionalEntropyOf();
	Test_FindBestAttribute();
	Test_GenerateDecisionTree();
}
