#include <stdio.h>

int t_itr(int n);
int t_rec(int n);

int main(int argc, char *argv[]){
	int x;
	printf("What is x? \n");
	scanf("%d", &x);
	printf("recursive: T=%d  triangle=%d \n", x, t_rec(x));
	printf("iterative: T=%d  triangle=%d \n", x, t_itr(x));
}

int t_itr(int n){
	int tri = 0;
	for (int inc=1; inc<=n; inc++){
		tri+=inc;
	}
	return tri;
}

int t_rec(int n){
	if (n==0){
		return 0;
	}

	else {
		return n + t_rec(n-1);
	}
}