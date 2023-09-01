#include <iostream>
#include <time.h>

const int MAX_SIZE = 12;
const int TYPE_SIZE = 4;

int main()
{
	srand(time(NULL));
	using std::cout;
	using std::cin;
	using std::endl;

	int arrNum[MAX_SIZE]{};
	int arrType[TYPE_SIZE]{};
	int arrType4[][2] = { {33, 47}, {58, 64}, {91, 96}, {123, 126} };

	char arrPass[MAX_SIZE]{' '};

	cout << "Start!\n";
	//fill by type symbols the cells of code
	int i = 0;
	do {

		int count = 0;
		for (int j = 0; j < TYPE_SIZE; j++)
			arrType[j] = 1;

		for (; i < MAX_SIZE; ) {

			int randNum = rand() % TYPE_SIZE;

			if (i > 0 && randNum == arrNum[i - 1])
				continue;

			else if (i > 0 && arrType[randNum] == 0)
				continue;

			arrType[randNum] -= 1;
			arrNum[i] = randNum;

			i++;
			count++;

			if (count < TYPE_SIZE)
				continue;
			break;
		}

		if (!(i < MAX_SIZE))
			break;

	} while (true);

	cout << "\narrNum: | ";
	for (const short int& element : arrNum)
		cout << element<< " | ";

	//fill pasword by symbols depend from them type defined before
	bool isSymbol;
	for (short int i = 0; i < MAX_SIZE;) {

		isSymbol = false;
		char symPass;

		if (arrNum[i] == 0)
			symPass = rand() % 10 + '0';

		else if (arrNum[i] == 1)
			symPass = rand() % 26 + 'a';

		else if (arrNum[i] == 2)
			symPass = rand() % 26 + 'A';

		else if (arrNum[i] == 3)
			symPass = rand() % 15 + '!';


		for (short int j = 0; j < i; j++) {

			if (arrPass[i] == arrPass[j]) {
				isSymbol = true;
				break;
			}
		}

		if (!isSymbol) {
			arrPass[i] = symPass;
			i++;
		}
	}

	cout << "\narrPass: | ";
	for (const unsigned char& element : arrPass)
		cout << element << " | ";
	cout << "\n";

	return 0;
}