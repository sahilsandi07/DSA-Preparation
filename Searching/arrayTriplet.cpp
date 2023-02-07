bool isPair(int a[], int n, int x, int si){
    int i=si,j=n-1;
    while (i<j){
        if (a[i]+a[j]==x){
            return true;
        }

        else if (a[i]+a[j]<x){
            i++;
        }

        else{
            j--;
        }
    }
    return false;
}

bool isTriplet(int a[], int n,  int x){
    for(int k=0, k<n-2, k++){
        if (isPair(a,n,x-a[k],k+1)){
            return true;
        }
        return false;
    }
}