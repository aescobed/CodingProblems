#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);


int main()
{


	int nums[4] = {2, 7, 11, 15};
	int target = 9;	
	
	int numSize = 4;
	int *returnSize;
	*returnSize = 2;

	int* ans = twoSum(nums, numSize, target, returnSize);

	printf("the indexes are: [%d, %d]", ans[0], ans[1]);

	free(ans);
}




int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

	int *ans = (int*)malloc(*returnSize * sizeof(int));

	for (int i = 0; i < numsSize; i++)
	{

		int difference = target - nums[i];

		//If it is possible to find a number which sums to the target with the number at index i
		if(difference > 0)
		for(int j = i + 1; j < numsSize; j++)
		{
		
			if(nums[j] == difference)
			{
				
				printf("found the numbers");

				//Set answer to the found indices
				ans[0] = i;
				ans[1] = j; 
				
				//Set numsize to 0 to exit outer loop
				numsSize = 0;
				break;
			}
		}

	}

	return ans;	

}

 
