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

            Console.WriteLine(convertSimple(input, 4));
        
        }

        private static string convert(string s, int numRows)
        {

            char[] res = new char[s.Length];
            char[] inp = s.ToCharArray();

            double index = 0;
            double length = Convert.ToDouble(s.Length);
            double diagonals = Math.Max(0, numRows - 2);
            double pattern = Math.Max(0, numRows - 2) + numRows;
            double repeats = Math.Ceiling(length / pattern);

            int empties = 0;
            
            for(int i = 0; i < res.Length + empties; i++)
            {

                index = (i / pattern); 


            }

            res[8] = 'k';

            return new string(res);

        }

        private static string convertSimple(string s, int numRows)
        {

            int length = s.Length;
            int diagonals = Convert.ToInt32(Math.Max(0, numRows - 2));
            int patternSize = Convert.ToInt32(Math.Max(0, numRows - 2) + numRows);
            int repeats = Convert.ToInt32(Math.Ceiling(Convert.ToDouble(length) / patternSize));
            int patternWidth = Convert.ToInt32(diagonals + 1);

            Console.WriteLine($"patternSize = {patternSize}");
            Console.WriteLine($"repeats = {repeats}");
            Console.WriteLine($"patternWidth = {patternWidth}");

            string[,] res = new string[Convert.ToInt32(repeats) * Convert.ToInt32(patternWidth), numRows];
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
                    
                    res[Convert.ToInt32(x), Convert.ToInt32(y)] = inp[i].ToString();
                }
                
                else
                {
                    x = ((i%patternSize)-numRows+1) + i/patternSize*patternWidth;
                    y = numRows - (i % patternSize) + 2;
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
