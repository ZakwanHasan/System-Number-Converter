// code written by Zakwan 2020/03/12
// Update on 2021/04/17

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

unsigned int *ConvertInttoBinary(char* input, int *size );               // Converts Int To Binary
unsigned int *ConvertInttoOctal(char* input, int* size );                // Converts Int To Octal
unsigned int *ConvertInttoHexadecimal(char* input, int* size);           // Converts Int To Hexadecimal

int main()
{
    // handle decimal input number from user 
    char input[50];
    printf("Please insert a Number\n");
    gets_s(input, 50);

    // define size and char output for converted number for each number system
    int sizeBinary[1], sizeOctal[1], sizeHexadecimal[1];
    char outputBinary[50], outputOctal[50], outputHexadecimal[50];

    // convert number to Binary
    unsigned int *BinaryValue = ConvertInttoBinary( input, sizeBinary);
    printf("Binary Value = "); 
    for (int i = 0; i < sizeBinary[0]; i++ )
    {
        outputBinary[i] = *(BinaryValue + i);
    }
    outputBinary[sizeBinary[0]] = '\0';
    printf("%s\n", outputBinary);

    // convert number to Octal
    unsigned int *OctalValue = ConvertInttoOctal( input, sizeOctal );
    for (int i = 0; i < sizeOctal[0]; i++)
    {
        outputOctal[i] = *(OctalValue + i);
    }
    outputOctal[sizeBinary[0]] = '\0';
    printf("Octal Value = %s\n", outputOctal);

    // convert number to Octal
    unsigned int *HexValue = ConvertInttoHexadecimal(input, sizeHexadecimal );
    for (int i = 0; i < sizeHexadecimal[0]; i++)
    {
        outputHexadecimal[i] = *(HexValue + i);
    }
    outputHexadecimal[sizeHexadecimal[0]] = '\0';
    printf("Hexadecimal Value = %s\n", outputHexadecimal);
    return 0;
}

//////////////////////////////////////////////////////////////
// Funtion : Decimal to Binary converter
// Parameter input 
//        input     Number to be converted
//        size      return the size of converted binary array 
// Function return
//        return binary into unsigned int array
//////////////////////////////////////////////////////////////
unsigned int *ConvertInttoBinary(char* input, int* size )
{
    int n = atoi(input);
    int i = 0;
    int BinaryNum[32];
    while (n > 0) {

        BinaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    static unsigned int iresult[32];
    int k = 0;
    for (int j = i-1; j >= 0; j--)
    {
        // offset HexNum to ASCII 0~1 char
        iresult[k] = BinaryNum[j] + 48;
        k++;
    }
    size[0] = k;
    return iresult;
}

//////////////////////////////////////////////////////////////
// Funtion : Decimal to Octal converter
// Parameter input 
//        input     Number to be converted
//        size      return the size array of converted Octal 
// Function return
//        return Octal number into unsigned int array
//////////////////////////////////////////////////////////////
unsigned int *ConvertInttoOctal( char* input, int *size )
{
    int n = atoi(input);
    int i = 0;
    int OctalNum[32];
    while (n > 0) {

        OctalNum[i] = n % 8;
        n = n / 8;
        i++;
    }

    static unsigned int iresult[32];
    int k = 0;
    for (int j = i-1; j >= 0; j--)
    {
        // offset HexNum to ASCII 0~9 char
        iresult[k] = OctalNum[j] + 48;
        k++;
    }
    size[0] = k;
    return iresult;
}
//////////////////////////////////////////////////////////////
// Funtion : Decimal to Hexadecimal converter
// Parameter input 
//        input     Number to be converted
//        size      return the size array of converted Hexadecimal 
// Function return
//        return Hexadecimal number into unsigned int array
//////////////////////////////////////////////////////////////
unsigned int *ConvertInttoHexadecimal(char* input, int *size )
{
    int n = atoi(input);
    int i = 0;
    int HexNum[32];
    int remainder;

    while (n > 0) {

        remainder = n % 16;
        if (10 > remainder)
        {
            // offset HexNum to ASCII 0~9 char
            HexNum[i] = 48 + remainder;
        }
        else
        {
            // offset HexNum to ASCII A~F char
            HexNum[i] = 55 + remainder;
        }
        n = n / 16;
        i++;
    }

    static unsigned int iresult[32];
    int k = 0;
    for (int j = i-1; j >= 0; j--)
    {
        iresult[k] = HexNum[j];
        k++;
    }
    size[0] = k;
    return iresult;
}

