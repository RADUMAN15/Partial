#pragma once
class Phrase
{
private:
	const char* prop;
	char** words;
	int max_size;
	int wrd_ind;

public:
	Phrase();
	Phrase(const char *prop);
	~Phrase();
	void operator= (const char *copy_string);
	operator int() const;
	char* operator[] (int index) const;
	void Print();
	int CountLetter(int index, char letter);
	int CountLetter(char letter);
	int CountVowels();
	const char* GetLongestWord();
};

