#include <iostream>
#include <vector>
using namespace std;

int main()
{
while(1){
    int nprocess,mresources,i,j,k,input;
    cout<<"Enter the no. of processes"<<endl;
    cin>>nprocess;
    cout<<"Enter the no. of resources "<<endl;
    cin>>mresources;
    int** allocation_mat=new int*[nprocess];
    for(int i=0; i<nprocess; i++){
        allocation_mat[i] = new int[mresources];
    }
    int** maximum_mat=new int*[nprocess];
    for(int i=0; i<nprocess; i++){
        maximum_mat[i] = new int[mresources];
    }
    int *available_mat=new int[mresources];
    int** need_mat=new int*[nprocess];
    for(int i=0; i<nprocess; i++){
        need_mat[i] = new int[mresources];
    }
    for (i=0;i<nprocess;i++)
    {
        for (j=0;j<mresources;j++)
            need_mat[i][j]=0;
    }
    int *finish_mat=new int[nprocess], *output=new int[nprocess];
    int index = 0;
    cout<<"Allocation Matrix:"<<endl;
    for (i = 0; i < nprocess; i++) {
        for (j = 0; j < mresources; j++){
            cin>>allocation_mat[i][j];
        }
        }
    cout<<"Maximum Matrix:"<<endl;
    for (i = 0; i < nprocess; i++) {
        for (j = 0; j < mresources; j++){
            cin>>maximum_mat[i][j];
        }
        }
    cout<<"Available Resources Matrix:"<<endl;
    for (i = 0; i < mresources; i++) {
        cin>>available_mat[i];
    }

    int *work_mat=new int[mresources];
    for (i = 0; i < mresources; i++) {
        work_mat[i]=available_mat[i];
    }
    for (i = 0; i < nprocess; i++) {
        for (j = 0; j < mresources; j++)
            need_mat[i][j] = maximum_mat[i][j] - allocation_mat[i][j];
    }
    cout<<"So The Need Matrix is:"<<endl;
    cout<<"  ";
    for (int j=0;j<mresources;j++)
    {
        cout<<"R"<<j+1<<" ";
    }
    cout<<endl;
    for (i = 0; i < nprocess; i++) {
        cout<<"P"<<i<<" ";
        for (j = 0; j < mresources; j++)
        {
            cout<< need_mat[i][j]<<"  ";
        }

        cout<<endl;
    }
    cout<<"For safety algorithm enter 1 and for resource request algorithm enter 2"<<endl;
    cin>>input;
    if(input==1){

    for (k = 0; k < nprocess; k++) {
        finish_mat[k] = 0;
    }

    for (k = 0; k < nprocess; k++) {
        for (i = 0; i < nprocess; i++) {
            if (finish_mat[i] == 0) {

                int flag = 0;
                for (j = 0; j < mresources; j++) {
                    if (need_mat[i][j] > available_mat[j]){
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    output[index++] = i;
                    for (int y = 0; y < mresources; y++)
                        available_mat[y] += allocation_mat[i][y];
                    finish_mat[i] = 1;
                }
            }
        }
    }
    if(index==nprocess)
    {
        cout << "YES,There is safe sequence:" << endl;
        for (i = 0; i < nprocess - 1; i++)
         cout<< " P" << output[i] << "->";
        cout << " P" << output[nprocess - 1]<<endl;
    }
    else{
    cout<<"NO,There's no safe sequence"<<endl;
    continue ;
    }
    }
    else if (input==2){
    index=0;
	int *request_mat=new int[mresources];
	int process_no;
	cout<<"Enter The no. of requested process"<<endl;
	cin>>process_no;
	cout<< "Enter The request"<<endl;
	for(i=0;i<mresources;i++){
		cin>> request_mat[i];
	}
    int Flag1=0,Flag2=0;
	for(i=0;i<mresources;i++){
		if(request_mat[i] > need_mat[process_no][i]){
			cout<< "Error because request matrix > need matrix"<<endl;
			Flag1=1;
            break;
			}
	}

	for(i=0;i<mresources;i++){
		if(request_mat[i] > work_mat[i]){
			cout<<"Error because request matrix > work matrix"<<endl;
			Flag2=1;
            break;
			}

    }
    if(Flag1==0 && Flag2==0){
            for(i=0;i<mresources;i++){
                work_mat[i]=work_mat[i]-request_mat[i];
                allocation_mat[process_no][i]=allocation_mat[process_no][i]+request_mat[i];
                need_mat[process_no][i]=need_mat[process_no][i]-request_mat[i];
	        }
	        for (k = 0; k < nprocess; k++) {
                    finish_mat[k] = 0;
            }

    for (i = 0; i < nprocess; i++) {
        for (j = 0; j < mresources; j++)
            need_mat[i][j] = maximum_mat[i][j] - allocation_mat[i][j];
    }

    cout<<"So Need after request is:"<<endl;
    cout<<"  ";
    for (int j=0;j<mresources;j++)
    {
        cout<<"R"<<j+1<<" ";
    }
    cout<<endl;
    for (i = 0; i < nprocess; i++) {
        cout<<"P"<<i<<" ";
        for (j = 0; j < mresources; j++)
        {
            cout<< need_mat[i][j]<<"  ";
        }

        cout<<endl;
    }

    int y = 0;
    for (k = 0; k < nprocess; k++) {
        for (i = 0; i < nprocess; i++) {
            if (finish_mat[i] == 0) {

                int flag = 0;
                for (j = 0; j < mresources; j++) {
                    if (need_mat[i][j] > work_mat[j]){
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    output[index++] = i;
                    for (y = 0; y < mresources; y++)
                        work_mat[y] += allocation_mat[i][y];
                    finish_mat[i] = 1;
                }
            }
        }
    }
    if(index==nprocess){
    cout << "Request can be granted , Safe sequence is:" << endl;
    cout<<"<"<<"P"<<process_no<<"req"<<",";
    for (i = 0; i < nprocess - 1; i++)
          cout<< "P" << output[i] << ",";
    cout << "P" << output[nprocess- 1]<<">"<<endl;
    }
    else{
            cout<<"There's no safe sequence"<<endl;
            continue ;
    }
    }
    }
    }
    return (0);
}
