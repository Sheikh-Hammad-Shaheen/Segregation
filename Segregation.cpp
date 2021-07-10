#include<iostream>
#include<vector>
using namespace std;


void partition(vector<int>& Vs)   //  0 at left and 1 at right   1
{
	int si = 0;
	int ei = Vs.size() - 1;
	do {
		while (si < ei && Vs[si] == 0)
			si++;

		while (ei > si && Vs[ei] == 1)
			ei--;

		if (si < ei)
			swap(Vs[si], Vs[ei]);
	}
	while (si < ei);
}

void partitionEo(vector<int>& Vs)              // even at left and odd at right 2
{
	int si = 0;
	int ei = Vs.size() - 1;
	do {
		while (si < ei && Vs[si]%2 == 0)
			si++;

		while (ei > si && Vs[ei]%2 != 0)
			ei--;

		if (si < ei)
			swap(Vs[si], Vs[ei]);
	} while (si < ei);
}


void partitionMain(vector<int>& Vs, int T)     // all less than T at ;eft and greater then T at right  3
{
	int si = 0;
	int ei = Vs.size() - 1;
	do {
		while (si < ei && Vs[si]<T)
			si++;

		while (ei > si && Vs[ei]>T)
			ei--;

		if (si < ei)
		{
			swap(Vs[si], Vs[ei]);
			if (Vs[si] == Vs[ei])
				ei--;
		}
	} while (si < ei);
}




ostream& operator<<(ostream&, vector<int> &v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return cout;
}

void partitionZOT(vector<int>& Vs)      // zero at left one at middle and two at right 
{
	int si = 0;
	int ei = Vs.size()- 1;
	int mid = 0;

	do {
		while (mid <= ei && Vs[mid] == 0)
			swap(Vs[si++], Vs[mid++]);
			
		while(mid<= ei &&Vs[mid]==1)
			mid++;
		while(mid<= ei &&Vs[mid]==2)
			swap(Vs[mid], Vs[ei--]);
	} while (mid <= ei);
}


void partitionQ5(vector<int>& Vs,int T)   //  all less than t at left and T at middle and greater T at right 
{
	auto si = Vs.begin();
	auto ei = Vs.end() - 1;
	auto mid = Vs.begin();

	do {
		while (mid <= ei && *mid < T)
		{
			iter_swap(si, mid);
			si++; mid++;
		}
		while (mid <= ei && *mid == T)
			mid++;

		while (mid <= ei && *mid > T)
		{
			iter_swap(mid, ei);
			ei--;

		}
	} while (mid <= ei);

	//without iter_swap

	/*do {
		while (mid <= ei && Vs[mid] <T)
			swap(Vs[si++], Vs[mid++]);

		while (mid <= ei && Vs[mid] == T)
			mid++;
		while (mid <= ei && Vs[mid] >T)
			swap(Vs[mid], Vs[ei--]);
	} while (mid <= ei);*/

}
int main()
{

	cout << "Q1 ::  ALL ZERO AT LEFT ALL ONES AT RIGHT ";
	cout << endl;
	vector <int> Vq1({ 0 ,1 ,1 ,0 ,1 ,1 ,0 ,1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0});
	cout << endl << "BEFORE SEGREGATION : ";
	cout << Vq1 << endl;
	partition(Vq1);
	cout << "AFTER SEGREGATION : ";
	cout << Vq1;
	
	cout << endl << endl;

	cout << "Q2 ::  ALL EVEN AT LEFT ALL ODDS AT RIGHT ";
	cout << endl;
	vector<int> vQ2({ 9,8,6,5,4,10,12,18,5,-15,6,8,9,10 });
	cout << endl << "BEFORE SEGREGATION : ";
	cout << vQ2;
	cout << endl;
	partitionEo(vQ2);
	cout << "AFTER SEGREGATION : ";
	cout << vQ2;
	
	cout << endl << endl;


	cout << "Q3 ::  VALUES LESS THAN T AT LEFT AND GREATER THAN T AT RIGHT ";
	cout << endl;
	vector<int> VQ3({ 9,8,6,5,4,10,12,18,5,- 15,6,8,9,10 });
	cout << endl << "BEFORE SEGREGATION : ";
	cout << VQ3;
	cout << endl;
	partitionMain(VQ3, 7);
	cout << "AFTER SEGREGATION : ";
	cout << VQ3;
	
	cout << endl << endl;


	cout << "Q4 ::  ALL ZERO AT LEFT ALL ONE IN MIDDLE AND ODDS AT RIGHT ";

	cout << endl;
	vector<int> VQ4({ 0,1,1,2,0 ,1 ,1 ,2 , 0, 1, 1, 0 ,0 ,1 ,0 , 2 , 0 ,0 ,1 ,0 });
	cout << endl << "BEFORE SEGREGATION : ";
	cout << VQ4;
	cout << endl;
	partitionZOT(VQ4);
	cout << "AFTER SEGREGATION : ";
	cout << VQ4;

	cout << endl << endl;

	cout << "Q5 ::  VALUES LESS THAN T AT LEFT AND T AT MIDDLE GREATER THAN T AT RIGHT ";

	cout << endl;
	vector<int> Q5({ 9 , 8 , 6 , 7, 5 , 4 , 10  ,12  ,18  ,5 ,-15 , 7  ,6  ,8  ,9  ,7 ,10 });
	cout << endl << "BEFORE SEGREGATION : ";
	cout << Q5;
	cout << endl;
	partitionQ5(Q5, 7);
	cout << "AFTER SEGREGATION : ";
	cout << Q5;
	
	
	cout << endl << endl;
	
}