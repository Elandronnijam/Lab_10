#include <iostream>
#include <string>
#include "bits0stdc++.h"

//������������ �� ������ A ����� ������ B �� �������: � ������ ����� ������� ��� ���������� ��������� ��������� �����.

/*
	� � � � � � �

	std::string A = "A"
	std::getline (Otkuda, Kuda, Konec)
	.size()



*/
/*
 
	1. ����� ��������� ����� � ������ �����, ��������� �
	2. ������� � ����� ����� �������� ��� ����� ������ ����� � ���������� ������
	3. ���������� �������

*/

/*

	1. ������������ �������� ����� ����� ������������ ����-����� - ����.
	1.1. ���� �� ����� ������� �����, ����������� �� ���������.
	1.2. ���� �� ����� ����� ������, ����� �� ����������
	1.3. ����:
	1.3.1. ��������� ����������� ������ std::string STROKA � ����� SLOVO
	1.3.2. ������ �� ����������� 	
	1.3.3. ��������� ���� ����������� KLON_STROKI = STROKA, ���� ����� KLON_SLOVA � �������� ���������� SUMMA_SLOV
	1.3.4. ��������� ��������� ���������� (dlina_slova)
	1.3.5. 
	
		While (KonecCikla != 666)
		   {

				std::getline (KLON_STROKI, SLOVO, " ")  //��������� �� ����������� 1 ������� �����

				dlina_slova = SLOVO.size()  //������ ����� 1 �����

				if (SLOVO[dlina_slova] == ".")	//�������� �� ����� ����������� => ����� �����
				{
					SLOVO[dlina_slova] = "";
					dlina_slova--
					KonecCikla = 666;
				}

				KLON_SLOVA = SLOVO;  //����������� ����� ����� �������� �������������� �����

				while (i = 0 < dlina_slova)  //������� 1 (��� ��������������) ����� �� �����������
				{
					KLON_STROKI [0] = "";
				}

				std::string POSLEDNYAYA_BUKVA_SLOVA = KLON_SLOVA[dlina_slova]  //������ ��������� ����� ��������������� �����
				
				while (i = 0 < dlina_slova)  //������� ��� ����������� � ��������� ����� � �����
				{
					if (KLON_SLOVA[i] == POSLEDNYAYA_BUKVA_SLOVA)  //���������� ������� ����� � ����������
					{
						KLON_SLOVA[i] == "";
						i--;
						dlina_slova--;
					}
					i++
				}

				SUMMA_SLOV = SUMMA_SLOV + KLON_SLOVA //���������� � ����� ������ ����������� ������������ �����

				If (KonecCikla == 666)
				{
					SUMMA_SLOV = SUMMA_SLOV + ".";
				}

				SLOVO.clear  //������� ���������� ����� ��� ��������� ����� �����
				KLON_SLOVA.clear  //� ����� ���� ��������
		   }

	2. ������ ������-�����
	3. ������ ����� ������ ����� (N, ������� ��������� ���������� � 0)
	4. ������ ������� LETTER ������-����� ��� ������� N (��������� �������)
	5. ���� while (i = 0 < N) -> {if (������� ����� i == LETTER) -> { ������� ����� i = "" } i++ }		//	��� m.clear();	if (m.empty())
	6. �������� ����� (������ �����)

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

	int EndOfCycle = 0;												//����������, ������������ �� ����� �� ����� ����
	int StepCounter = 0;											//������� ���� �����
	int WordLength = 0;												//����� �����

	std::string LINE = DANO;										//������� ������
	std::string CLONE_LINE = LINE;									//��������� ���������� ��� �����. ������
	std::string WORD;												//���������� ��� ���� �� �����������
	std::string CLONE_WORD;											//Ÿ ����
	std::string SUM_WORDS;											//��������� ������

	std::stringstream GetLine_CLONELINE(CLONE_LINE);
	std::stringstream GetLine_CLONE_WORD(CLONE_WORD);


	while (EndOfCycle != 1)		//�������� ������ �����������
	{
		std::cout << "Your text: " << CLONE_LINE << std::endl;
		
		std::getline (GetLine_CLONELINE, WORD, ' ');	//������ �� ���� ������ ������� ����� � ���������� � ���������� WORD

		std::cout << "1: Word: " << WORD << std::endl;

		WordLength = WORD.size();	//������� ����� ����� � ���������� � WordLength

		std::cout << "2: WordLength = " << WordLength << std::endl;

		if (WORD[WordLength] == '.')	//�������� �� ����� ����������� => ����� ����� (���� �� ����� ����� ���� ����� => ��� ��������� ����� � �����������)
		{
			WORD[WordLength] = '\0';	// '\0' - ����� "������", ������ "", �� ������� �������� ���������� (�� ���� "" - ConstChar, � ConstChar != Char)
			WordLength--;
			EndOfCycle = 1;
		}

		std::cout << "3: EndOfCycle = " << EndOfCycle << std::endl;

		CLONE_WORD = WORD;  //����������� ����� ����� �������� �������������� �����

		std::cout << "4: CLONE_WORD = " << CLONE_WORD << std::endl;

		int Counter1 = 0;

		while (Counter1 < WordLength + 1)  //������� 1 (��� ��������������) ����� �� �����������, +1 ����� ��� ������� �������, �������� �� ������.
		{
			CLONE_LINE[Counter1] = '\0';	/*
											��������� ��������� ���������� ����� ������� ������� � ����, ������ �������� ������ �� ������ ���� ����� 
											� ���������� ����������,� ���� � ��������� �������� [0], ����� ����� ������ ������ �� ���, 
											�.�. ������ �������� �� ����� ����������� "0" ����� ����� �������� ������ �����.
											*/
			Counter1++;
			if (Counter1 > 5000)	//��������� �����
			{
				std::cout << "Error: Counter 1 > 5000. Program was emergency stopped!";
				return 0;
			}
		}

		Counter1 = 0;

		std::cout << "5: CLONE_LINE = " << CLONE_LINE << std::endl;

		std::string LAST_LETTER;	//���������� ��������� ����� �����
		LAST_LETTER = CLONE_WORD[WordLength - 1];  //������ ��������� ����� ��������������� �����

		std::cout << "6: LAST_LETTER (of WORD) = " << LAST_LETTER << std::endl;

		int Counter2 = 0;

		while (Counter2 < WordLength)  //������� ��� ����������� � ��������� ����� � �����
		{
			std::string NUMBERS_OF_LETTERS;
			NUMBERS_OF_LETTERS = CLONE_WORD[Counter2];
			if (NUMBERS_OF_LETTERS == LAST_LETTER)  //���������� ������� ����� � ����������
			{
				NUMBERS_OF_LETTERS == "";
				Counter2--;
				WordLength--;
			}
			Counter2++;
			if (Counter2 > 5000)	//��������� �����
			{
				std::cout << "Error: Counter 2 > 5000. Program was emergency stopped!";
				return 0;
			}
		}

		std::cout << "7: CLONE_WORD = " << CLONE_WORD << std::endl;

		SUM_WORDS = SUM_WORDS + CLONE_WORD; //���������� � ����� ������ ����������� ������������ �����

		if (EndOfCycle == 1)	//������ ����� � ����� ��������������� �����������
		{
			SUM_WORDS = SUM_WORDS + ".";
		}

		std::cout << "8: SUM_WORDS = " << SUM_WORDS << std::endl;

		WORD.clear();  //������� ���������� ����� ��� ��������� ����� �����
		CLONE_WORD.clear();  //� ����� ���� ��������

		std::cout << "9: WORD.clear/CLONE_WORD.clear = " << WORD << CLONE_WORD << std::endl;

		StepCounter++;	//������� �����

		std::cout << "10: Step_Counter = " << StepCounter << std::endl << std::endl;

		if (StepCounter > 5000)	//���� ���������� ������
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
