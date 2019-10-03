package SPCDay2;

import java.util.Queue;
import java.util.Scanner;
import java.util.LinkedList;

public class Main {

	public static void main(String[] args)
	{
		
		Queue<Integer> Q=new LinkedList<Integer>();
		
		Scanner sc = new Scanner(System.in);
		
		//get first line
		int S = -1;
		
		//until end of input
		while (true)
		{
			
			S = sc.nextInt();
			
			if (S == 0)
			{
				break;
			}
			
			Q.add(S);
			
		}
		
		
		sc.close();
		
		PrintNumbers(Q);
		
	}
	
	
	public static void PrintNumbers(Queue<Integer> Q)
	{
		int a = 0;
		
		Queue<Integer> W=new LinkedList<Integer>();
		
		while (Q.size() > 0) 
		{
	
			if (a!=0)
			{
				System.out.println();
				
			}
			a=1;
		int S = Q.poll();
		
		for (int i = 1; i<=S; i++)
			{
				W.add(i);
			}
		
			int j = 0;
			
			while (W.size() > 1)
			{
				if (j==0)
				{
					System.out.print("Discarded cards: " + W.poll());
				}
				else
				{
					System.out.print(", " + W.poll());
				}
				
				j = 1;
				
				W.add(W.poll());
				
			}
			
			System.out.println();
			System.out.print("Remaining card: " + W.poll());

		}	
		
	}
	
}
