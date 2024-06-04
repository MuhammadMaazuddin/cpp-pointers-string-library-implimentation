#include <iostream>
#include<cstring>
int  Strlen(const char* s1)
{
    int length = 0;
    for(int i=0;*(s1+i)!='\0';i++)
    {
        length++;
    }

    return length;
}
using namespace std;
void countLetters(const char *string, int *&array, int & AlphabetSize) 
{
    AlphabetSize = 26;  
    array = new int[AlphabetSize];  
    char check;

    for (int i = 0; i < *(string+i)!='\0'; i++)     
    {
        check = tolower(*(string +i));  
        
        if (check >= 97 && check <= 122) 
        {  
            array[check - 97]++;  
        }
    }
}


void countWordsBasedOnLength(const char* input, int*& output, int& size) {
    
    int InputLength = Strlen(input);

    
    output = new int[InputLength];
    size = 0;
char alpha;
    
    int WordLength = 0;

    for (int i = 0; i < InputLength; i++) 
    {
         alpha = *(input+i);
        if ((alpha == 32) || (alpha == 10) || (alpha == 13) || (alpha == 9)) 
{
            
            if (WordLength > 0) 
            {
                if (WordLength > size) 
                {
                        int* NewOutput = new int[WordLength];

                    
                    for (int j = 0; j < size; j++) 
                    {
                        *(NewOutput+j) = *(output);
                    }
                    output = NewOutput;
                    size = WordLength;
                }     delete[] output;

                output[WordLength - 1]++;
                WordLength = 0;
            }
        } else {
            
            WordLength++;
        }
    }

    
    if (WordLength > 0) 
    {
        if (WordLength > size) {
            
            int* NewOutput = new int[WordLength]();
            for (int j = 0; j < size; j++) {
                NewOutput[j] = output[j];
            }
            delete[] output;
            output = NewOutput;
            size = WordLength;
        }
        output[WordLength - 1]++;
    }                   

}


int main() 
{
    ///////////////
    //function 1
    char* const  string = new char[200];
    cout<<"Enter the string  ::  ";
    fgets(string, 200, stdin);
    int *array;
    int AlphabetSize;
    countLetters(string, array, AlphabetSize);
    char alpha = 'a';
    for (int i = 0; i < AlphabetSize; i++) 
    {
        cout <<" -->  "<< alpha << "  ::  " << *(array+i) << endl;
        alpha++;
    }
    //////////////
    //function 2
    char* const  input = new char[200];
    cout<<"Enter the words  ::  ";
    fgets(input, 200, stdin);
    int* output;
    int size;
    countWordsBasedOnLength(input, output, size);
    for (int i = 0; i < size; i++) {
    cout <<" Number of "<< i + 1<< " letter words is  :: " << *(output+i)<< endl;
    }
    //////////////
    //fucntion 3

   
    delete[] input;
    
    delete[] output;
 
    return 0;
}


