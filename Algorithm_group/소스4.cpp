/*
#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> l;
	char input = cin.get();
	while (input != '\n') {
		l.push_back(input);
		input = cin.get();
	} 

	int numberOfInstruction; cin >> numberOfInstruction;
	list<char>::iterator cusu = l.end();
	char instruction, charOfP;

	while (numberOfInstruction > 0) {
		cin >> instruction;
		switch (instruction)
		{
		case 'L': if (cusu != l.begin()) --cusu;
			break;
		case 'D': if (cusu != l.end()) ++cusu;
			break;
		case 'B': if (cusu != l.begin()) { --cusu; cusu = l.erase(cusu); }
				break;
		case 'P': {cin >> charOfP; cusu = l.insert(cusu, charOfP); cusu++;}
			break;
		default:
			break;
		}
		numberOfInstruction--;
	}

	for (auto& i : l) { cout << i; }
	return 0;
}
*/