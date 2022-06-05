#include <iostream>
#include <string>
#include "bits0stdc++.h"

//Сформировать по строке A новую строку B по правилу: в каждом слове удалить все предыдущие вхождения последней буквы.

/*
	К О М А Н Д Ы

	std::string A = "A"
	std::getline (Otkuda, Kuda, Konec)
	.size()



*/
/*
 
	1. Найти последнюю букву в каждом слове, сохранить её
	2. Начиная с конца слова сравнить все кроме первой буквы с сохранённой буквой
	3. Совпадения удалить

*/

/*

	1. Организовать создание сроки через суммирование мини-строк - слов.
	1.1. Пока не будет введена точка, предложение не закончено.
	1.2. Пока не будет введён пробел, слово не законченою
	1.3. Цикл:
	1.3.1. Объявляем перемепнную строки std::string STROKA и слова SLOVO
	1.3.2. Вводим всё предложение 	
	1.3.3. Объявляем клон предложения KLON_STROKI = STROKA, клон слова KLON_SLOVA и итоговую переменную SUMMA_SLOV
	1.3.4. Объявляем сервисные переменные (dlina_slova)
	1.3.5. 
	
		While (KonecCikla != 666)
		   {

				std::getline (KLON_STROKI, SLOVO, " ")  //извлекаем из предложения 1 стоящее слово

				dlina_slova = SLOVO.size()  //узнаем длину 1 слова

				if (SLOVO[dlina_slova] == ".")	//проверка на конец предложения => конец цикла
				{
					SLOVO[dlina_slova] = "";
					dlina_slova--
					KonecCikla = 666;
				}

				KLON_SLOVA = SLOVO;  //присваиваем клону слова значение обрабатывемого слова

				while (i = 0 < dlina_slova)  //стираем 1 (уже обрабатываемое) слово из предложения
				{
					KLON_STROKI [0] = "";
				}

				std::string POSLEDNYAYA_BUKVA_SLOVA = KLON_SLOVA[dlina_slova]  //узнаем последнюю букву обрабатываемого слова
				
				while (i = 0 < dlina_slova)  //стираем все совпадающие с последней буквы в слове
				{
					if (KLON_SLOVA[i] == POSLEDNYAYA_BUKVA_SLOVA)  //сравниваем текущую букву с последеней
					{
						KLON_SLOVA[i] == "";
						i--;
						dlina_slova--;
					}
					i++
				}

				SUMMA_SLOV = SUMMA_SLOV + KLON_SLOVA //записываем в новую версию предложения обработанное слово

				If (KonecCikla == 666)
				{
					SUMMA_SLOV = SUMMA_SLOV + ".";
				}

				SLOVO.clear  //очищаем переменную слова для следущего круга цикла
				KLON_SLOVA.clear  //и клона тоже затираем
		   }

	2. Ввести строку-слово
	3. Узнать длину строки слова (N, подсчёт элементов начинается с 0)
	4. Узнать элемент LETTER строки-слова под номером N (последний элемент)
	5. Цикл while (i = 0 < N) -> {if (элемент номер i == LETTER) -> { элемент номер i = "" } i++ }		//	или m.clear();	if (m.empty())
	6. Следущее слово (строка слово)

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

	std::stringstream GetLine_CLONELINE(CLONE_LINE);
	std::stringstream GetLine_CLONE_WORD(CLONE_WORD);


	while (EndOfCycle != 1)		//Начинаем разбор предложения
	{
		std::cout << "Your text: " << CLONE_LINE << std::endl;
		
		std::getline (GetLine_CLONELINE, WORD, ' ');	//Достаём из него первое стоящее слово и записываем в переменную WORD

		std::cout << "1: Word: " << WORD << std::endl;

		WordLength = WORD.size();	//считаем длину слова и записываем в WordLength

		std::cout << "2: WordLength = " << WordLength << std::endl;

		if (WORD[WordLength] == '.')	//проверка на конец предложения => конец цикла (если на конце слова стои точка => это последнне слово в предложении)
		{
			WORD[WordLength] = '\0';	// '\0' - сивол "ничего", вместо "", на которое жалуется компилятор (ну типа "" - ConstChar, а ConstChar != Char)
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
			if (Counter1 > 5000)	//аварийный выход
			{
				std::cout << "Error: Counter 1 > 5000. Program was emergency stopped!";
				return 0;
			}
		}

		Counter1 = 0;

		std::cout << "5: CLONE_LINE = " << CLONE_LINE << std::endl;

		std::string LAST_LETTER;	//переменная последней буквы слова
		LAST_LETTER = CLONE_WORD[WordLength - 1];  //узнаем последнюю букву обрабатываемого слова

		std::cout << "6: LAST_LETTER (of WORD) = " << LAST_LETTER << std::endl;

		int Counter2 = 0;

		while (Counter2 < WordLength)  //стираем все совпадающие с последней буквы в слове
		{
			std::string NUMBERS_OF_LETTERS;
			NUMBERS_OF_LETTERS = CLONE_WORD[Counter2];
			if (NUMBERS_OF_LETTERS == LAST_LETTER)  //сравниваем текущую букву с последеней
			{
				NUMBERS_OF_LETTERS == "";
				Counter2--;
				WordLength--;
			}
			Counter2++;
			if (Counter2 > 5000)	//аварийный выход
			{
				std::cout << "Error: Counter 2 > 5000. Program was emergency stopped!";
				return 0;
			}
		}

		std::cout << "7: CLONE_WORD = " << CLONE_WORD << std::endl;

		SUM_WORDS = SUM_WORDS + CLONE_WORD; //записываем в новую версию предложения обработанное слово

		if (EndOfCycle == 1)	//ставит точку в конце переработанного предложения
		{
			SUM_WORDS = SUM_WORDS + ".";
		}

		std::cout << "8: SUM_WORDS = " << SUM_WORDS << std::endl;

		WORD.clear();  //очищаем переменную слова для следущего круга цикла
		CLONE_WORD.clear();  //и клона тоже затираем

		std::cout << "9: WORD.clear/CLONE_WORD.clear = " << WORD << CLONE_WORD << std::endl;

		StepCounter++;	//счетчик ходов

		std::cout << "10: Step_Counter = " << StepCounter << std::endl << std::endl;

		if (StepCounter > 5000)	//блок аварийного выхода
		{
			std::cout << "Error: StepCounter > 5000. Program was emergency stopped!";
			EndOfCycle = 1;
			return 0;
		}
	}

	std::cin.ignore(32767, '\n');
	std::cout << "String B: " << SUM_WORDS;

	return 0;
}
