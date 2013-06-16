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

bool isAnagram(char *string1, char *string2)
{
	// if either of the string is NULL, return
	if(string1 == NULL || string2 == NULL)
	{
		cout<<"Either of the string empty.\n";
		return false;
	}

	// Calculate the length of both the strings
	int length1 = getLength(string1);
	int length2 = getLength(string2);

	// if the length of the two strings is different, cannot be anagrams
	if(length1 != length2)
	{
		cout<<"Length of the two strings different\n";
		return false;	
	}
	
	// Create an array to hold the counts and intialize it 0
	int counts[256];
	for(int i = 0; i < 256; ++i)
		counts[i] = 0;

	for(int i = 0; i < length1; ++i)
	{
		// For every character in string1, increment its corresponding count
		counts[string1[i]]++;

		// For every character in string2, decrement its corresponding count
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
	char string1[100];
	char string2[100];

	cout<<"Please enter the first word:";
	cin>>string1;

	cout<<"Plese enter the second word:";
	cin>>string2;

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