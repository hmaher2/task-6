#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
void RemovingSpaces(string &word3 );
void RemovingPunct(string &word3 );
void RemovingCapital(string  &word3);
void DetectAnagram(string &word4, string &word5);

int main()
{
    cout<<"Ahlan ya user"<<endl<<"Enter the first word : "<<endl;
    string word1,word2;
    getline(cin,word1);

    RemovingSpaces(word1);
    RemovingPunct(word1 );
    RemovingCapital(word1 );

    cout<<"Enter the second word" <<endl;
    getline(cin,word2);
    RemovingSpaces(word2);
    RemovingPunct(word2 );
    RemovingCapital(word2 );
    DetectAnagram(word1,word2 );



    return 0;
}

//------------------------------------------------------------//
void RemovingSpaces(string &word3 )
{
    for(int i =0; word3[i]; i++)
    {
        if (word3[i]==' ')                            //Using the erase remove idiom to remove spaces from strings
        {
            {
                word3.erase(std::remove(word3.begin(), word3.end(), word3[i]), word3.end());
            }
        }
    }
}


//------------------------------------------------------------//
void RemovingPunct(string  &word3)  //Using the erase remove idiom to remove punctuations  from strings
{
    for( unsigned int i =0; word3[i]; i++)
    {

        if (((int (word3[i]) > 33) &&  (int (word3[i]) < 64))   || (int (word3[i]) == 64) || (int (word3[i]) == 33))

        {
            word3.erase(std::remove(word3.begin(), word3.end(), word3[i]), word3.end());  // removing !	" #	 $	% &	'(	) *	+ ,	- .	: ;	< =	> ? / @
        }
    }

    for(int i =0; word3[i]; i++)
    {
        if  (((int (word3[i]) > 91) &&  (int (word3[i]) < 96))   || (int (word3[i]) == 96) || (int (word3[i]) == 91))  // removing [ \ ]^ _	`
        {
            word3.erase(std::remove(word3.begin(), word3.end(), word3[i]), word3.end());
        }
    }

    for(int i =0; word3[i]; i++)
    {
        if (((int (word3[i]) > 123) &&  (int (word3[i]) < 126))   || (int (word3[i]) == 126) || (int (word3[i]) == 123)) // removing   { ¦	}	~

        {
            word3.erase(std::remove(word3.begin(), word3.end(), word3[i]), word3.end());
        }
    }
}

//------------------------------------------------------------//
void RemovingCapital(string &word3 )  // getting rid of capital letters
{
    for(int i =0; word3[i]; i++)
    {
        if (((int (word3[i]) > 65) &&  (int (word3[i]) < 90)) || (int (word3[i]) == 65) || (int (word3[i]) == 90))
        {
            word3[i]=char((int(word3[i])) +32);
        }
    }
}
//------------------------------------------------------------//
void DetectAnagram(string &word4, string &word5)
{
    int c =0 ;
    if (sizeof(word4)!=sizeof(word5))
    {
        cout<<"they are not anagrams"<<endl;
    }
    else
    {

        for(int i =0; word4[i]; i++)
        {
            for(int j=0; word5[j]; j++)
            {
                if (word4[i]==word5[j])
                {
                    c=c+1;
                }
            }
        }

        if (c==sizeof(word4)-1)
        {
            cout<<" the two words are anagram"<<endl;
        }

        else
        {
            cout << "the two words are not anagram " <<endl;
        }
    }
}

