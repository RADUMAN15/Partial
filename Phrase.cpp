#include "Phrase.h"
#include <iostream>

Phrase::Phrase() {
	prop = nullptr;
	words = nullptr;
}

Phrase::Phrase(const char *prop) {	/// problema realocarii de mem	-> dim char* ??
	
	max_size = 100;
	words = new char*[max_size];
	for (int i = 0; i < max_size; i++)
		words[i] = new char[max_size];

	wrd_ind = 0;
	int let_ind = 0;	///letter index

	int i = 0;
	while (*(prop + i) == ' ' || (*(prop + i) == '\0'))
		i++;

	for (; *(prop + i) != '\0'; i++)
	{
		if( (*(prop + i) == ' ' && *(prop + i + 1) != ' ' ) || *(prop + i + 1) == '\0' )
		{
			words[wrd_ind][let_ind] = '\0';
			wrd_ind ++;
			let_ind = 0;
		}
		else if (*(prop + i ) != ' ') {
			words[wrd_ind][let_ind++] = *(prop + i);
		}
	}
}
Phrase::~Phrase() {
	for (int i = 0; i < max_size; i++)
		delete[]words[i];

	delete []words;	///sters tot array ul, nu doar prima locatie de mem(i.e wrods[i])
}
void Phrase::Print() {

	for (int i = 0; i < wrd_ind; i++)
		std::cout << words[i]	<< '\n';
}
int Phrase::CountLetter(int index, char letter)
{
	if (index < wrd_ind)
	{
		int k = 0;
		for (int i = 0; words[index][i] != '\0'; i++)
			if (words[index][i] == letter)
				k++;
		return k;
	}
	return 0;
}
int Phrase::CountLetter(char letter)
{
	
	int k = 0;
	for(int index = 0 ; index < wrd_ind; index++)
		for (int i = 0; words[index][i] != '\0'; i++)
			if (words[index][i] == letter)
				k++;
		return k;
}
int Phrase::CountVowels()
{
	int k = 0;
	for (int index = 0; index < wrd_ind; index++)
		for (int i = 0; words[index][i] != '\0'; i++)
			if (words[index][i] == 'a' || words[index][i] == 'e' ||
				words[index][i] == 'i' || words[index][i] == 'o' ||
				words[index][i] == 'u' || words[index][i] == 'A' ||
				words[index][i] == 'E' || words[index][i] == 'I' || 
				words[index][i] == 'O' || words[index][i] == 'U')
				k++;
	return k;
}
const char* Phrase::GetLongestWord()
{
	int max_len = -1;
	int wrd_max_idx = -1;

	for (int index = 0; index < wrd_ind; index++)
	{
		int i = 0;
		for (; words[index][i] != '\0'; i++);
		if (i > max_len)
			wrd_max_idx = index, max_len = i;
	}
	return words[wrd_max_idx];
}
void Phrase::operator=(const char* copy_string) {

	prop = copy_string;
	Phrase(prop);
}

Phrase::operator int() const
{
	return wrd_ind;
}

char* Phrase::operator[](int index) const
{
	if(index < wrd_ind)
		return words[index];

	return nullptr;
}
