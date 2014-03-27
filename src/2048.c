#include "2048.h"

int GetRandomNumberWeNeed(int n, int m)
{
	int random_number = 0;
	int got_what_we_need = 1;
	// init random numbers generation seed
	srand(time(NULL));

	for(got_what_we_need = 1; got_what_we_need; got_what_we_need = 0 ){
		random_number = rand() % GAMESIZE;
		if(Tiles[random_number] == 0){
			got_what_we_need = 1;
		}
	}
	return random_number;
}
		
void InitTiles(void)
{
	int i = 0;
	for(i = 0; i < GAMESIZE; ++i){
		Tiles[i] = 0;
	}
}

void ShiftRight(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// most eligible space
	int mes = 0;
	
	for(i = 0; i < D; ++i){
		mes = 4*i + D-1;
		for(j = mes; j > 4*i; --j){
			if(Tiles[j] != 0) continue;

			for(k = j-1; k >= 4*i; --k){
				if(Tiles[k] != 0) break;
			}
			if(k >= 4*i && Tiles[k] != 0){ // put k >= 0 and boom, bad logic
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}

void ShiftLeft(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// most eligible space
	int mes = 0;
	
	for(i = 0; i < D; ++i){
		mes = 4*i + 0;
		for(j = mes; j < 4*i + D-1; ++j){
			if(Tiles[j] != 0) continue;

			for(k = j+1; k <= 4*i+D-1; ++k){
				if(Tiles[k] != 0) break;
			}
			if(k <= 4*i+D-1 && Tiles[k] != 0){ // put k >= 0 and boom, bad logic
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}

void ShiftDown(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	// most eligible space
	int mes = 0;
	
	for(i = 0; i < D; ++i){
		mes = i + D*(D-1);
		for(j = mes; j >  i; j-=4){
			if(Tiles[j] != 0) continue;

			for(k = j-4; k >= i; k-=4){
				if(Tiles[k] != 0) break;
			}
			if(k >= i && Tiles[k] != 0){ // put k >= 0 and boom, bad logic
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}

void ShiftUp(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	
	for(i = 0; i < D; ++i){
		for(j = i; j < D*(D-1) + i; j += 4){
			if(Tiles[j] != 0) continue;
			for(k = j+4; k <= D*(D-1)+i; k += 4){
				if(Tiles[k] != 0) break;
			}
			if(k <= D*(D-1)+i && Tiles[k]!= 0){
				Tiles[j] = Tiles[k];
				Tiles[k] = 0;
			}
		}
	}
}

void MergeRight(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int sum = 0;
printf("\nMR\n");
}

void MergeLeft(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int sum = 0;
printf("\nML\n");
	
}

void MergeDown(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int sum = 0;
printf("\nMD\n");	
	
}

void MergeUp(void)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int sum = 0;
printf("\nMU\n");
	
	
}

void PrintTiles()
{
	int i = D, j = D;
	for(i = 0; i < D; ++i){
		for(j = 0; j < D; ++j){
			printf("%6d", Tiles[D*i+j]);
		}
		printf("\n\n");
	}
}

int main()
{
	int i = 0;
	for(i=0; i<GAMESIZE; ++i){
		Tiles[i] = 0;
	}
	Tiles[1] = 4;
	Tiles[3] = 4;
	Tiles[6] = 8;
	Tiles[9] = 8;
	Tiles[12] = 16;

	PrintTiles();
	ShiftRight();
	PrintTiles();
	ShiftLeft();
	PrintTiles();
	ShiftUp();
	PrintTiles();
	ShiftDown();
	PrintTiles();
	ShiftUp();
	PrintTiles();
	MergeLeft();
	PrintTiles();
	ShiftLeft();
	PrintTiles();
	MergeDown();
	PrintTiles();
	ShiftUp();
	PrintTiles();
	MergeUp();
	PrintTiles();
	MergeDown();
	PrintTiles();
}
