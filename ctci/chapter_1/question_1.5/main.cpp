#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using std::cout;
using std::cin;

// Calculate the newLength of the sentence
inline int getLength(char *word)
{
	if(word == NULL)
		return 0;

	int length = 0;
	while(word[length] != '\0')
		length++;

	return length;
}

// Calculate the number of digits required to store number
int calcNoDigits(int number)
{
	int numOfDigits = 0;

	while(number > 0)
	{
		number /= 10;
		numOfDigits++;
	}

	return numOfDigits;
}

int calcNewLength(char *word)
{
	if(word == NULL)
		return 0;

	// Get the length of the word
	int length = getLength(word);
	char currentChar = word[0];
	int currentCount = 1;
	int newLength = 0;

	for(int i = 1; i <= length; ++i)
	{
		// if the next word is the same
		if(word[i] == currentChar)
			currentCount++;
		else
		{
			// if the current count is less than 10, only 1 digit is required to represent it
			if(currentCount< 10)
				newLength += 2;
			else
				newLength += (1 + calcNoDigits(currentCount));

			currentCount = 1;
			currentChar = word[i];
		}
	}

	return newLength;
}

void compressString(char *word, char* compressedString)
{
	if(word == NULL)
	{
		cout<<"Emtpy String.\n";
		return;
	}

	// Calculate the length and the expected new length of the string
	int length = getLength(word);
	int newLength = calcNewLength(word);

	cout<<"Original Length: "<<length<<"\nNew Length: "<<newLength<<"\n";

	// if new length is more than the original, dont compress
	if(newLength > length)
	{
		strcpy(compressedString, word);
		cout<<"Compressed String: "<<compressedString<<"\n";
		return;
	}

	char currentChar = word[0];		// Keep track of the current character
	int currentCount = 1;			// Keep track of the current character count
	int counter = 0;				// Keep track of the end of the compressed string

	cout<<"Original String: "<<word<<"\n";

	for(int i = 1; i <= length; ++i)
	{
		// if the next word is the same
		if(word[i] == currentChar)
			currentCount++;
		else
		{
			// Store the current Character first
			compressedString[counter++] = currentChar;

			// Store the character count
			if(currentCount < 10)
				compressedString[counter++] = (char)(((int)'0') + currentCount);
			else
			{
				int digit = 0;
				int numOfDigits = calcNoDigits(currentCount);

				while(currentCount > 0)
				{
					// get the first digit
					digit = currentCount/pow(10, numOfDigits);

					// Update the number
					currentCount -= digit * pow(10, numOfDigits);

					// Set the digit in the compressed string
					compressedString[counter++] = (char)(((int)'0') + digit);

					numOfDigits--;
				}	
			}

			// Update the current character and count
			currentCount = 1;
			currentChar = word[i];
		}
	}

	compressedString[counter] = '\0';
	cout<<"Compressed String: "<<compressedString<<"\n";
}

int main(int argc, char const *argv[])
{
	// Read in the two words
	char sentence[256];
	char compressedString[256];

	cout<<"Please enter the sentence:";
	cin.getline(sentence, 256);

	if(sentence == NULL)
	{
		cout<<"Sentence is empty. Exiting...\n";
		return -1;
	}

	compressString(sentence, compressedString);
	
	return 0;
}