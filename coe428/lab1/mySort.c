void mySort(int d[], unsigned int n)
{
int i, j,temp_var;
	for( i = 1; i < n; i++){
		temp_var = d[i];
		j = i -1;
		 while( j >= 0 && d[j] > temp_var){
				d[j +1] = d[j] ;
				j = j - 1;	}
		d[j + 1] = temp_var;
    }	
}
