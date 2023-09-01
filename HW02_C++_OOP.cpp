#include <iostream>
#include <time.h>

const int MAX_SIZE = 12;
const int TYPE_SIZE = 4;
const int STEP_CODE = 4;

int main()
{
	srand(time(NULL));
	using std::cout;
	using std::cin;
	using std::endl;

	int arrNum[MAX_SIZE]{0};
	char arrPassword[MAX_SIZE]{};
	bool isCode = false;

	cout << "Start!\n";

	for (short int n = 0; n < MAX_SIZE; n += STEP_CODE) //generation type symbol code
	{
		int arrTemp[TYPE_SIZE]{ 0 };

		for (short int i = 0; i < TYPE_SIZE;) {

			isCode = false;
			int numRandType = rand() % TYPE_SIZE;

			for (short int j = 0; j < i; j++) {

				if (arrTemp[j] == numRandType) {
					isCode = true;
					break;
				}
			}

			if (!isCode) {
				arrTemp[i] = numRandType;
				i++;
			}
		}

		for (short int i = 0; i < TYPE_SIZE; i++)
			arrNum[i + n] = arrTemp[i];
	}

	cout << "\nbefore\n";
	for (const short int& element : arrNum)
		cout << element<< " | ";

	for (short int i = STEP_CODE; i < MAX_SIZE; i += STEP_CODE)//check neighbour items is equal
		if (arrNum[i] == arrNum[i - 1])
			std::swap(arrNum[i], arrNum[i+1]);

	cout << "\nafter\n";
	for (const short int& element : arrNum)
		cout << element << " | ";

	return 0;
}