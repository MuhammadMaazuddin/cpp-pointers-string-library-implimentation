#include<iostream>
using namespace std;
int  Strlen(const char* s1)
/*returns the length of string in number of characters...*/
{
    int length = 0;
    for(int i=0;*(s1+i)!='\0';i++)
    {
        length++;
    }

    return length;
}
char *Strcpy( char *s1, const char *s2 )
//Copies string s2 into array s1.
//The value of s1 is returned.
{
    int i;
    for (i = 0; *(s2+i) != '\0'; i++) {
        *(s1+i) = *(s2+i);
    }
    *(s1+i) = '\0';
    return s1;
}

char *strncpy( char *s1, const char *s2, size_t n )
//copies at most n characters of string s2 into array s1.
//The value of s1 is returned.
{
int i;
    for (i = 0; i < n && *(s2+i) != '\0'; i++) {
        *(s1+i) = *(s2+i);
    }
    for ( ; i < n; i++ ) {
        *(s1+i)= '\0';
    }
    return s1;
}
char *StrCat( char *s1, const char *s2 )
/*Appends string s2 to array s1.
The first character of s2 overwrites
the terminating null character of s1.
The value of s1 is returned.*/
{
int i, j;
    for (i = 0; *(s1+i) != '\0'; i++);
    for (j = 0; *(s2+j) != '\0'; j++) {
        *(s1+(i+j)) = *(s2+j);
    }
    *(s1+(i+j)) = '\0';
    return s1;

}
char *StrnCat( char *s1, const char *s2, size_t n )
/*Appends at most n characters of string s2 to array s1.
The first character of s2 overwrites the terminating
null character of s1. The
value of s1 is returned.*/
{
     int i, j;
    for (i = 0; *(s1+i) != '\0'; i++);
    for (j = 0; j < n && *(s2+j) != '\0'; j++) {
        *(s1+(i+j)) = *(s2+j);
    }
    *(s1+(i+j)) = '\0';
    return s1;
}

int StrCmp( const char *s1, const char *s2 )
/*Compares the string s1 with the string s2 .
The function returns 0,
less than 0 or greater than 0 if s1 is equal to,
less than or greater
than s2 , respectively.*/
{
    int i;
    for (i = 0; *(s1+i) == *(s2+i); i++) {
        if (*(s1+i) == '\0') {
            return 0;
        }
    }
    return *(s1+i) - *(s2+i);
}
int StrnCmp( const char *s1, const char *s2, size_t n )
/*
Compares up to n characters of the string
s1 with the string s2 .
The function returns 0 ,
less than 0 or greater than 0 if s1 is equal
to, less than or greater than s2 , respectively.
*/
{
    int i;
    for (i = 0; i < n && *(s1+i) == *(s2+i); i++) {
        if (*(s1+i) == '\0') {
            return 0;
        }
    }
    return (i == n) ? 0 : *(s1+i) - *(s2+i);
}
char **StrTok( char *s1, const char s2)
/*call to StrTok breaks string s1 into
``tokens’’ (logical pieces such as words
in a line of text) separated by character
contained in char s2*/
{
    static char *current = nullptr;
    if (s1) current = s1;
    if (!current) return nullptr;

    char **tokens = new char*[Strlen(current) / 2 + 1];

    int token_count = 0;
    while (*current) {
        // skip over any leading s2 characters
        while (*current == s2) ++current;
        if (!*current) break;

        tokens[token_count++] = current;

        // find the end of the token
        while (*current && *current != s2) ++current;
        if (!*current) break;

        *current++ = '\0';
    }
    tokens[token_count] = nullptr;
    return tokens;
}
int StrFind(char *s1, char *s2)
/*
Searches the string s1 for the first occurrence
of the string s2 and returns its starting index,
if s2 not found returns -1.
*/
{
    int len1 = Strlen(s1);
    int len2 = Strlen(s2);
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if ( *(s1+(i+j)) != *(s2+j))
                break;
        }
        if (j == len2) // Found s2
            return i;
    }
    return -1; // s2 not found
}
char * SubStr (char *str, int pos, int len)
/*
This function returns a newly constructed
string variable with its value initialized
to a copy of a substring of this variable.
The substring is the portion of the string
that starts at character position ``pos’’ and
spans ``len’’ characters (or until the end
of the string, whichever comes first).*/
{
     char *sub = new char[len+1];
    strncpy(sub, str+pos, len);
    sub[len] = '\0';
    return sub;
}
int main()
{
    cout<<"FUNTION 1\n\n";
    ///////////////
    //function 1
    int count = 0;
    char* const  st1 = new char[200];
    char* const  s1 = new char[200];
    cout<<"Enter the words :: ";
    fgets(st1, 200, stdin);    
    count = Strlen(st1);
    cout<<"length of string is :: "<<count<<endl<<endl;
    cout<<"FUNTION 2\n\n";
    ///////////////
    // function 2
    Strcpy(s1, st1);
    cout << "s1 after copying s2: " << s1 << endl<<endl;
    cout<<"FUNTION 3\n\n";
    ///////////////
    //function 3
    char* const  st2 = new char[200];
    char* const  st3 = new char[200];
    cout<<"Enter the words  in array 1 :: ";
    fgets(st2, 200, stdin);
    cout<<"Enter the words in array 2 :: ";
    fgets(st3, 200, stdin);
    size_t n;
    cout << "Enter value of n: ";
    cin >> n;
    strncpy(st3, st2, n);
    cout << "s1 after copying first " << n << " characters of s2: " << st3 << endl<<endl;
    cout<<"FUNTION 4\n\n";
    ///////////////
    //function 4
    char* const  st4 = new char[200];
    char* const  st5 = new char[200];
    fgets(st4, 200, stdin);
    cout<<"Enter the words in array 1 :: ";
    fgets(st4, 200, stdin);
    cout<<"Enter the words in array 2 :: ";
    fgets(st5, 200, stdin);
    StrCat(st5, st4);
    cout << "st5 after concatenating st2: " << st5 << endl<<endl;
    cout<<"FUNTION 5\n\n";
    ///////////////
    //function 5
    char* const  st6 = new char[200];
    char* const  st7 = new char[200];
    cout<<"Enter the words in array 1 :: ";
    fgets(st6, 200, stdin);
    cout<<"Enter the words in array 2 :: ";
    fgets(st7, 200, stdin);
    cout << "Enter value of n: ";
    cin >> n;
    StrnCat(st7, st6, n);
    cout << "st7 after concatenating first " << n << " characters of s2: " << st7 <<endl<<endl;
    cout<<"FUNTION 6\n\n";
    ///////////////
    //function 6
    char* const  st8 = new char[200];
    char* const  st9 = new char[200];
    fgets(st8, 200, stdin);
    cout<<"Enter the words in array 1 :: ";
    fgets(st8, 200, stdin);
    cout<<"Enter the words in array 2:: ";
    fgets(st9, 200, stdin);
    int NUM1 = StrCmp(st9, st8);
    if (NUM1 == 0) {
        cout << "st9 and s2 are equal" << endl<<endl;
    } else if (NUM1 < 0) {
        cout << "st9 is less than s2" << endl<<endl;
    } else {
        cout << "st9 is greater than s2" <<endl<<endl;
    }
    cout<<"FUNTION 7\n\n";
    ///////////////
    //function 7
    cout << "Enter value of n: ";
    cin >> n;

    int NUM2 = StrnCmp(st9, st2, n);
    if (NUM2 == 0) {
        cout << "st9 and s2 are equal for first " << n << " characters" << endl<<endl;
    } else if (NUM2 < 0) {
        cout << "st9 is less than s2 for first " << n << " characters" << endl<<endl;
    } else {
        cout << "st9 is greater than s2 for first " << n << " characters" << endl<<endl;
    }
    cout<<"FUNTION 8\n\n";


    ///////////////
    //function 8
    char* const  st10 = new char[200];
    fgets(st8, 200, stdin);
    cout<<"Enter the words in array  :: ";
    fgets(st10, 200, stdin);
    char **tokens = StrTok(st10, ' ');
    for (int i = 0; tokens[i] != nullptr; ++i) {
        cout << tokens[i] << endl;
    }
    cout<<"FUNTION 9\n\n";


    ///////////////
    //function 9
    char* const  st11 = new char[200];
    char* const  st12 = new char[200];
    cout<<"Enter the words in array 1 :: ";
    fgets(st11, 200, stdin);
    cout<<"Enter the words in array  2:: ";
    fgets(st12, 200, stdin);
    int index = StrFind(st11, st12);
    if (index == -1) {
        cout << "Substring not found!" << endl;
    } else {
        cout << "Substring found at index " << index << endl;
    }
cout<<"FUNTION 10\n\n";


    ///////////////
    //function 10
    
    char* const  st13 = new char[200];
    fgets(st8, 200, stdin);
    cout<<"Enter the words in array  :: ";
    fgets(st13, 200, stdin);
    char *sub = SubStr(st13, 7, 5);
    cout << sub << endl;


    delete []st1;
    delete []s1;
    delete []st2;
    delete []st4;
    delete []st5;
    delete []st6;
    delete []st7;
    delete []st8;
    delete []st9;
    delete []st10;
    delete []st11;
    delete []st12;
    delete []st13;





    return 0;
}