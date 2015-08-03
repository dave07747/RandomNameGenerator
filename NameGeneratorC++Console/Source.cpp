#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
		
		string letter = "n";
		char chosen;
		string exclude = "n";
		char letterExclude;
		string doubleLetter = "n";

		static bool endSearch = false;

		static int count1 = 0;
		static int count2 = 0;
		static int count3 = 0;
		static int count4 = 0;
		static int count5 = 0;
		static int count6 = 0;
		static int count7 = 0;

		char cons [20] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j',
			'k', 'l', 'm', 'n', 'p', 'q', 'r',
			's', 't', 'v', 'w', 'x', 'z' };

		 char vowel [6] = { 'a', 'e', 'i', 'o', 'u', 'y' };

		 char all [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
			's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

		 bool is_file_exist(const char *fileName)
		 {
			 std::ifstream infile(fileName);
			 return infile.good();
		 }

		 void clear_screen(char fill = ' ') {
			 /*******************/
			 /*** Taken from ****/
			 /*StackOverflow.com*/
			 /*******************/

			 COORD tl = { 0, 0 };
			 CONSOLE_SCREEN_BUFFER_INFO s;
			 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			 GetConsoleScreenBufferInfo(console, &s);
			 DWORD written, cells = s.dwSize.X * s.dwSize.Y;
			 FillConsoleOutputCharacter(console, fill, cells, tl, &written);
			 FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
			 SetConsoleCursorPosition(console, tl);
		 }

		 string makeName()
		{
			string name = " ";
			
		
			while (true)
			{
				
				name = " ";

				name += cons[count1];
				name += vowel[count2];
				name += all[count3];
				name += all[count4];
				name += all[count5];
				name += all[count6];
				name += all[count7];
				

				count1++;
				if (count1 >= 20)
				{
					count1 = 0;
					count2++;
				}
				if (count2 == 6)
				{
					count2 = 0;
					count3++;
				}
				if (count3 == 26)
				{
					count3 = 0;
					count4++;
				}
				if (count4 == 26)
				{
					count4 = 0;
					count5++;
				}
				if (count5 == 26)
				{
					count5 = 0;
					count6++;
				}
				if (count6 == 26)
				{
					count6 = 0;
					count7++;
				}
				if (count7 == 26)
				{
					count7 = 0;
					endSearch = true;
				}

				char x = '1';
				char y = '0';
				bool check = false;
				

				for (int i = 0; i < 9; ++i) // Check for double letter and excludes
				{

					y = x;
					x = name[i];
					if (doubleLetter == "y"){
						if (x == y)
						{
							if (x == 'o')
								break;

							check = true;
						}
					}

					if (exclude == "y"){
						if (x == letterExclude){
							check = false;
							break;
						}
					}
				}



				if (check == false)
					continue;
				
				check = false;

				if (letter == "y"){
					for (int i = 0; i < 9; ++i) // Check for letter 
					{
						x = name[i];
						if (x == chosen)
						{
							check = true;
							break;
						}

					}
				}

				if (check == true)
					break;
			
			}
			return name;
		}


		int main()
		{
			cout << "Welcome to the random name generator! \nWe will generate over 200 million names for you!" << endl << endl;
			system("pause");
			while (true){
				clear_screen();
				cout << "Would you like any specific letters?(y/n): " << endl;
				cin >> letter;
				if (letter == "y" || letter == "n")
					break;
			}
			clear_screen();
			if (letter == "y"){
				cout << "Which letter: ";
				cin >> chosen;
			}
			while (true){
				clear_screen();
				cout << "Would you like to exclude any letters?(y/n): ";
				cin >> exclude;
				clear_screen();
				if (exclude == "y" || exclude == "n")
					break;
			}
			if (exclude == "y"){
				cout << "Which letter would you like to exclude: ";
				cin >> letterExclude;
				clear_screen();
			}

			while (true){
				clear_screen();
				cout << "Would you like double letters?(y/n): ";
				cin >> doubleLetter;
				clear_screen();
				if (doubleLetter == "y" || doubleLetter == "n")
					break;
			}
			cout << "Please enter the name of the file to save into: ";
			string name;
			cin >> name;
			name += ".txt";

			ofstream author;

		
			author.open(name, fstream::app);
			cout << "\a";

			while (true)
			{
				string name;
				name = makeName();
				author << name << endl;

				if (endSearch == true){
					cout << "The End!\a";
					author.close();
					break;
				}
			}
		}

		BOOL SetConsoleCtrlHandler(
			PHANDLER_ROUTINE HandlerRoutine, // handler function
			BOOL Add // add or remove handler
			);

		BOOL WINAPI HandlerRoutine(
			DWORD dwCtrlType   //  control signal type
			);

		BOOL WINAPI ConsoleHandler(DWORD CEvent)
		{
			ofstream writer;
			writer.open("save.txt");

			writer << count1 << endl << count2 << endl << count3 << endl <<
				count4 << endl << count5 << endl << count6 << endl << count7;
			writer.close();

			return TRUE;
		}
