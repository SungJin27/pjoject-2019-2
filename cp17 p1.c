#include<stdio.h>
union rope {
	unsigned long long ll[1];
	unsigned int i[2];
	unsigned short s[4];
	unsigned char c[8];
};
typedef enum {
	ROPE_C = 1, ROPE_S = 2, ROPE_I = 4, ROPE_LL = 8
}rope_type;
void print_rope(union rope r, rope_type t, int idx) {
	switch (t) {
	case ROPE_C:
		printf("=%02X=", r.c[idx]);
		break;
	case ROPE_S:
		printf("=%04X=", r.s[idx]);
		break;
	case ROPE_I:
		printf("=%08X=", r.i[idx]);
		break;
	case ROPE_LL:
		printf("=%016llX=", r.ll[idx]);
		break;
	default:
		printf("\n");
	}
}
int main()
{
	union rope r = { 0x0123456789ABCDEF };
	int i = 0, j;
	rope_type t = 0;
	int idx = 0;
	int command = -1;
	while (command != 0) {
		i++;
		switch (i) {
		case 1:
			for (j = 7; j >= 0; j--) {
				print_rope(r, 1, j);
			}
			print_rope(r, 0, 0);
			break;

		case 2:
			print_rope(r, 2, 3);
			for (j = 5; j >= 0; j--) {
				print_rope(r, 1, j);
			}
			print_rope(r, 0, 0);
			break;

		case 3:
			for (j = 3; j >= 2; j--) {
				print_rope(r, 2, j);
			 }
			for (j = 3; j >= 0; j--) {
				print_rope(r, 1, j);
			}
			print_rope(r, 0, 0);
			break;
		
		case 4:
			print_rope(r, 4, 1);
			for (j = 3; j >= 0; j--) {
				print_rope(r, 1, j);
			}
			print_rope(r, 0, 0);
			break;
		
		case 5:
			print_rope(r, 4, 1);
			print_rope(r, 2, 1);
			for (j = 1; j >= 0; j--) {
				print_rope(r, 1, j);
			}
			print_rope(r, 0, 0);
			break;

		case 6:
			print_rope(r, 4, 1);
			for (j = 1; j >= 0; j--) {
				print_rope(r, 2, j);
			}
			print_rope(r, 0, 0);
			break;

		case 7:
			for (j = 1; j >= 0; j--) {
				print_rope(r, 4, j);
			}
			print_rope(r, 0, 0);
			break;

		default:
			print_rope(r, 8, 0);
			print_rope(r, 0, 0);
		}
		
		scanf("%d", &command);
	}
	
	return 0;
}
