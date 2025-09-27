#include <iostream>
using namespace std;

void printMat(int A[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void diagStore(int A[4][4], int B[]) {
    for(int i=0;i<4;i++) {
        B[i]=A[i][i];
    }
}
void diagLoad(int B[], int C[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            C[i][j]=0;
        }
    }
    for(int i=0;i<4;i++) {
        C[i][i]=B[i];
    }
}

int triStore(int A[4][4], int B[]) {
    int k=0;
    for(int i=0;i<4;i++) {
        B[k]=A[i][i];
        k++;
    }
    for(int i=0;i<3;i++) {
        B[k]=A[i][i+1];
        k++;
    }
    for(int i=1;i<4;i++) {
        B[k]=A[i][i-1];
        k++;
    }
    return k;
}
void triLoad(int B[], int C[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            C[i][j]=0;
        }
    }
    int k=0;
    for(int i=0;i<4;i++) {
        C[i][i]=B[k];
        k++;
    }
    for(int i=0;i<3;i++) {
        C[i][i+1]=B[k];
        k++;
    }
    for(int i=1;i<4;i++) {
        C[i][i-1]=B[k];
        k++;
    }
}

int lowerStore(int A[4][4], int B[]) {
    int k=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<=i;j++) {
            B[k]=A[i][j];
            k++;
        }
    }
    return k;
}
void lowerLoad(int B[], int C[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            C[i][j]=0;
        }
    }
    int k=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<=i;j++) {
            C[i][j]=B[k];
            k++;
        }
    }
}

int upperStore(int A[4][4], int B[]) {
    int k=0;
    for(int i=0;i<4;i++) {
        for(int j=i;j<4;j++) {
            B[k]=A[i][j];
            k++;
        }
    }
    return k;
}
void upperLoad(int B[], int C[4][4]) {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            C[i][j]=0;
        }
    }
    int k=0;
    for(int i=0;i<4;i++) {
        for(int j=i;j<4;j++) {
            C[i][j]=B[k];
            k++;
        }
    }
}

int symStore(int A[4][4], int B[]) {
    int k=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<=i;j++) {
            B[k]=A[i][j];
            k++;
        }
    }
    return k;
}
void symLoad(int B[], int C[4][4]) {
    int k=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<=i;j++) {
            C[i][j]=B[k];
            C[j][i]=B[k];
            k++;
        }
    }
}

int main() {
    int B[100], R[4][4];

    int Diag[4][4] = {
        {1,0,0,0},
        {0,6,0,0},
        {0,0,11,0},
        {0,0,0,16}
    };

    int Tri[4][4] = {
        {1,2,0,0},
        {3,4,5,0},
        {0,6,7,8},
        {0,0,9,10}
    };

    int Lower[4][4] = {
        {1,0,0,0},
        {5,6,0,0},
        {9,10,11,0},
        {13,14,15,16}
    };

    int Upper[4][4] = {
        {1,2,3,4},
        {0,6,7,8},
        {0,0,11,12},
        {0,0,0,16}
    };

    int Sym[4][4] = {
        {1,5,9,13},
        {5,6,10,14},
        {9,10,11,15},
        {13,14,15,16}
    };

    cout<<"Diagonal Matrix:"<<endl;
    printMat(Diag);
    diagStore(Diag,B);
    cout<<"Stored: ";
    for(int i=0;i<4;i++) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    diagLoad(B,R);
    cout<<"Back:"<<endl;
    printMat(R);
    cout<<endl;

    cout<<"Tri-diagonal Matrix:"<<endl;
    printMat(Tri);
    int t=triStore(Tri,B);
    cout<<"Stored: ";
    for(int i=0;i<t;i++) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    triLoad(B,R);
    cout<<"Back:"<<endl;
    printMat(R);
    cout<<endl;

    cout<<"Lower Triangular Matrix:"<<endl;
    printMat(Lower);
    int l=lowerStore(Lower,B);
    cout<<"Stored: ";
    for(int i=0;i<l;i++) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    lowerLoad(B,R);
    cout<<"Back:"<<endl;
    printMat(R);
    cout<<endl;

    cout<<"Upper Triangular Matrix:"<<endl;
    printMat(Upper);
    int u=upperStore(Upper,B);
    cout<<"Stored: ";
    for(int i=0;i<u;i++) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    upperLoad(B,R);
    cout<<"Back:"<<endl;
    printMat(R);
    cout<<endl;

    cout<<"Symmetric Matrix:"<<endl;
    printMat(Sym);
    int s=symStore(Sym,B);
    cout<<"Stored: ";
    for(int i=0;i<s;i++) {
        cout<<B[i]<<" ";
    }
    cout<<endl;
    symLoad(B,R);
    cout<<"Back:"<<endl;
    printMat(R);

    return 0;
}
