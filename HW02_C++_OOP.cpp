#include <iostream>
#include <time.h>

int checkValue();

const int MAX_SIZE = 12;
const int TYPE_SIZE = 4;
const int TYPE4_SIZE = 4;

int main()
{
	srand(time(NULL));
	using std::cout;
	using std::cin;
	using std::endl;

	int numPass = 0;
	int arrType4[TYPE4_SIZE][2] = { {33, 47}, {58, 64}, {91, 96}, {123, 126} };//ASCII code positions of special symbols

	cout << "\nPASSWORDS GENERATION";

	cout << "\n\tenter qty of password -> ";
	numPass = checkValue();
	cout << "\thas been done " << numPass << " password" << (numPass > 1 ? "s.\n" : ".\n");

	for (short int n = 0; n < numPass; n++) {

		int arrType[TYPE_SIZE]{};
		int arrNum[MAX_SIZE]{};
		char arrPass[MAX_SIZE]{};

		//fill by type symbols the cells of code
		int pos = 0;
		do {

			int count = 0;
			for (int j = 0; j < TYPE_SIZE; j++)
				arrType[j] = 1;

			for (; pos < MAX_SIZE; ) {

				int randNum = rand() % TYPE_SIZE;

				if (pos > 0 && randNum == arrNum[pos - 1])
					continue;

				else if (pos > 0 && arrType[randNum] == 0)
					continue;

				arrType[randNum] -= 1;
				arrNum[pos] = randNum;

				pos++;
				count++;

				if (count < TYPE_SIZE)
					continue;
				break;
			}

			if (!(pos < MAX_SIZE))
				break;

		} while (true);

		//cout << "\narrNum: | "; //print type of symbols by cells of passwords
		//for (const short int& element : arrNum)
		//	cout << element<< " | ";

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

			else if (arrNum[i] == 3) {

				short int numType4 = rand() % TYPE4_SIZE;
				short int divValue = (arrType4[numType4][1] - arrType4[numType4][0]) + 1;

				symPass = rand() % (divValue)+arrType4[numType4][0];
			}

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

		cout << "\nPassword " << n + 1 << ": ";
		for (const unsigned char& element : arrPass)
			cout << element;
	}
	cout << "\n";

	return 0;
}

int checkValue()
{
	int a = 0.0;
	while (true) // the cycle continues until the user enters the correct value
	{
		std::cin >> a;
		if (std::cin.fail()) // if the previous extraction was unsuccessful,
		{
			std::cout << "Incorrect input.\n\tEnter value in digit format: ";
			std::cin.clear(); // then return the cin to 'normal' mode of operation
			std::cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
		}
		else // if all is well, return a
		{
			std::cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
			return abs(a);
		}
	}
}