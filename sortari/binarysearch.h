template<class T1, class T2>
int binarysearch(T1 <T2> vector, int pinitial, int pfinal, T2 cautat)
{
	int medie;
	medie=(pinitial+pfinal) >> 1; // >> 1 = impartire la 2
	if (vector[medie]==cautat) return medie;
	if (vector[medie]<cautat)
		{
			return binarysearch(vector, medie+1, pfinal,cautat);
		}
	else
	{
		return binarysearch(vector, pinitial, medie-1,cautat);
	}

}
