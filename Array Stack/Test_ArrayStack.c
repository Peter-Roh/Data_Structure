#include "ArrayStack.h"

int main(void)
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 5);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);
	AS_Push(Stack, 47);

	printf("Capacity : %d, Size : %d, Top : %d\n\n", 
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	printf("Is Stack Full? : %s\n\n", AS_IsFull(Stack) == 1 ? "Yes" : "No");

	AS_Push(Stack, 25);

	printf("Capacity : %d, Size : %d, Top : %d\n\n", 
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	printf("Is Stack Full? : %s\n\n", AS_IsFull(Stack) == 1 ? "Yes" : "No");

	for(i = 0; i < 5; i++)
	{
		if(AS_IsEmpty(Stack))
			break;

		printf("Popped : %d, ", AS_Pop(Stack));

		if(! AS_IsEmpty(Stack))
			printf("Current Top : %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}

	printf("\n");

	printf("Capacity : %d, Size : %d, Top : %d\n\n", 
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	printf("Is Stack Full? : %s\n\n", AS_IsFull(Stack) == 1 ? "Yes" : "No");

	for(i = 5; i < 6; i++)
	{
		if(AS_IsEmpty(Stack))
			break;

		printf("Popped : %d, ", AS_Pop(Stack));

		if(! AS_IsEmpty(Stack))
			printf("Current Top : %d\n", AS_Top(Stack));
		else
			printf("Stack Is Empty.\n");
	}


	AS_DestroyStack(Stack);

	return 0;
}