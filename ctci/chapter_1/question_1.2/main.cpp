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

// reverses the characters in the string
void reverse(char *word)
{
	// Check if word is null
	if(word == NULL)
	{
		cout<<"No word to reverse.\n";
		return;
	}

	// Find the length of the word
	size_t length = getLength(word);
	cout<<"length of the word is: "<<length<<"\n";

	int left = 0;
	int right = length - 1;
	char temp;

	cout<<"Before reversing:"<<word<<"\n";
	while(left < right)
	{
		// swap the characters pointed by left and the right 
		temp = word[left];
		word[left] = word[right];
		word[right] = temp;

		left++;
		right--;
	}
	cout<<"After reversing: "<<word<<"\n";
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
	
	cout<<"Calling reverse..\n";
	reverse(word);

	return 0;
}