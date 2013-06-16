#include <iostream>
#include <ctype.h>

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

inline size_t getLengthWithoutWS(char *word)
{
	// If there is not word, return 0
	if(word == NULL)
		return 0;

	// Calculate the length of the word
	size_t length = 0;
	size_t count = 0;
	while(word[count] != '\0')
	{
		if(!iswspace(word[count]))
			length++;

		count++;
	}
		

	return length;
}

bool isAnagram(char *string1, char *string2)
{
	// if either of the string is NULL, return
	if(string1 == NULL || string2 == NULL)
	{
		cout<<"Either of the string empty.\n";
		return false;
	}

	// Calculate the length of both the strings disregarding the whitespace
	int lengthWS1 = getLengthWithoutWS(string1);
	int lengthWS2 = getLengthWithoutWS(string2);
	cout<<"Length without whitespaces: "<<lengthWS1<<", "<<lengthWS2<<"\n";

	// if the length of the two strings is different, cannot be anagrams
	if(lengthWS1 != lengthWS2)
	{
		cout<<"Length of the two strings different\n";
		return false;	
	}
	
	// Calculate the length with the whitespace for iteration
	int length1 = getLength(string1);
	int length2 = getLength(string2);
	cout<<"Length with whitespaces: "<<length1<<", "<<length2<<"\n";

	// Create an array to hold the counts and intialize it 0
	int counts[256];
	for(int i = 0; i < 256; ++i)
		counts[i] = 0;

	for(int i = 0; i < length1; ++i)
	{
		// For every character in string1, increment its corresponding count
		if(!iswspace(string1[i]))
			counts[string1[i]]++;
	}
	
	for(int i = 0; i < length2; ++i)
	{	// For every character in string2, decrement its corresponding count
		if(!iswspace(string2[i]))
			counts[string2[i]]--;
	}

	// Check if all counts zero 
	for(int i = 0 ; i < 256; ++i)
		if(counts[i] != 0)
			return false;

	return true;
}	

int main(int argc, char const *argv[])
{
	// Read in the two words
	char string1[256];
	char string2[256];

	cout<<"Please enter the first word:";
	cin.getline(string1, 256);

	cout<<"Plese enter the second word:";
	cin.getline(string2, 256);

	if(getLength(string1) == 0)
	{
		cout<<"First word is empty. Exiting...\n";
		return -1;
	}
	
	if(getLength(string2) == 0)
	{
		cout<<"Second word is empty. Exiting...\n";
		return -1;
	}

	// Check if the two strings are anagrams
	cout<<"Calling isAnagram..\n";
	if(isAnagram(string1, string2))
		cout<<"The two strings "<<string1<<" and "<<string2<<" are anagrams.\n";
	else
		cout<<"The two strings "<<string1<<" and "<<string2<<" are not anagrams.\n";

	return 0;
}