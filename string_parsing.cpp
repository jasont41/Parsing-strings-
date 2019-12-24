// string_parsing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
void print_vector(vector<string>); 
void dump_long_string_to_resultant_vect(string, vector<string>&); 
void remove_punc_from_string(vector<string>&); 
void remove_dup(vector<string>&);

int main()
{
	ifstream infile; 
	vector<string> result; 
	vector<string> vect_of_individual_strings; 
	infile.open("test_file.txt");
	if (infile.fail())
	{
		cout << "File didn't open correctly, check file name\n"; 
	}
	while (!infile.eof()) 
	{
		string temp; 
		getline(infile, temp); 
		result.push_back(temp); 
	}
	int vect_size = result.size(); 
	for(int i = 0; i < vect_size; i++)
	{
		dump_long_string_to_resultant_vect(result[i], vect_of_individual_strings);
	}
	remove_punc_from_string(vect_of_individual_strings);
	sort(vect_of_individual_strings.begin(), vect_of_individual_strings.end());
	print_vector(vect_of_individual_strings); 
	remove_dup(vect_of_individual_strings); 
	cout << endl << endl; 
	cout << vect_of_individual_strings.size() << endl;
	print_vector(vect_of_individual_strings); 
}
/*
	String vector element -> sstream -> break into words ->
	dump into new vect -> strip punc 
*/
void print_vector(vector<string> string_vect) 
{
	int vect_size = string_vect.size(); 
	for (int i = 0; i < vect_size; i++) {
		cout << string_vect[i] << endl;
	}
}

void dump_long_string_to_resultant_vect(string incoming_string, vector<string>& ending_vect) 
{
	string delimiter = " ";
	size_t pos = 0; 
	string token; 
	while ((pos = incoming_string.find(delimiter)) != string::npos) {
		token = incoming_string.substr(0, pos); 
		ending_vect.push_back(token); 
		incoming_string.erase(0, pos + delimiter.length()); 
	}
}

void remove_punc_from_string(vector<string>& incoming_vect) {
	for (int i = 0; i < incoming_vect.size(); i++) {
		string temp = incoming_vect[i]; 
		incoming_vect.erase(incoming_vect.begin()); 
		int temp_num = temp.length() - 1; 
		if (ispunct(temp[temp_num])) {
			temp.resize(temp_num); 
		}
		incoming_vect.push_back(temp);
	}
}

//https://www.techiedelight.com/remove-duplicates-vector-cpp/
void remove_dup(vector<string>& incoming_vect) {
	auto end = incoming_vect.end(); 
	for (auto it = incoming_vect.begin(); it != end; ++it) {
		end = remove(it + 1, end, *it); 
	}
	incoming_vect.erase(end, incoming_vect.end());
}
