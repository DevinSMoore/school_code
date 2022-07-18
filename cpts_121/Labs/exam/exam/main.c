#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int is_anagram(int intAr1[], int intAr2[], char str1[], char str2[])
{
	int index = 0;
	for (; index < 26; index++)
	{
		intAr1[((int)str1[index]) - 97]++;
		intAr2[((int)str2[index]) - 97]++;
	}
	for (index = 0; index < 26; index++)
	{
		if (intAr1[index] != intAr2[index]) { return 0; }
	}
	return 1;
}

void my_str_copy_variation(char* destination, char* source)
{
	int len = strlen(source), index = 0;
	source++;
	
	for (; index < (len / 2); index++, destination++, source += 2)
	{
			*destination = *source;
	}
	*destination = '\0'; // adds the null char to the end of the copied characters making it a string
}


int is_reverse(char str1[], char str2[])
{
	int len1 = strlen(str1), len2 = strlen(str2), strCompCheck = 0, index1 = 0, index2 = len2 - 1;
	if (len1 == len2)
	{
		for (; index1 < len1; index1++, index2--)
		{
			if (tolower(str1[index1]) != tolower(str2[index2])) {return 0;}
		} 
		return 1;
	} 
	return 0;
}

int sum_squares(int maxTerm)
{
	int minTerm = 1, sum = 0;
	for (; minTerm <= maxTerm; minTerm++)
	{
		sum += pow(minTerm, 2);
	}
	return sum;
}

double calculate_grade_point(char letterGrade)
{
	switch (letterGrade)
	{
		case ('A'):
			return 4.0;
			break;
		case ('B'):
			return 3.0;
			break;
		case ('C'):
			return 2.0;
			break;
		case ('D'):
			return 1.0;
			break;
		case ('F'):
			return 0.0;
			break;
		default:
			return -1.0;
			break;
	}
}

int main(void)
{

	int sum = 0, next = 1, bound = 15;
	for (; next <= bound; sum += next, next += 2) {}

	printf("value of sum: %d\n", sum);
	sum = 0, next = 1, bound = 15;
	while (next <= bound) {
		sum += next;
		next += 2;
	}

	printf("value of sum: %d\n", sum);

	//int intAr1[26] = { 0 }, intAr2[26] = { 0 };
	//char str1[100] = "cababzfdfdz", str2[100] = "aabxutbbbzz";

	//printf("is it an anagram? 1 = yes 0 = no\n???: %d\n", is_anagram(intAr1, intAr2, str1, str2));
	//printf("+-----------------------------------------------+\n");
	//printf("|   character   | intAr1 value  | intAr2 value  |\n");
	//printf("+-----------------------------------------------+\n");
	//for (int i = 0; i < 26; i++)
	//{
	//	printf("|\t%c\t|\t%d\t|\t%d\t|\n", (i + 97), intAr1[i], intAr2[i]);
	//}	printf("+-----------------------------------------------+\n");

	//char charArray[100], sourceArray[100] = "123456789101112131415161718192021222324252627282930";

	//my_str_copy_variation(charArray, sourceArray);
	//puts(charArray);
	//puts(sourceArray);


	//int int1 = 0;
	//char str1[20] = "test string", str2[20] = "string test";
	//int1 = is_reverse(str1, str2);
	//printf("val of int1: %d", int1);

	//int sum = 0;
	//for (int i = 1; i <= 100; i++)
	//{
	//	sum = sum_squares(i);
	//	printf("sum of squares to %d: %d\n", i, sum);
	//}






	/*double val = 0.0;

	val = calculate_grade_point('A');
	printf("val('A'): %lf\n", val);
	val = calculate_grade_point('B');
	printf("val('B'): %lf\n", val);
	val = calculate_grade_point('C');
	printf("val('C'): %lf\n", val);
	val = calculate_grade_point('D');
	printf("val('D'): %lf\n", val);
	val = calculate_grade_point('F');
	printf("val('F'): %lf\n", val);
	val = calculate_grade_point('G');
	printf("val('G'): %lf\n", val);
*/




	//char vehicle[20] = "porsche", my_candy[5] = "twix";
	//int rand0 = 0, rand1 = 0, rand2 = 0, rand3 = 0, rand4 = 0, rand5 = 0;
	//rand0 = strlen(vehicle);
	//printf("after strlen, before strcmp: \n");
	//puts(vehicle);
	//puts(my_candy);
	//rand1 = (strcmp("ford", vehicle));
	//printf("\nafter strcmp, before strncpy: \n");
	//puts(vehicle);
	//puts(my_candy);
	///*printf("string length: %d\n", rand0);
	//printf("contents of my_candy[4]: %c\n", my_candy[4]);
	//printf("value of (strcmp(\"ford\", vehicle)): %d\n\n\n", rand1);*/
	//strncpy(my_candy, vehicle, 2);
	//printf("\nafter strncpy, before strcat: \n");
	//puts(vehicle);
	//puts(my_candy);
	//strcat(vehicle, &my_candy[0]);
	//printf("\nafter strcat:\n");
	//puts(vehicle);
	//puts(my_candy);
	//printf("contents of vehicle[3]: %c\n", vehicle[3]);
	//puts(vehicle);
	//printf("contents of my_candy[2]: %c\n", my_candy[2]);
	return 0;
}