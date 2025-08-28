#include <stdio.h>

int main(int argc, char* argv[]) {
	int total = 0;
	int plus, minus = 0;
	scanf("%d %d %d", &plus, &minus, &total);
	
	int delay = (total - minus) / (plus - minus);
	
	if((total - minus) % (plus - minus) != 0) {
		delay++;
	}
	
	printf("%d", delay);
	
	return 0;
}