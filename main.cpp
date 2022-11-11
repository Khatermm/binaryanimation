#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "windows.h"
//#include <unistd.h>

using namespace std;

fstream plik;

void wypiszobraz(int row, int col)
{
    char c[1];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // c = " ";
            plik.read(c, 1);
            if ((c == " ") || (c == ""))
            {
                continue;
            }
            else
            {
                if (c[0] == '0')
                {
                    std::cout << " ";
                }
                else if (c[0] == '1')
                {
                    int v = rand() % 2;
                    std::cout << v;
                }
                // else if (c[0] == ' ')
                //{
                //     continue;
                // }
                else
                {
                    cout << c[0];
                }
            }

            // usleep( 1 );
        }
        // cout<<endl;
    }
    // std::cout << endl << c[0] << endl ;
}

int main()
{
    int n = 0;
    plik.open("obraz.pbm", ios::in | ios::binary);
    if (plik.good() == true)
    {
        // std::cout << "Uzyskano dostep do pliku!" << std::endl;

        char ss1[255];
        char ss2[255];
        // char c[1];

        while (n < 10)
        {

            plik.getline(ss1, 255);
            plik.getline(ss2, 255);

            // int row;
            // int col;

            // for (int i = 0; i < 255; i++)
            // {
            //     if (ss2[i] == " ")
            //     {
            //     }
            // }

            // std::cout << ss1 << endl << ss2 << endl ;

            system("CLS");

            wypiszobraz(50, 50 * 2);
            // usleep(100000);
            Sleep(100);
            plik.seekg(0, plik.beg);
            n++;
        }

        std::cout << endl;
    }
    else
        std::cout << "ops!" << std::endl;

    return 0;
}