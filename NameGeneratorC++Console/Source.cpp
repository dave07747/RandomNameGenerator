#include <iostream>
#include <string>
#include <fstream>
using namespace std;


		static bool endSearch = false;

		static int count1 = 0;
		static int count2 = 2;
		static int count3 = 8;
		static int count4 = 16;
		static int count5 = 2;
		static int count6 = 17;
		static int count7 = 20;

		char cons [20] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j',
			'k', 'l', 'm', 'n', 'p', 'q', 'r',
			's', 't', 'v', 'w', 'x', 'z' };

		 char vowel [6] = { 'a', 'e', 'i', 'o', 'u', 'y' };

		 char all [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
			's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

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
				

				for (int i = 0; i < 9; ++i) // Check for double letter
				{

					y = x;
					x = name[i];

					if (x == y)
					{
						if (x != 'o'){
							check = true;
							break;
						}
					}
				}

				if (check == false)
					continue;
				
				check = false;

				for (int i = 0; i < 9; ++i) // Check for letter K
				{
					x = name[i];
					if (x == 'k')
					{
						check = true;
						break;
					}

				}

				if (check == true)
					break;
			
			}
			return name;
		}



		int main()
		{
			ofstream author;
			author.open("names2.txt");
			cout << "\a";

			while (true)
			{
				string name;
				name = makeName();
				author << name << endl;

				if (endSearch == true){
					cout << "The End!\a";
					break;
				}
			}
		}