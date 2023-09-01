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
	char arrPassword[MAX_SIZE]{};

	cout << "Start!\n";

	int i = 0;
	//fila by type symbols the cells of code
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

	cout << "\nnum type: | ";
	for (const short int& element : arrNum)
		cout << element<< " | ";

	return 0;
}