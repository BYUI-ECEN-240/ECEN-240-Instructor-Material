using System.Collections.Generic;
using System;
using microcode;


// See https://aka.ms/new-console-template for more information
List<int> result = new List<int>();
Console.WriteLine("Hello, World!");
result = UniqueSevenDigitNumber.Generate();   //program execution starts from here


// See https://aka.ms/new-console-template for more information

// class Program
// {
    // static void Main()
    // {
     // myNumbers = new(UniqueSevenDigitNumbers);
    // Console.WriteLine("Hello, World!");
    // Console.WriteLine("MyNumbers: ", myNumbers);
    // result = UniqueSevenDigitNumber.Generate();   //program execution starts from here
    // }
// }


    




public static class UniqueSevenDigitNumbers
{
    public static List<int> Generate()
    {
        List<int> result = new List<int>();
        GenerateUniqueNumbers(result, new List<int>(), 0);
        return result;
    }

    private static void GenerateUniqueNumbers(List<int> resultList, List<int> currentNumber, int digitIndex)
    {
        if (digitIndex == 7)
        {
            int number = 0;
            for (int i = 0; i < currentNumber.Count; i++)
            {
                number += currentNumber[i] * (int)Math.Pow(10, 6 - i);
            }
            resultList.Add(number);
            return;
        }

        for (int i = 0; i <= 6; i++)
        {
            if (!currentNumber.Contains(i))
            {
                currentNumber.Add(i);
                GenerateUniqueNumbers(resultList, currentNumber, digitIndex + 1);
                currentNumber.RemoveAt(currentNumber.Count - 1); // Backtrack
            }
        }
    }
}
