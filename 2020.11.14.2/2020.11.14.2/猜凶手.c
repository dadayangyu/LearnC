#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	char m = 'A';
	for (m = 'A'; m <= 'D'; m++){
		if ((m != 'A') + (m == 'C') + (m == 'D') + (m != 'D') == 3){
			printf("������%c\n", m);
		}
	}
	system("pause");
	return 0;

}