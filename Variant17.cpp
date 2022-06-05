#include <iostream>
#include <string>
#include "bits0stdc++.h"

//“.«.: —формировать по строке A новую строку B по правилу: в каждом слове удалить все предыдущие вхождени€ последней буквы.

float variant17()
{
	int cin_choice;
	std::string DANO = "London is the capital of Great Britain";
	std::cout << "If u want to name the <<string A>> press 1: ";
	std::cin >> cin_choice;
	if (cin_choice == 1)
	{
		std::cout << "Enter your text: ";
		std::cin.ignore(32767, '\n');
		std::getline(std::cin, DANO);
	}

	int EndOfCycle = 0;												//ѕеременна€, ответсвенна€ за выход из цикла ниже
	int StepCounter = 0;											//—читает шаги цикла
	int WordLength = 0;												//ƒлина слова

	std::string LINE = DANO;										//¬ходные данные
	std::string CLONE_LINE = LINE;									//–езервна€ переменна€ дл€ входн. данных
	std::string WORD;												//ѕеременна€ дл€ слов из предложений
	std::string CLONE_WORD;											//≈Є клон
	std::string SUM_WORDS;											//¬ыводимые данные

	std::stringstream GetLine_CLONELINE(CLONE_LINE);
	std::stringstream GetLine_CLONE_WORD(CLONE_WORD);


	while (EndOfCycle != 1)		//Ќачинаем разбор предложени€
	{
		std::getline(GetLine_CLONELINE, WORD, ' ');	//ƒостаЄм из него первое сто€щее слово и записываем в переменную WORD

		WordLength = WORD.size();	//считаем длину слова и записываем в WordLength


		if (WORD[WordLength] == '.')	//проверка на конец предложени€ => конец цикла (если на конце слова стои точка => это последнне слово в предложении)
		{
			WORD[WordLength] = '\0';	// '\0' - сивол "ничего", вместо "", на которое жалуетс€ компил€тор (ну типа "" - ConstChar, а ConstChar != Char)
			WordLength--;
			EndOfCycle = 1;
		}

		CLONE_WORD = WORD;  //присваиваем клону слова значение обрабатывемого слова

		while (int i = 0 < WordLength)  //стираем 1 (уже обрабатываемое) слово из предложени€
		{
			CLONE_LINE[0] = '\0';
		}

		std::string LAST_LETTER;	//переменна€ последней буквы слова
		LAST_LETTER = CLONE_WORD[WordLength];  //узнаем последнюю букву обрабатываемого слова

		while (int i = 0 < WordLength)  //стираем все совпадающие с последней буквы в слове
		{
			std::string NUMBERS_OF_LETTERS;
			NUMBERS_OF_LETTERS = CLONE_WORD[i];
			if (NUMBERS_OF_LETTERS == LAST_LETTER)  //сравниваем текущую букву с последеней
			{
				NUMBERS_OF_LETTERS == "";
				i--;
				WordLength--;
			}
			i++;
		}

		SUM_WORDS = SUM_WORDS + CLONE_WORD; //записываем в новую версию предложени€ обработанное слово

		if (EndOfCycle == 1)
		{
			SUM_WORDS = SUM_WORDS + ".";
		}

		WORD.clear();  //очищаем переменную слова дл€ следущего круга цикла
		CLONE_WORD.clear();  //и клона тоже затираем
	}

	std::cin.ignore(32767, '\n');
	std::cout << "String B: " << SUM_WORDS;

	return 0;
}