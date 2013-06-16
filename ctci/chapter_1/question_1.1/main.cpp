#include <iostream>

using std::cout;
using std::cin;

// Calculate the length of the word
inline size_t getLength(char *word)
{
	// If there is not word, return 0
	if(word == NULL)
		return 0;

	// Calculate the length of the word
	size_t length = 0;
	while(word[length] != '\0')
		length++;

	return length;
}

// returns if the string has all unique characters or not
bool isUnique(char *word)
{
	// If there is not string return false
	if(word == NULL)
		return false;

	// Find the length of the string
	size_t length = getLength(word);
	cout<<"Length of the word: "<<length<<"\n";

	// Create a bool array reperesentin 256 characters and intialise to false
	bool hit[256];
	for(int i = 0; i < 256; ++i)
		hit[i] = false;

	for(size_t i = 0; i < length; ++i)
	{
		cout<<"i ="<<i<<", "<<word[i]<<"\n";
		// if character already present return false, else set its hitvlue to true
		if(hit[word[i]])
		{
			cout<<"First Repeated letter: "<<word[i]<<"\n";
			return false;
		}	
			
		else
			hit[word[i]] = true;
	}	

	// No unique characters found, so return true
	return true;
}

int main(int argc, char const *argv[])
{
	char word[100];
	cout<<"Please enter the word:";
	cin>>word;

	if(getLength(word) == 0)
	{
		cout<<"No word entered. Exiting...\n";
		return -1;
	}
	
	cout<<"Calling unique.\n";
	if(isUnique(word))
		cout<<"Word contains all unique characters.\n";
	else
		cout<<"Word does not contain all unique character.\n";
	
	return 0;
}