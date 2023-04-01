#include<iostream>
#include<string>
using namespace std;

void middleErase(string word, int pos){
	word[pos / 2] = 0;
	cout << word << endl;
}
string wordErase(string str, int pos){
	return str.erase(0, pos + 1);
}
int wordsCount(string str) {
	int a = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == ' ' || str[i] == '.'){
			a++;
		}
	}
	return a;
}
int position(string word) {
	int a = 0;
	for (int i = 0; i < word.length(); i++) {
		if (word[i] != ' ' && word[i] != '.'){
			a++;
		}
		else{
			break;
		}
	}
	return a;
}
string wordErase2(string str, int pos){
	return str.find(0, pos - 1);
}
int main() {
	string str, word;
	getline(cin, str);
	int words_amount = wordsCount(str);
	for (int i = 0; i < words_amount; i++){
		word = str;
		int pos = position(word);
		word.resize(pos);
		if (pos % 2 != 0){
			middleErase(word, pos);
		}
		else{
			cout << word << endl;
		}
		str = wordErase(str, pos);
	}
	cout << str[0] << endl;
}
