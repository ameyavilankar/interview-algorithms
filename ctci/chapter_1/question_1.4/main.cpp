#include <iostream>

using std::cout;
using std::cin;

// Calculate the newLength of the sentence
inline int getNewLength(char *sentence, int& length, int& zeroCount)
{
	if(sentence == NULL)
		return 0;

	length = 0;
	zeroCount = 0;
	while(sentence[length] != '\0')
	{
		if(isspace(sentence[length]))
			zeroCount++;

		length++;
	}
}

void replaceSpaces(char *sentence)
{
	// If sentence is NULL, return
	if(sentence == NULL)
	{
		cout<<"The string is empty.\n";
		return;
	}

	// Calculate the length of the new string
	int length = 0;
	int zeroCount = 0;
	getNewLength(sentence, length, zeroCount);
	int newLength  = length + 2 * zeroCount;
	
	// Debug Info
	cout<<"Original length: "<<length<<"\nZerCount: "<<zeroCount<<"\nnewLength: "<<newLength<<"\n";
	cout<<"Orignal Sentence"<<sentence<<"\n";

	// Set the last character of the new sentence
	sentence[newLength--] = '\0';
	length--;

	while(length >= 0)
	{
		cout<<"Length, newLength: "<<length<<", "<<newLength<<"\n";

		if(isspace(sentence[length]))
		{
			sentence[newLength--] = '0';
			sentence[newLength--] = '2';
			sentence[newLength--] = '%';
		}
		else
			sentence[newLength--] = sentence[length];

		length--;
	}

	cout<<"New sentence: "<<sentence<<"\n";
}	

int main(int argc, char const *argv[])
{
	// Read in the two words
	char sentence[256];

	cout<<"Please enter the sentence:";
	cin.getline(sentence, 256);

	if(sentence == NULL)
	{
		cout<<"Sentence is empty. Exiting...\n";
		return -1;
	}

	// replace the spaces in the string with %20
	replaceSpaces(sentence);

	return 0;
}