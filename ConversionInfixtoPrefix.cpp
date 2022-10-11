/*
Nama    : Virnika Shefira Gina Morissa
NIM     : A11.2021.13841
Kelompok: 4317
Matkul  : Struktur Data
*/

#include <iostream>
#include <string>
#define MAX 20
using namespace std;

void push(char);
char pop();
string in2postfix(string);
int priority(char);
int stk [20];
int top = -1;
bool isFull();
bool isEmpty();
string in2prefix(string);

int main()
{
    string infix,postfix,prefix,reverseString;

    cout << "Masukkan infix : ";
    cin>>infix;

    postfix = in2postfix(infix);
    cout<<endl;

    prefix = in2prefix(infix);
    cout << endl;

    return 0;
}

bool isFull(){
    if(top == MAX - 1 ){
        return true;
    }else {
        return false;
    }
}

bool isEmpty(){
    if(top == -1 ){
        return true;
    }else {
        return false;
    }
}

// prosedur memasukkan operator ke stack
void push(char oper){
    if(isFull()){
        cout<<"stack penuh";
    }
    else{
        top++;
        stk[top]=oper;
    }
}

// fungsi untuk menghapus data dari stack
char pop(){
    char ch;
    if(isEmpty())
    {
        cout<<"stack kosong!!!!";
    }
    else
    {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}

/*
* fungsi untuk mengonversi infix ke postfix, asumsinya semua ekspresi sudah valid
*/
string in2postfix(string infix){
    int i=0;
    string pst = "";

    // looping selama urutan terakhir string tidak kosong
    while(infix[i]!='\0'){
        // jika ketemu alfabet, maka masukkan ke variabel
        if(infix[i]>='a' && infix[i]<='z'){
            pst.insert(pst.end(),infix[i]);
            i++;
        }
        // jika ketemu kurung buka, push ke stack
        else if(infix[i]=='(' || infix[i]=='{' || infix[i]=='['){
            push(infix[i]);
            i++;
        }
        //jika ketemu kurung tutup, pop dari stack
        else if(infix[i]==')' || infix[i]=='}' || infix[i]==']')
        {
            if(infix[i] == ')')
            {
                while(stk[top]!= '('){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == ']')
            {
                while(stk[top]!= '['){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i] == '}')
            {
                while(stk[top]!= '{'){
                    pst.insert(pst.end(),pop());
                }
                pop();
                i++;
            }
        }

        //kalo ga ada kurung tutup, berarti cuma ada operator aja, lakukan blok berikut
        else{
            if(isEmpty()){
                push(infix[i]);
                i++;
            }
            // jika prioritas operator kurang dari atau sama dengan operator yang ada di top of stack
            // pop operator yang di stack, kemudian masukkan ke pst
            else if(priority(infix[i]) <= priority(stk[top])){
                pst.insert(pst.end(),pop());

                // jika prioritas operator sama dengan operator di stack, pop
                while(priority(stk[top]) == priority(infix[i])){
                    pst.insert(pst.end(),pop());
                    if(top<0){
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }

            // jika prioritas operator lebih tinggi, push operator ke stack
            else if(priority(infix[i]) > priority(stk[top])){
                push(infix[i]);
                i++;
            }
        }
    }

    // pada akhirnya, remove semua operator dari stack
    while(top != -1){
        pst.insert(pst.end(),pop());
    }
    cout<<"Hasil konversi ke postfix: "<<pst;
    return pst;
}

// fungsi untuk mencari prioritas operator
int priority(char alpha){
    if(alpha == '+' || alpha == '-'){
        return 1;
    }

    if(alpha == '*' || alpha == '/'){
        return 2;
    }

    if(alpha == '$'){
        return 3;
    }
    return 0;
}


//reverse
void dibalik(string &str)
{
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //menukar nilai
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
  }

}

/*
* fungsi untuk mengonversi infix ke prefix, asumsinya semua ekspresi sudah valid
*/
//fungsi untuk mengonversi infix ke prefix
string in2prefix(string infix)
{
    int i=0;
    dibalik(infix);
    string pre = "";

    // looping selama urutan terakhir string tidak kosong
    while(infix[i]!='\0')
    {
        // jika ketemu alfabet, maka masukkan ke variabel
        if(infix[i]>='a' && infix[i]<='z')
        {
            pre.insert(pre.begin(),infix[i]);
            i++;
        }

        // jika ketemu kurung tutup, push ke stack
        else if(infix[i]==')' || infix[i]=='}'  || infix[i]==']')
        {
            push(infix[i]);
            i++;
        }

        //jika ketemu kurung buka, pop dari stack
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='[')
        {
            if(infix[i]=='(')
            {
                while(stk[top]!=')')
                {
                    pre.insert(pre.begin(),pop());
                }
                pop();
                i++;
                  }

            if(infix[i]=='[')
            {
                while(stk[top]!=']')
                {
                    pre.insert(pre.begin(),pop());
                }
                pop();
                i++;
            }

            if(infix[i]=='{')
            {
                while(stk[top]!='}')
                {
                    pre.insert(pre.begin(),pop());
                }
                pop();
                i++;
            }
        }
        //kalo ga ada kurung tutup, berarti cuma ada operator aja, lakukan blok berikut
        else
        {
            // jika stack kosong, push ke stack
            if(isEmpty())
            {
                push(infix[i]);
                i++;
            }

            // jika prioritas operator kurang dari atau sama dengan operator yang ada di top of stack
            // pop operator yang di stack, kemudian masukkan ke pre
            else if( priority(infix[i]) <= priority(stk[top]))
            {
                pre.insert(pre.begin(),pop());

                // jika prioritas operator sama dengan operator di stack, pop
                while(priority(stk[top]) == priority(infix[i]))
                {
                    pre.insert(pre.begin(),pop());
                    if(top < 0)
                    {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }

            // jika prioritas operator lebih tinggi, push operator ke stack
            else if(priority(infix[i]) > priority(stk[top]))
            {
                push(infix[i]);
                i++;
            }
        }
    }

    // pada akhirnya, remove semua operator dari stack
    while(top!=-1)
    {
        pre.insert(pre.begin(),pop());
    }
    cout << "Hasil konversi ke prefix : " << pre;
    return pre;
}
