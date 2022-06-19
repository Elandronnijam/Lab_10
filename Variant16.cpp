#include <iostream>
#include <string>
#include "bits0stdc++.h"

//Сформировать по строке A новую строку B по правилу: в каждом слове удалить все предыдущие вхождения последней буквы.

/*
 
	1. Найти последнюю букву в каждом слове, сохранить её
	2. Начиная с конца слова сравнить все кроме первой буквы с сохранённой буквой
	3. Совпадения удалить

*/

float variant16()
{
	int cin_choice;
	std::string DANO = "London is the capital of Great Britain.";
	std::cout << "If u want to name the <<string A>> press 1: ";
	std::cin >> cin_choice;
	if (cin_choice == 1)
	{
		std::cout << "Enter your text: ";
		std::cin.ignore(32767, '\n');
		std::getline (std::cin, DANO);
	}

	int EndOfCycle = 0;												//Переменная, ответсвенная за выход из цикла ниже
	int StepCounter = 0;											//Считает шаги цикла
	int WordLength = 0;												//Длина слова

	std::string LINE = DANO;										//Входные данные
	std::string CLONE_LINE = LINE;									//Резервная переменная для входн. данных
	std::string WORD;												//Переменная для слов из предложений
	std::string CLONE_WORD;											//Её клон
	std::string SUM_WORDS;											//Выводимые данные

	std::stringstream GetLine_CLONE_WORD(CLONE_WORD);


	while (EndOfCycle != 1)		//Начинаем разбор предложения
	{
		std::stringstream GetLine_CLONELINE(CLONE_LINE);

		std::cout << "Your text: " << CLONE_LINE << std::endl;
		
		std::getline (GetLine_CLONELINE, WORD, ' ');	//Достаём из него первое стоящее слово и записываем в переменную WORD

		std::cout << "1: Word: " << WORD << std::endl;

		WordLength = WORD.size();	//считаем длину слова и записываем в WordLength

		std::cout << "2: WordLength = " << WordLength << std::endl;

		if (WORD[WordLength - 1] == '.')	//проверка на конец предложения => конец цикла (если на конце слова стои точка => это последнне слово в предложении)
		{
			WORD[WordLength - 1] = '\0';	// '\0' - сивол "ничего", вместо "", на которое жалуется компилятор (ну типа "" - ConstChar, а ConstChar != Char)
			WordLength--;
			EndOfCycle = 1;
		}

		std::cout << "3: EndOfCycle = " << EndOfCycle << std::endl;

		CLONE_WORD = WORD;  //присваиваем клону слова значение обрабатывемого слова

		std::cout << "4: CLONE_WORD = " << CLONE_WORD << std::endl;

		int Counter1 = 0;

		while (Counter1 < WordLength + 1)  //стираем 1 (уже обрабатываемое) слово из предложения, +1 нужен для тирания пробела, стоящего за словом.
		{
			CLONE_LINE[Counter1] = '\0';	/*
											Поскольку программа запоминает номер каждого символа в слое, каждая следущая букава не меняет свой номер 
											с удаплением предыдущей,и если в аргументе написать [0], будет стёрта только первая из них, 
											т.к. каждая слудущая не будет наследлвать "0" номер после стирания первой буквы.
											*/
			Counter1++;
			if (Counter1 > 1000)	//аварийный выход
			{
				std::cout << "Error: Counter 1 > 1000. Program was emergency stopped!";
				return 0;
			}
		}

		Counter1 = 0;

		std::cout << "5: CLONE_LINE = " << CLONE_LINE << std::endl;

		std::string LAST_LETTER;	//переменная последней буквы слова
		LAST_LETTER = CLONE_WORD[WordLength - 1];  //узнаем последнюю букву обрабатываемого слова

		std::cout << "6: LAST_LETTER (of WORD) = " << LAST_LETTER << std::endl;

		int Counter2 = 0;
		
		std::string CLEARED_WORD;
		while (Counter2 < WordLength)  //стираем все совпадающие с последней буквы в слове
		{
			std::string CURRENT_LETTER;	//переменная, хранящая букву слово
			CURRENT_LETTER = CLONE_WORD[Counter2];

			if (Counter2 <= WordLength - 1)	//переписывает слово без входений последенй буквы
			{
				if (CURRENT_LETTER == LAST_LETTER)  //сравниваем текущую букву с последеней
				{
					std::cout << "letter " << CURRENT_LETTER << " was cleared!" << std::endl;
				}
				else
				{
					CLEARED_WORD = CLEARED_WORD + CURRENT_LETTER;
				}
			}

			Counter2++;

			if (Counter2 > 1000)	//аварийный выход
			{
				std::cout << "Error: Counter 2 > 1000. Program was emergency stopped!";
				return 0;
			}
		}

		CLEARED_WORD = CLEARED_WORD + LAST_LETTER;	//дописываем последнюю букву.

		std::cout << "7: CLEARED_WORD = " << CLEARED_WORD << std::endl;

		if (EndOfCycle != 1)	//ставит точку пробел между словами и точку в конце переработанного предложения
		{
			SUM_WORDS = SUM_WORDS + CLEARED_WORD + " "; //записываем в новую версию предложения обработанное слово
		}
		else
		{
			SUM_WORDS = SUM_WORDS + CLEARED_WORD + "."; //записываем в новую версию предложения обработанное слово
		}

		std::cout << "8: SUM_WORDS = " << SUM_WORDS << std::endl;

		WORD.clear();  //очищаем переменную слова для следущего круга цикла
		CLONE_WORD.clear();  //и клона тоже затираем
		CLEARED_WORD.clear();	//ну вы поняли
		WordLength = 0;	//и длину слова чтобы не складывалась

		std::cout << "9: WORD.clear/CLONE_WORD.clear = " << WORD << CLONE_WORD << std::endl;

		StepCounter++;	//счетчик ходов

		std::cout << "10: Step_Counter = " << StepCounter << std::endl << std::endl;

		if (StepCounter > 1000)	//блок аварийного выхода
		{
			std::cout << "Error: StepCounter > 1000. Program was emergency stopped!";
			EndOfCycle = 1;
			return 0;
		}
	}

	std::cin.ignore(32767, '\n');
	std::cout << "String B: " << SUM_WORDS << std::endl;	//выводим результат

	return 0;
}
