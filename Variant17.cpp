#include <iostream>
#include <string>
#include "bits0stdc++.h"

//�.�.: ������������ �� ������ A ����� ������ B �� �������: � ������ ����� ������� ��� ���������� ��������� ��������� �����.

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
		std::getline(GetLine_CLONELINE, WORD, ' ');	//������ �� ���� ������ ������� ����� � ���������� � ���������� WORD

		WordLength = WORD.size();	//������� ����� ����� � ���������� � WordLength


		if (WORD[WordLength] == '.')	//�������� �� ����� ����������� => ����� ����� (���� �� ����� ����� ���� ����� => ��� ��������� ����� � �����������)
		{
			WORD[WordLength] = '\0';	// '\0' - ����� "������", ������ "", �� ������� �������� ���������� (�� ���� "" - ConstChar, � ConstChar != Char)
			WordLength--;
			EndOfCycle = 1;
		}

		CLONE_WORD = WORD;  //����������� ����� ����� �������� �������������� �����

		while (int i = 0 < WordLength)  //������� 1 (��� ��������������) ����� �� �����������
		{
			CLONE_LINE[0] = '\0';
		}

		std::string LAST_LETTER;	//���������� ��������� ����� �����
		LAST_LETTER = CLONE_WORD[WordLength];  //������ ��������� ����� ��������������� �����

		while (int i = 0 < WordLength)  //������� ��� ����������� � ��������� ����� � �����
		{
			std::string NUMBERS_OF_LETTERS;
			NUMBERS_OF_LETTERS = CLONE_WORD[i];
			if (NUMBERS_OF_LETTERS == LAST_LETTER)  //���������� ������� ����� � ����������
			{
				NUMBERS_OF_LETTERS == "";
				i--;
				WordLength--;
			}
			i++;
		}

		SUM_WORDS = SUM_WORDS + CLONE_WORD; //���������� � ����� ������ ����������� ������������ �����

		if (EndOfCycle == 1)
		{
			SUM_WORDS = SUM_WORDS + ".";
		}

		WORD.clear();  //������� ���������� ����� ��� ��������� ����� �����
		CLONE_WORD.clear();  //� ����� ���� ��������
	}

	std::cin.ignore(32767, '\n');
	std::cout << "String B: " << SUM_WORDS;

	return 0;
}