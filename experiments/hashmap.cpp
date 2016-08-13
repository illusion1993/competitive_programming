#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int main(){

    int myNum = 237;

    if (myNum/10 == 0){
		cout << "YES" << endl;
	}

	unordered_map<int, int> myVector;

	int numLength = (int)(log10(myNum)+1);

	cout << "ready to loop from 1 to " << numLength-1 << endl << endl;

	for (int i = 1; i < numLength; ++i){

        cout <<"    loop " << i << endl;

		int newNum = myNum;

		cout <<"    newNum = nyNum" << endl;

		int newNumLength = (int)(log10(newNum)+1);

		cout <<"    ready to loop from " << newNumLength + 1 - i << " to 1" << endl << endl;

		for (int j = newNumLength+1-i; j >= 1; --j){

        cout <<"        loop " << j << endl;

			int numPush = newNum%((int)pow(10,i));

        cout <<"        numPush = " << numPush << endl;

			if ((int)(log10(numPush)+1) > 1){

				int x = numPush%10;
				int nL = (int)(log10(numPush)+1);
        cout <<"        Since, digits in numPush are > 1, x = " << x << ", nL = " << nL << endl;

        cout <<"        ready to loop from 1 to " << nL-1 << endl << endl;

				for (int k =1; k < nL; ++k){
        cout <<"            loop " << k << endl;
					if (x == 1 || x == 0){
        cout <<"            Since x == 1 or 0, " << endl;
						cout << "No" << endl;
					}
					numPush = numPush/10;
					x = x*(numPush%10);
        cout <<"            numPush = " << numPush << ", x = " << x << endl;
				}
        cout <<"        numPush = " << numPush << endl;
				numPush = x;
			}

			if (numPush == 0 || numPush == 1){
        cout <<"        Since numPush == 1 or 0, " << endl;
				cout << "No";
			}
			myVector[numPush] = 1;
			newNum = newNum/10;
        cout <<"myVector[numPush] = 1, newNum = newNum/10" << endl;
		}
	}

	int mySize = 0;
	for (int i = 2; i <= numLength; ++i){
		mySize = mySize + i;
	}


	if (mySize > myVector.size()){
		return false;
	}
	return true;


    return 0;

}
