#include<iostream>
#include<cctype>
using namespace std;
int checkthiscase(int skl[][5] , int reqskl[][5] , int m , int n , int* numofroles , bool canapply[][5] , bool hasapplied[][100] , bool* mentor){
    int completedprojects = 0;

    for(int i=0; i<m; i++){

        for(int j=0; j<n; j++){

            for(int k=0; k<5; k++){
                if(skl[j][k] >= reqskl[i][k] && reqskl[i][k] > 0 && canapply[i][k]){
                    int s=0;
                    for(int b=0; b<m; b++){
                        if(hasapplied[j][b]) s++;
                    }
                    if(s==0){
                    hasapplied[j][i] = true;
                    canapply[i][k] = false;
                    numofroles[i]--;
                    }
                }
            }

            for(int k=0; k<5; k++){
                if(skl[j][k] == reqskl[i][k] - 1 && canapply[i][k]){
                    int s=0;
                    for(int b=0; b<m; b++){
                        if(hasapplied[j][b]) s++;
                    }
                if(s==0){
                for(int a=0; a<n; a++){    
                    if(hasapplied[a][i] && skl[a][k] > reqskl[i][k] && !mentor[a]){
                    hasapplied[j][i] = true;
                    canapply[i][k] = false;
                    numofroles[i]--;
                    mentor[a] = true;
                    break;
                    }  
                }
                }
            }
        }
    }
    if(numofroles[i] == 0) completedprojects++;
    }
    return completedprojects;
}
int main(){
    int n;
    cin>>n;    //number of participants
    int rollno[n],skl[n][5];
    for(int i=0; i<n; i++){
        int s=0;
        cin>>rollno[i];
    while(s<5){
        cin>>skl[i][s++];
    }
    }
    int m;    //number of projects
    cin>>m;
    cin.ignore();
    char projectname[m][50];
    int reqskl[m][5];
    for(int i=0; i<m; i++){
        cin.getline(projectname[i],50);
        int index,j=0;
        while(projectname[i][j]){
            if(isdigit(projectname[i][j])){    //assuming the max value a required 
                index = j;                     //skill level can reach is 9 :)
                break;
            }
        j++;    
        }
        for(int k=0; k<5; k++){
            reqskl[i][k] = projectname[i][index] - 48;
            index = index+2;
        }
    }

    int t[n]={0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<5; k++){
            if(skl[i][k] >= reqskl[j][k] && reqskl[j][k] > 0){
                t[i]++;
            }
            }
        }
    }

    int jt[n][m*5],kt[n][m*5];
    for(int i=0; i<n; i++){
        if(t[i] >= 2){
        int jj=0;
            for(int j=0; j<m; j++){
            for(int k=0; k<5; k++){
            if(skl[i][k] >= reqskl[j][k] && reqskl[j][k] > 0){
                jt[i][jj] = j; kt[i][jj] = k; 
                jj++;
            }   
        }
        }
}
}

    int numofroles[m];     //total number of roles in ith project
    for(int i=0; i<m; i++)
    numofroles[i] = 0;

    for(int i=0; i<m; i++){
    for(int j=0; j<5; j++){
        if(reqskl[i][j] != 0)
        numofroles[i]++;
    }
    }
    
    bool canapply[m][5];      //can apply for the role or not
    for(int i=0; i<m; i++){
        for(int j=0; j<5; j++){
            canapply[i][j] = true;
        }
    }
    
    bool hasapplied[n][100];       //have the person applied(and got) for any role or not
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            hasapplied[i][j] = false;
        }
    }

    bool mentor[n];       //has the person become a mentor or not
    for(int i=0; i<n; i++)
    mentor[i] = false;

    int maximize=0;

for(int i=0; i<n; i++){
    if(t[i] >= 2){
    for(int j=0; j<t[i]; j++){

    hasapplied[i][jt[i][j]] = true;
    canapply[jt[i][j]][kt[i][j]] = false;
    numofroles[jt[i][j]]--;

    if(checkthiscase(skl , reqskl , m , n , numofroles , canapply , hasapplied , mentor) > maximize){
    maximize = checkthiscase(skl , reqskl , m , n , numofroles , canapply , hasapplied , mentor);
    }
    }
}
else if(checkthiscase(skl , reqskl , m , n , numofroles , canapply , hasapplied , mentor) > maximize)
maximize = checkthiscase(skl , reqskl , m , n , numofroles , canapply , hasapplied , mentor);
}
cout<<maximize;
}
