#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode* next;
};

#define NEW_STRUCT(name)		struct ListNode __LINE__##_l###name;			\
								result_struct->next = &__LINE__##_l###name


struct ListNode* addTwoNumbers(struct ListNode*, struct ListNode*); 
int length_struct(struct ListNode*, struct ListNode*);
struct ListNode* int_to_struct(int);

int main(int argc, int* argv)
{
	struct ListNode l1_a = { .val = 9 };
	struct ListNode l1_b = { .val = 9 };
	struct ListNode l1_c = { .val = 9 };
	struct ListNode l1_d = { .val = 9 };
	struct ListNode l1_e = { .val = 9 };
	struct ListNode l1_f = { .val = 9 };
	struct ListNode l1_g = { .val = 9 };

	struct ListNode l2_a = { .val = 9 };
	struct ListNode l2_b = { .val = 9 };
	struct ListNode l2_c = { .val = 9 };
	struct ListNode l2_d = { .val = 9 };

	l1_a.next = &l1_b;
	l1_b.next = &l1_c;
	l1_c.next = &l1_d;
	l1_d.next = &l1_e;
	l1_e.next = &l1_f;
	l1_f.next = &l1_g;

	l2_a.next = &l2_b;
	l2_b.next = &l2_c;
	l2_c.next = &l2_d;


	struct ListNode* res = addTwoNumbers(&l1_a, &l2_a);
	printf("%d", res->val);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	static struct ListNode result;							//сумма чисел структур
	static int result_type_int = 0;							//сумма чисел в формате int
	int sum_digits;											//сумма цифр					
	int remains_sum = 0;									//остаток суммы цифр

	int length_number_sum = length_struct(l1, l2);
	int x = l1->val;
	int y = l2->val;


	for (size_t i = 0; (i < length_number_sum) || (remains_sum != 0); i++)
	{
		if ((sum_digits = x + y + remains_sum) > 9) {
			//result.val = (sum_digits % 10);
			result_type_int = ((result_type_int * 10) + (sum_digits % 10));
			remains_sum = sum_digits / 10;
		}
		else {
			//result.val =  sum_digits;
			result_type_int = ((result_type_int * 10) + sum_digits );
			remains_sum = 0;
		}

		if (l1->next != NULL) {
			l1 = l1->next;
			x = l1->val;
		}else
		{
			x = 0;
		}

		if (l2->next != NULL) {
			l2 = l2->next;
			y = l2->val;
		}else
		{
			y = 0;
		}
		printf("%d\n", result_type_int);

	}
	int_to_struct(result_type_int);
	return &result;
}

int length_struct(struct ListNode* l1, struct ListNode* l2) {
	int length_struct_l1 = 1;
	int length_struct_l2 = 1;
	int length_struct_return;

	while ((l1 = l1->next) != NULL)
		length_struct_l1++;

	while ((l2 = l2->next) != NULL)
		length_struct_l2++;

	if ((length_struct_return = length_struct_l1) >= length_struct_l2);
	else length_struct_return = length_struct_l2;

	return length_struct_return;
}

struct ListNode* int_to_struct(int result_int) {
	struct ListNode* result_struct;
	
	result_struct->next = new (ListNode);

	/*while (result_int != 0)
	{
		struct ListNode a;
		result_struct->val = result_int % 10;
		result_int /= 10;
		printf("\n%d\n", result_struct->val);
		printf("%x\n", result_struct->next);
		result_struct->next = &a;
		result_struct = result_struct->next;
		i++;
	}*/
	//return result_struct;
	return 0;
}