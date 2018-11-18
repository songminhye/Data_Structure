#include <stdio.h>

struct student {
	char name[20];
	int age;
	int score;
	struct student* friend;

};

typedef struct student STD;

int main(){

	struct student s1 = {"Hong",23,99};
	STD	       s2 = {"Park", 21, 76};      	
	
	s1.friend = &s2;
	s2.friend = &s1;	
	
	printf("student name : %s\n",s1.name);
	printf("student age  : %d\n",s1.age);
	printf("student score: %d\n",s1.score);
	//printf("friend name  : %s\n",*(s1.friend).name);
	printf("friend name  : %s\n",s1.friend -> name);
	
	printf("student name : %s\n",s2.name);
	printf("student age  : %d\n",s2.age);
	printf("student score: %d\n",s2.score);
	return 0;
}
