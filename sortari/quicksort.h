template<class T2>
void quicksort(ResizableArray <T2> vector, int pinitial, int pfinal)
{
    int m = (pinitial+pfinal) >> 1;
    int i = pinitial;
    int j = pfinal;
    T2 pivot = vector[m];

    while(i<=j)
    {
        while(vector[i]<pivot)
        i++;
        while(pivot<vector[j])
        j--;

        if(i<=j)
        {
            T2 temp = vector[i];
    		vector[i] = vector[j];
    		vector[j] = temp;
            i++;
            j--;
        }
       }
       if(pinitial<j)
       {
           quicksort(vector, pinitial, j);
       }
       if(i<pfinal)
       {
            quicksort(vector,i,pfinal);
       }
}






