using System;
using System.Linq;
using System.Runtime.InteropServices;

namespace ZigZagConversionProject
{
    class Program
    {
        static void Main(string[] args)
        {

            string input = "PAYPALISHIRING";

            Console.WriteLine(convert(input, 5));
        
        }

        private static string convert(string s, int numRows)
        {

            int length = s.Length;
            int diagonals = Convert.ToInt32(Math.Max(0, numRows - 2));
            int patternSize = Convert.ToInt32(Math.Max(0, numRows - 2) + numRows);
            int repeats = Convert.ToInt32(Math.Ceiling(Convert.ToDouble(length) / patternSize));
            int patternWidth = Convert.ToInt32(diagonals + 1);

            Console.WriteLine($"patternSize = {patternSize}");
            Console.WriteLine($"repeats = {repeats}");
            Console.WriteLine($"patternWidth = {patternWidth}");

            string[,] res = new string[repeats * patternWidth, numRows];
            char[] inp = s.ToCharArray();

            int x;
            int y;

            for (int i = 0; i < s.Length; i++)
            {
                // If not diagonal letter
                if (i % patternSize < numRows)
                {
                    x = (i / patternSize) * patternWidth;                    
                    y = (i % patternSize % numRows);
                    
                    res[x, y] = inp[i].ToString();
                }
                
                else
                {
                    x = ((i%patternSize)-numRows+1) + i/patternSize*patternWidth;
                    y = numRows - ((i % patternSize) - numRows) - 2;
                    Console.WriteLine($"letter {i}: {x},{y}");
                    res[x, y] = inp[i].ToString();
                }
                
            }


            for (y = 0; y < numRows; y++)
            {
                for (x = 0; x < repeats * patternWidth; x++)
                    if (res[x, y] == null)
                        Console.Write(" ");
                else
                    Console.Write(res[x, y]);
                Console.WriteLine();
            }
                


            string ret = "";
            for (y = 0; y < numRows; y++)
                for (x = 0; x < repeats * patternWidth; x++)
                    ret += res[x, y];

            return ret;

        }

    }
}
